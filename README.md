# Arduino Memory Game
- A memory game using the Arduino microcontroller, LEDs, buttons, and a piezo buzzer.
- Players must watch the LED sequence and repeat it by pressing the matching buttons. Each round adds a new step to the sequence.

<img src="assets/UsingTheMemoryGame.jpeg.png" alt="User playing the Arduino memory game" width="300"/>

## Demo Link
https://youtube.com/shorts/1UGmg3GiB4w?feature=share

## Overview
This project is a LED memory game built using an Arduino microcontroller. The program generates a random sequence and plays the sequence using LEDs and tones. The user must memorize and repeat the sequence by pressing the corresponding buttons. If the user enters the correct sequence for the round, then the length of the sequence increases in the next round, making the game more challenging for the user. If the user enters an incorrect sequence, then the game tells the user their score in the Serial output and restarts the game.

This is my first project using an Arduino microcontroller and it allowed me to learn the fundamentals of embedded systems programming, including digital input/output, circuit/code design, and integrating hardware components.

## Hardware Components
- Arduino Microcontroller
- 4 LEDs
- 4 push buttons
- 4 resistors (220Ω)
- Piezo buzzer
- Breadboard
- Jumper wires

### Circuit Diagram
<img src="assets/WireDiagram.png" alt="Wiring diagram for memory game" width="500"/>

## Setup Instructions
1. Follow circuit diagram to set up LEDs, resistors, button, buzzer, and wires 
2. Connect LEDs to pins 7-10.
3. Connect buttons to pins 2-5.
4. Connect buzzer to pin 12
5. Upload Arduino sketch and power board

## How it works - probably go in overview at high level and below more low level 
1. Program generates random sequence of led signals
2. Sequence is then shown with LED lights and sound
3. The player repeats the sequence by clicking corresponding buttons
4. Arduino checks input against correct sequence
5. If correct, then the sequence increases and shown in the next round 
6. If incorrect, then the user's score is displayed in serial output and the game restarts  

### Code Structure
- setup() - initializes hardware (LED pins & buzzer are outputs; button pins are input)
- loop() - main game loop and heart of the program's logic

- Helper methods:
- - flashButtonSignal() - Turn on LED and play its note 
- - playSequence() - Show the current memory pattern on the Arduino
- - getButtonPress() - Check if the user presses a button and return the button pressed
- - isPlayerCorrect() - Check whether the player pressed the correct button(s) for the round
- - playFailSound() - Play the game over sound when the player clicks the incorrect button sequence
- - playWinSound() - Play the win sound when the player clicks the correct button(s) for the sequence
- - gameOver() - Tells the user their score in the serial output

## Skills Learned/Improved
- Fundamentals of digital input/output with Arduino microcontrollers 
- Worked with hardware components (LEDs, resistors, buttons, and piezo buzzer)
- Circuit design and simulation in Tinkercad
- Integrating hardware and software systems
- Writing code for modular functions and structuing programs
- Basic embedded systems programming in C++

## Future Improvements
- Add a OLED display for round and score
- Build 3d printed enclosure 
- Make a leaderboard