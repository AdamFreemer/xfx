
// Bounce library import
#include <Bounce.h>

// LED pin definitions
#define Left_LED_Blue1 27
#define Left_LED_Blue2 1
#define Left_LED_Red 14
#define Left_LED_Green 0
#define Right_LED_Blue1 15
#define Right_LED_Blue2 26
#define Right_LED_Red 25
#define Right_LED_Green 16

// Button pin declarations
const int LeftBlue1_ButtonPin = 2;
const int LeftBlue2_ButtonPin = 4;
const int LeftRed_ButtonPin = 5;
const int LeftGreen_ButtonPin = 3;
const int RightBlue1_ButtonPin = 6;
const int RightBlue2_ButtonPin = 8;
const int RightRed_ButtonPin = 9;
const int RightGreen_ButtonPin = 7;

// Button object declarations - 10ms debounce
Bounce LeftBlue1_ButtonObject = Bounce(LeftBlue1_ButtonPin, 10); 
Bounce LeftBlue2_ButtonObject = Bounce(LeftBlue2_ButtonPin, 10); 
Bounce LeftRed_ButtonObject = Bounce(LeftRed_ButtonPin, 10); 
Bounce LeftGreen_ButtonObject = Bounce(LeftGreen_ButtonPin, 10); 
Bounce RightBlue1_ButtonObject = Bounce(RightBlue1_ButtonPin, 10);
Bounce RightBlue2_ButtonObject = Bounce(RightBlue2_ButtonPin, 10);
Bounce RightRed_ButtonObject = Bounce(RightRed_ButtonPin, 10);
Bounce RightGreen_ButtonObject = Bounce(RightGreen_ButtonPin, 10);


void setup() 
  {
      // Button input setup
      pinMode(LeftBlue1_ButtonPin, INPUT_PULLUP);
      pinMode(LeftBlue2_ButtonPin, INPUT_PULLUP);
      pinMode(LeftRed_ButtonPin, INPUT_PULLUP);
      pinMode(LeftGreen_ButtonPin, INPUT_PULLUP);
      pinMode(RightBlue1_ButtonPin, INPUT_PULLUP);
      pinMode(RightBlue2_ButtonPin, INPUT_PULLUP);
      pinMode(RightRed_ButtonPin, INPUT_PULLUP);
      pinMode(RightGreen_ButtonPin, INPUT_PULLUP);
    
      // Button LED setup
      pinMode(Left_LED_Blue1, OUTPUT);
      pinMode(Left_LED_Blue2, OUTPUT);
      pinMode(Left_LED_Red, OUTPUT);
      pinMode(Left_LED_Green, OUTPUT);
      pinMode(Right_LED_Blue1, OUTPUT);
      pinMode(Right_LED_Blue2, OUTPUT);
      pinMode(Right_LED_Red, OUTPUT);
      pinMode(Right_LED_Green, OUTPUT);
    
      Serial.begin(57600);
      Serial.println("Pushbutton Bounce library test:");
  
  
      // tada code 
      for (int x = 0; x < 3; x++)
        {
        int LED_BRIGHT = 255;
        int LED_DIM = 20;  
          
        //scene 1
        analogWrite(Left_LED_Blue1, LED_BRIGHT);
        analogWrite(Left_LED_Red, LED_BRIGHT);
        delay(25);
        //scene 2
        analogWrite(Left_LED_Blue1, LED_DIM);
        analogWrite(Left_LED_Red, LED_DIM);
        analogWrite(Left_LED_Blue2, LED_BRIGHT);
        analogWrite(Left_LED_Green, LED_BRIGHT);
        delay(25);
        //scene 3
        analogWrite(Left_LED_Blue2, LED_DIM);
        analogWrite(Left_LED_Green, LED_DIM);
        analogWrite(Right_LED_Blue1, LED_BRIGHT);
        analogWrite(Right_LED_Red, LED_BRIGHT);
        delay(50);
        //scene 4
        analogWrite(Right_LED_Blue1, LED_DIM);
        analogWrite(Right_LED_Red, LED_DIM);
        analogWrite(Right_LED_Blue2, LED_BRIGHT);
        analogWrite(Right_LED_Green, LED_BRIGHT);
        delay(50);
        //scene 5
        analogWrite(Right_LED_Blue2, LED_DIM);
        analogWrite(Right_LED_Green, LED_DIM);
        analogWrite(Right_LED_Blue1, LED_BRIGHT);
        analogWrite(Right_LED_Red, LED_BRIGHT);
        delay(50);
        //scene 6
        analogWrite(Right_LED_Blue1, LED_DIM);
        analogWrite(Right_LED_Red, LED_DIM);
        analogWrite(Left_LED_Blue2, LED_BRIGHT);
        analogWrite(Left_LED_Green, LED_BRIGHT);
        delay(25);
        //scene 7 
        analogWrite(Left_LED_Blue2, LED_DIM);
        analogWrite(Left_LED_Green, LED_DIM);
        analogWrite(Left_LED_Blue1, LED_BRIGHT);
        analogWrite(Left_LED_Red, LED_BRIGHT); 
         delay(50); 
        //scene 8 
        analogWrite(Left_LED_Blue1, LED_DIM);
        analogWrite(Left_LED_Red, LED_DIM);   
         delay(50); 
        //scene 9 
        }
  }

// Inits  
int LED_BRIGHT = 255;
int LED_DIM = 20;
int LED_STATUS_LeftBlue1 = 15;
int LED_STATUS_LeftBlue2 = 15;
int LED_STATUS_LeftRed = 15;
int LED_STATUS_LeftGreen = 15;
int LED_STATUS_RightBlue1 = 15;
int LED_STATUS_RightBlue2 = 15;
int LED_STATUS_RightRed = 15;
int LED_STATUS_RightGreen = 15;
int channel = 1;

//int blueLED1 = 27;
//int blueLED2 = 1;

// Main loop
void loop() 
  {
  // Update LED output
  analogWrite(Left_LED_Blue1, LED_STATUS_LeftBlue1);
  analogWrite(Left_LED_Blue2, LED_STATUS_LeftBlue2);
  analogWrite(Left_LED_Blue1, LED_STATUS_LeftRed);
  analogWrite(Left_LED_Blue2, LED_STATUS_LeftGreen);
  analogWrite(Left_LED_Blue1, LED_STATUS_RightBlue1);
  analogWrite(Left_LED_Blue2, LED_STATUS_RightBlue2); 
  analogWrite(Left_LED_Blue1, LED_STATUS_RightRed);
  analogWrite(Left_LED_Blue2, LED_STATUS_RightGreen);  
  
  // Update Button objects
  LeftBlue1_ButtonObject.update();
  LeftBlue2_ButtonObject.update();
  LeftRed_ButtonObject.update();
  LeftGreen_ButtonObject.update();  
  RightBlue1_ButtonObject.update();
  RightBlue2_ButtonObject.update();
  RightRed_ButtonObject.update();
  RightGreen_ButtonObject.update();


  // Left buttons code   
      if (LeftBlue1_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_LeftBlue1 = LED_BRIGHT;
          Serial.println("Left blue button 1 pressed");
          usbMIDI.sendNoteOn(60, 99, channel);
          }
      if (LeftBlue1_ButtonObject.risingEdge()) 
          {
          LED_STATUS_LeftBlue1 = LED_DIM;
          Serial.println("Left blue 1 button released"); 
          usbMIDI.sendNoteOff(60, 0, channel);   
          }        
      if (LeftBlue2_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_LeftBlue2 = LED_BRIGHT;
          Serial.println("Left blue 2 button pressed");
          usbMIDI.sendNoteOn(61, 99, channel);
          }
      if (LeftBlue2_ButtonObject.risingEdge()) 
          {
          LED_STATUS_LeftBlue2 = LED_DIM;
          Serial.println("Left blue 2 button released"); 
          usbMIDI.sendNoteOff(61, 0, channel);   
          }     
      if (LeftRed_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_LeftRed = LED_BRIGHT;
          Serial.println("Left red button pressed");
          usbMIDI.sendNoteOn(62, 99, channel);
          }
      if (LeftRed_ButtonObject.risingEdge()) 
          {
          LED_STATUS_LeftRed = LED_DIM;
          Serial.println("Left red button released"); 
          usbMIDI.sendNoteOff(62, 0, channel);   
          }                
      if (LeftGreen_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_LeftGreen = LED_BRIGHT;
          Serial.println("Left green button pressed");
          usbMIDI.sendNoteOn(63, 99, channel);
          }
      if (LeftGreen_ButtonObject.risingEdge()) 
          {
          LED_STATUS_LeftGreen = LED_DIM;
          Serial.println("Left green button released"); 
          usbMIDI.sendNoteOff(63, 0, channel);   
          }            

      // Right buttons code
      if (RightBlue1_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_RightBlue1 = LED_BRIGHT;
          Serial.println("Right blue 1 button pressed");
          usbMIDI.sendNoteOn(64, 99, channel);
          }
      if (RightBlue1_ButtonObject.risingEdge()) 
          {
          LED_STATUS_RightBlue1 = LED_DIM;
          Serial.println("Right blue 1 button released"); 
          usbMIDI.sendNoteOff(64, 0, channel);   
          }
      if (RightBlue2_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_RightBlue2 = LED_BRIGHT;
          Serial.println("Right blue 2 button pressed");
          usbMIDI.sendNoteOn(65, 99, channel);
          }
      if (RightBlue2_ButtonObject.risingEdge()) 
          {
          LED_STATUS_RightBlue2 = LED_DIM;
          Serial.println("Right blue 2 button released"); 
          usbMIDI.sendNoteOff(65, 0, channel);   
          }     
      if (RightRed_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_RightRed = LED_BRIGHT;
          Serial.println("Right red button pressed");
          usbMIDI.sendNoteOn(66, 99, channel);
          }
      if (RightRed_ButtonObject.risingEdge()) 
          {
          LED_STATUS_RightRed = LED_DIM;
          Serial.println("Right red button released"); 
          usbMIDI.sendNoteOff(66, 0, channel);   
          }                
      if (RightGreen_ButtonObject.fallingEdge()) 
          {
          LED_STATUS_RightGreen = LED_BRIGHT;
          Serial.println("Right green button pressed");
          usbMIDI.sendNoteOn(67, 99, channel);
          }
      if (RightGreen_ButtonObject.risingEdge()) 
          {
          LED_STATUS_RightGreen = LED_DIM;
          Serial.println("Right green button released"); 
          usbMIDI.sendNoteOff(67, 0, channel);   
          }            

      





}
