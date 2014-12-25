#include <Bounce.h>

// This code turns a led on/off through a debounced button
// Build the circuit indicated here: http://arduino.cc/en/Tutorial/Button

// define button pins : parameter # = pin number off schematic
#define Left_Button_Blue1 2
#define Left_Button_Blue2 4
#define Left_Button_Red 5
#define Left_Button_Green 3
#define Right_Button_Blue1 6 
#define Right_Button_Blue2 8
#define Right_Button_Red 9
#define Right_Button_Green 7

// define led pins : parameter # = pin number off schematic
#define Left_LED_Blue1 27
#define Left_LED_Blue2 1
#define Left_LED_Red 14
#define Left_LED_Green 0
#define Right_LED_Blue1 15
#define Right_LED_Blue2 26
#define Right_LED_Red 25
#define Right_LED_Green 16

// Instantiate bounce objects : parameter 2 = bounce time in ms
Bounce Left_Button_Blue1_Object = Bounce (Left_Button_Blue1, 5); 
Bounce Left_Button_Blue2_Object = Bounce (Left_Button_Blue2, 5); 
Bounce Left_Button_Red_Object = Bounce (Left_Button_Red, 5); 
Bounce Left_Button_Green_Object = Bounce (Left_Button_Green, 5); 
Bounce Right_Button_Blue1_Object = Bounce (Right_Button_Blue1, 5); 
Bounce Right_Button_Blue2_Object = Bounce (Right_Button_Blue2, 5); 
Bounce Right_Button_Red_Object = Bounce (Right_Button_Red, 5); 
Bounce Right_Button_Green_Object = Bounce (Right_Button_Green, 5); 

void setup() {
  
  // Button setup based off defines
  pinMode(Left_Button_Blue1,INPUT_PULLUP);
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
  Left_Button_Blue1_Object.update ( );
  Left_Button_Blue2_Object.update ( );
  Left_Button_Red_Object.update ( ); 
  Left_Button_Green_Object.update ( ); 
  Right_Button_Blue1_Object.update ( ); 
  Right_Button_Blue2_Object.update ( ); 
  Right_Button_Red_Object.update ( ); 
  Right_Button_Green_Object.update ( );

  
 // Get the update value
//    int Left_Button_Blue1_State = Left_Button_Blue1_Object.read();
//    int Left_Button_Blue2_State = Left_Button_Blue2_Object.read();
//    int Left_Button_Red_State = Left_Button_Red_Object.read();  
//    int Left_Button_Green_State = Left_Button_Green_Object.read();  
//    int Right_Button_Blue1_State = Right_Button_Blue1_Object.read();  
//    int Right_Button_Blue2_State = Right_Button_Blue2_Object.read();  
//    int Right_Button_Red_State = Right_Button_Red_Object.read();  
//    int Right_Button_Green_State = Right_Button_Green_Object.read(); 
//     
 // Logic Section
 
  if (Left_Button_Blue1_Object.update()) {
    if (Left_Button_Blue1_Object.fallingEdge()) {
      Serial.print("bounce ");
   //  delay(2000);  // Delay output by 5ms
    }
  } 
      


 
 
// 
// 
//   if ( Left_Button_Blue1_State == HIGH) 
//      {
//      analogWrite(Left_LED_Blue1, 100);
//      } 
//      else 
//      {
//      analogWrite(Left_LED_Blue1, 0);
//      }
//      
   

    
}

