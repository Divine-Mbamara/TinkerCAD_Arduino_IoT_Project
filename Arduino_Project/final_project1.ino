// Divine Lotanna Mbamara
// Final Project
// July 24, 2024
// Goal - Create a Gate Security System for a driveway

// FUNCTIONALITIES
// Red button represents car at the gate
// Servo motor is the gate
// If red button is pressed, prompt driver for password to access driveway
// If password is correct, display greenLED and open gate
// If password is incorrect, display redLED and keep gate closed
// Add buzzer sounds for effect 

//Import Libraries
#include <LiquidCrystal.h>
#include <IRremote.h>
#define IR_RECEIVE_PIN 10
#include <Servo.h>

//Initialize the Serial LCD
LiquidCrystal lcd(12,11,5,4,3,2);

//create variables
Servo myservo;
int redLED=8;//The red LED is connected pin 8 of the Arduino.
int greenLED=9;//The green LED is connected pin 9 of the Arduino.
int value = -1;
int angle = 0;
char number;
char correctPassword[5]={'7','3','1','6','4'};
char userInput[5]={};
int correct=0;
int count=0;
int buzzerPin =7;


void setup()
{
  myservo.attach(6);
  pinMode(redLED, OUTPUT); //Setup red LED as an output pin.
  pinMode(greenLED, OUTPUT); //Setup green LED as an output pin.
  lcd.begin(16,2); //initialize the lcd screen
  IrReceiver.begin(IR_RECEIVE_PIN); //initialize Ir remote
  Serial.begin(9600);
}


void loop()
{
  myservo.write(angle);
  delay(200);
  //Prompt driver to press power button for password
  lcd.setCursor(0,0);
  lcd.print("Press red button"); 

  if (IrReceiver.decode()) {
    IrReceiver.resume();
    value = IrReceiver.decodedIRData.command;
    Serial.println(value);
    //wait for power button
    if(value==0){
       //print instructions
       printPrompt();
       //wait for driver to type in password
       waitpassword();
    }
  }
}

 
  //Create functions
 // Function 1 - Instructions
void printPrompt(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter password:");
    lcd.setCursor(0,1);
    lcd.print("5 characters");
    delay(1000);
}


 //Function 2 - Wait for password & Print on LCD Screen
void waitpassword(){
    while(count<5){
      Serial.println("entering loop1");
      if (IrReceiver.decode()) {
         IrReceiver.resume();
         value = IrReceiver.decodedIRData.command;
         //call the password functionality
         Serial.println("got user input");
         //call the function for converting remote buttons to char
         remoteToChar();
         userInput[count]=number;
         count++;
         //display to screen
         lcd.clear();
         for(int i=0; i<5; i++){
            lcd.setCursor(i,0);
            lcd.print(userInput[i]);
            delay(500);
         }//end of for loop
      }//end of if statement
    }//end of while loop
   //call the password function
   password();
     
  value=-1;
  Serial.println("ending waitpassword");
}


 //Function 3 - Checks if password is correct or incorrect
 //with functionalities for both cases
void password(){
   //display password the driver enters on the lcd screen
  for(int i=0; i<5; i++){
     lcd.clear();
     lcd.setCursor(i,0);
     lcd.print(userInput[i]);
  }
   //check if password is correct or incorrect
  for(int i=0; i<5; i++){
    if(userInput[i] == correctPassword[i]){
       correct++;
    }
  }//end of for loop
  
   if(correct==5){ //if correct, access granted
       //flash greenLED
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
       //print message to LCD screen
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Access granted");
       //make buzzer sound - beep 3 times
      for(int i=0; i<3; i++){
         analogWrite(buzzerPin,200);
         delay(150);
         analogWrite(buzzerPin,0);
         delay(150);
      }
       //open servo motor & close after 2 seconds
      angle= angle+120;
      myservo.write(angle);
      delay(2000);
      angle= angle-120;
      myservo.write(angle);
      delay(2000);
   }
   else{ //if incorrect, access denied
       //flash redLED
      digitalWrite(redLED, HIGH);
      delay(400);
      digitalWrite(redLED, LOW);
       //print message to LCD screen
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Access denied");
       //make buzzer sound - beep once
      analogWrite(buzzerPin,500);
      delay(200);
      analogWrite(buzzerPin,0);
      delay(200);
  }
  
  myservo.write(angle);
  delay(200);
  correct = 0;
  count = 0;
  for(int i=0;i<5;i++){
    userInput[i]=0;
  }
}
    

 //Function 4 - Converts buttons on remote to char
void remoteToChar(){
     //change remote buttons to char
    if(value==12){
      number='0';
    }else if(value==16){
      number='1';
    }else if(value==17){
      number='2';
    }else if(value==18){
      number='3';
    }else if(value==20){
      number='4';
    }else if(value==21){
      number='5';
    }else if(value==22){
      number='6';
    }else if(value==24){
      number='7';
    }else if(value==25){
      number='8';
    }else if(value==26){
      number='9';
    }
} 
  