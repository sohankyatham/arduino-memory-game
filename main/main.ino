const byte LED_PINS[] = {7, 8, 9, 10};
const byte BUZZER_PIN = 12;
const byte BUTTON_PINS[] = {2, 3, 4, 5};

// Note definitions for buzzer sounds
#define NOTE_C4 262
#define NOTE_E4 330
#define NOTE_G4 392
#define NOTE_C5 523

const int NOTE_VALUES[] = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5};

const byte MAX_SEQUENCE_LENGTH = 100; // Maximum allowed length of the game

byte sequence[MAX_SEQUENCE_LENGTH]; // Array that stores pattern
byte currentLevel = 0; 


/**
 * Set up function to initialize hardware 
 * 
 * LED Pins are outputs
 * Piezo buzzer is output
 * Button pins are inputs
 */
void setup() {
    Serial.begin(9600); // Initialize Serial communication
    pinMode(BUZZER_PIN, OUTPUT);
    for (byte i=0; i<4; i++) { 
        pinMode(LED_PINS[i], OUTPUT);
        pinMode(BUTTON_PINS[i], INPUT_PULLUP); // Set button pin as pin & turn on Arduino's inner pull-up resistor
    }
    randomSeed(analogRead(A0)); // Make the random sequence different each time when the Arduino starts
    delay(100);
}


/**
 * Turn on one LED and play its note
 */
void flashButtonSignal(byte index) {
    digitalWrite(LED_PINS[index], HIGH);
    tone(BUZZER_PIN, NOTE_VALUES[index]);
    delay(100);
    digitalWrite(LED_PINS[index], LOW);
    noTone(BUZZER_PIN);
    delay(50);
}


/**
 * Show the current memory pattern on the arduino
 */
void playSequence() {
    for (byte i = 0; i < currentLevel; i++) {
        flashButtonSignal(sequence[i]);
        delay(200);
    }
}


/**
 * Check if the user presses a button and return the button pressed
 */
byte getButtonPress() {
    while (true) {
        for (byte i=0; i<4; i++) {
            if (digitalRead(BUTTON_PINS[i]) == LOW) {
                while (digitalRead(BUTTON_PINS[i]) == LOW) {
                    delay(1);
                }
                return i;
            }
        }
        delay(1);
    }
}


/**
 * Check whether the player pressed the correct button(s) for the round
 */
bool isPlayerCorrect() {
    for (byte i = 0; i < currentLevel; i++) {
        byte expectedButton = sequence[i];
        byte actualButton = getButtonPress();

        // Show what the player is pressing
        flashButtonSignal(actualButton);

        if (expectedButton != actualButton) {
            return false;
        }
    }

    return true;
}


/**
 * Play the game over sound when the player clicks the incorrect button sequence
 */
void playFailSound() {
    delay(200);
    tone(BUZZER_PIN, NOTE_C5);
    delay(250);
    tone(BUZZER_PIN, NOTE_G4);
    delay(250);
    tone(BUZZER_PIN, NOTE_E4);
    delay(250);
    tone(BUZZER_PIN, NOTE_C4);
    delay(250);
    noTone(BUZZER_PIN);
}


/**
 * Play the win sound when the player clicks the correct button(s) for the sequence
 * Move onto the next level
 */
void playWinSound() {
    delay(200);
    tone(BUZZER_PIN, NOTE_C4);
    delay(200);
    tone(BUZZER_PIN, NOTE_E4);
    delay(200);
    tone(BUZZER_PIN, NOTE_G4);
    delay(200);
    tone(BUZZER_PIN, NOTE_C5);
    delay(200);
    noTone(BUZZER_PIN);
}

/**
 * Game over - tells user their score
 */
void gameOver() {
    Serial.println("Your score: ");
    Serial.println(currentLevel);
}


/**
 * Main game loop
 * 
 * 1. Add a new random step to the sequence
 * 2. Show that sequence to the player
 * 3. Wait for the player to repeat the sequence
 * 4. Check if the player is correct
 */
void loop() {
    if (currentLevel < MAX_SEQUENCE_LENGTH) {
        sequence[currentLevel] = random(0, 4);
        currentLevel++;
    }

    playSequence();

    if (isPlayerCorrect()) {
        playWinSound();
    } else {
        playFailSound();
        gameOver();
        currentLevel = 0; // reset game
    }

    delay(800);

    // ------ First Test - blink all 4 LEDs ------
    // for (byte i=0; i<4; i++) {
    //     digitalWrite(LED_PINS[i], HIGH);
    //     delay(300);
    //     digitalWrite(LED_PINS[i], LOW);
    //     delay(150);
    // }

    // ------ Second Test - buttons control LEDs & buzzer plays sound ------
    // for (byte i=0; i<4; i++) {
    //     if (digitalRead(BUTTON_PINS[i]) == LOW) {
    //         // Turn on LEDs & buzzer when buttons are pressed
    //         digitalWrite(LED_PINS[i], HIGH);
    //         tone(BUZZER_PIN, NOTE_VALUES[i]);
    //     } else {
    //         // Turn off LEDs & turn off buzzer
    //         digitalWrite(LED_PINS[i], LOW);
    //         noTone(BUZZER_PIN);
    //     }
    // }
}