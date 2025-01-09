# TinkerCAD_Arduino_IoT_Project
## Driveway Security System

![Final Project](https://github.com/user-attachments/assets/4481a411-fe9f-4395-9b73-6602bbb6aee5)

### Description
This project uses an Arduino to simulate a driveway security system. The system requires the user to input the correct password before granting access to the gate.
If the password is correct:
- The green light flashes.
- The piezo buzzer emits a sound.
- The LCD screen displays "Access granted."
- The gate (simulated by a servo motor) opens.
If the password is incorrect:
- The red light flashes.
- The piezo buzzer emits a different sound.
- The LCD screen displays "Access denied."
- The gate remains locked.

### Features
- Password protection for access
- Servo motor simulates gate opening
- Visual (LED lights) and sound (Piezo buzzer) indicators for access status
- LCD screen feedback

### Components
- Arduino Uno
- LCD screen
- IR sensor
- Servo motor
- LED lights
- Piezo buzzer
- Resistors
- Jumper wires
- Breadboard
