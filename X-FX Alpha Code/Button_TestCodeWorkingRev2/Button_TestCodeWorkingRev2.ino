#include <Bounce.h>

#define Left_LED_Blue1 27
#define Left_LED_Blue2 1
#define Left_LED_Red 14
#define Left_LED_Green 0
#define Right_LED_Blue1 15
#define Right_LED_Blue2 26
#define Right_LED_Red 25
#define Right_LED_Green 16

const int buttonPin = 2;
const int buttonPin1 = 4;
Bounce pushbutton = Bounce(buttonPin, 10);  // 10 ms debounce
Bounce pushbutton1 = Bounce(buttonPin1, 10);  // 10 ms debounce

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(27, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(16, OUTPUT);
  
  Serial.begin(57600);
  Serial.println("Pushbutton Bounce library test:");
  
  
// --- tada code --- //

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

int LED_BRIGHT = 255;
int LED_DIM = 20;
int LED_STATUS_1 = 15;
int LED_STATUS_2 = 15;
int channel = 1;
int blueLED1 = 27;
int blueLED2 = 1;

void loop() {
  
  analogWrite(blueLED1, LED_STATUS_1);
  analogWrite(blueLED2, LED_STATUS_2);
  
  pushbutton.update();
  pushbutton1.update();

      
      if (pushbutton.fallingEdge()) 
          {
          LED_STATUS_1 = LED_BRIGHT;
          Serial.println("Button 1 Pressed");
          usbMIDI.sendNoteOn(60, 99, channel);
          }
      if (pushbutton.risingEdge()) 
          {
          LED_STATUS_1 = LED_DIM;
          Serial.println("Button 1 Let Go"); 
          usbMIDI.sendNoteOff(60, 0, channel);   
          }
      


      
      if (pushbutton1.fallingEdge()) 
          {
          LED_STATUS_2 = LED_BRIGHT;
          Serial.println("Button 2 Pressed");
          usbMIDI.sendNoteOn(61, 99, channel);
          }
      if (pushbutton1.risingEdge()) 
          {
          LED_STATUS_2 = LED_DIM;
          Serial.println("Button 2 Let Go"); 
          usbMIDI.sendNoteOff(61, 0, channel);   
          }
      


}
