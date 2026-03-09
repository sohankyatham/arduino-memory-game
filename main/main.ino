const byte BUTTON_PINS[] = {2, 3, 4, 5};
const byte LED_PINS[] = {7, 8, 9, 10};
const byte BUZZER_PIN = 12;

// LED Pins are outputs
// Piezo buzzer is output
// Button pins are inputs
void setup() {
    // Start USB serial communication so Arduino can send messages to Serial Monitor
    Serial.begin(9600); 

    for (byte i = 0; i < 4; i++) {
        pinMode(LED_PINS[i], OUTPUT);
        pinMode(BUTTON_PINS[i], INPUT_PULLUP);
    }

    pinMode(BUZZER_PIN, OUTPUT);
}

void playSignal() {}
void showPattern() {}
void waitForPlayerPress() {}
bool checkPlayerRound() {}
void playFailSound() {}
void playWinSound() {}

void loop() {
    // first test program - blink all 4 LEDs
    // for (byte i = 0; i < 4; i++) {
    //     digitalWrite(LED_PINS[i], HIGH);
    //     delay(300);
    //     digitalWrite(LED_PINS[i], LOW);
    //     delay(150);
    // }

    // second test - buttons control LEDs
    for (byte i = 0; i < 4; i++) {
        if (digitalRead(BUTTON_PINS[i]) == LOW) {
            digitalWrite(LED_PINS[i], HIGH);
        } else {
            digitalWrite(LED_PINS[i], LOW);
        }
    }
}