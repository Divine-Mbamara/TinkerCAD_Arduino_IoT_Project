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

 ### Software
  - Tinkercad

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
 
### Installation and Setup
- Log in or sign up on Tinkercad
- Go to "Circuits" section and click "Create new Circuit"
- Give your project an appropriate name for easy reference
- Add the components listed in the readme file to the Tinkercad workspace
- Wire the components according to the circuit diagram
- Copy the provided Arduino code from this repository
- Click on the "Code" button in the Tinkercad workspace to open the code editor
- Delete any existing code and paste the copied code into the code editor
- Click on "Start Simulation" beside the "Code" button to run the code

### How To Use
- Follow the instructions on the LCD Screen.
- "Press red button" on the IR Remote
- "Enter Password: 5 characters" (The password is 73164. Type in the password using the IR Remote)

### Expected Outcome
The system will produce output depending on the entered password.

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
