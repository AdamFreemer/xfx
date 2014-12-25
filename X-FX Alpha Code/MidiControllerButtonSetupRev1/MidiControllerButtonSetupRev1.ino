#include <Bounce.h>

// This code turns a led on/off through a debounced button
// Build the circuit indicated here: http://arduino.cc/en/Tutorial/Button

// define button pins : parameter # = pin number off schematic
#define Left_Button_Blue1 02
#define Left_Button_Blue2 04
#define Left_Button_Red 05
#define Left_Button_Green 03
#define Right_Button_Blue1 06 
#define Right_Button_Blue2 08
#define Right_Button_Red 09
#define Right_Button_Green 07

// define led pins : parameter # = pin number off schematic
#define Left_LED_Blue1 27
#define Left_LED_Blue2 01
#define Left_LED_Red 14
#define Left_LED_Green 00
#define Right_LED_Blue1 15
#define Right_LED_Blue2 26
#define Right_LED_Red 25
#define Right_LED_Green 16

// Instantiate bounce objects : parameter 2 = bounce time in ms
Bounce Left_Button_Blue1_Object = Bounce(Left_Button_Blue1, 5); 
Bounce Left_Button_Blue2_Object = Bounce(Left_Button_Blue2, 5); 
Bounce Left_Button_Red_Object = Bounce(Left_Button_Red, 5); 
Bounce Left_Button_Green_Object = Bounce(Left_Button_Green, 5); 
Bounce Right_Button_Blue1_Object = Bounce(Right_Button_Blue1, 5); 
Bounce Right_Button_Blue2_Object = Bounce(Right_Button_Blue2, 5); 
Bounce Right_Button_Red_Object = Bounce(Right_Button_Red, 5); 
Bounce Right_Button_Green_Object = Bounce(Right_Button_Green, 5); 

void setup() {
  
  // Button setup based off defines
  pinMode(Left_Button_Blue1,INPUT);
  pinMode(Left_Button_Blue2,INPUT);
  pinMode(Left_Button_Red,INPUT);    
  pinMode(Left_Button_Green,INPUT);  
  pinMode(Right_Button_Blue1,INPUT);
  pinMode(Right_Button_Blue2,INPUT);
  pinMode(Right_Button_Red,INPUT);    
  pinMode(Right_Button_Green,INPUT);    

  // LED setup based off defines
  pinMode(Left_LED_Blue1, OUTPUT);
  pinMode(Left_LED_Blue2, OUTPUT);
  pinMode(Left_LED_Red, OUTPUT);
  pinMode(Left_LED_Green, OUTPUT);
  pinMode(Right_LED_Blue1, OUTPUT);
  pinMode(Right_LED_Blue2, OUTPUT);
  pinMode(Right_LED_Red, OUTPUT);
  pinMode(Right_LED_Green, OUTPUT);
}

void loop() {
 // Update the debouncer
  bouncer.update ( );
 
 // Get the update value
    int value = bouncer.read();

// analogWrite(Left_LED_Blue1, 100);
// analogWrite(Left_LED_Blue2, 100);
// analogWrite(Left_LED_Red, 100);
// analogWrite(Left_LED_Green, 100);
// analogWrite(Right_LED_Blue1, 100);
// analogWrite(Right_LED_Blue2, 100);
// analogWrite(Right_LED_Red, 100);
// analogWrite(Right_LED_Green, 100);
 
 
 // Turn on or off the LED
 if ( value == HIGH) 
    {
    analogWrite(Left_LED_Blue1, 100);
    } 
    else 
    {
    analogWrite(Left_LED_Blue1, 0);
    }
 
}

