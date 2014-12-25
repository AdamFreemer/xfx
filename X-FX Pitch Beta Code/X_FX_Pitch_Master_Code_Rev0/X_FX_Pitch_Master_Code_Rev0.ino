
// Bounce library import
#include <Bounce.h>

// led pin definitions
#define left_led_blue1 27
#define left_led_blue2 1
#define left_led_red 14
#define left_led_green 0
#define right_led_blue1 15
#define right_led_blue2 26
#define right_led_red 25
#define right_led_green 16

// Button pin declarations
const int leftblue1_buttonpin = 2;
const int leftblue2_buttonpin = 4;
const int leftred_buttonpin = 5;
const int leftgreen_buttonpin = 3;
const int rightblue1_buttonpin = 6;
const int rightblue2_buttonpin = 8;
const int rightred_buttonpin = 9;
const int rightgreen_buttonpin = 7;

// Potentiometer declarations
const int numReadings = 25; // Smoothing amount
int reading_at[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int pots = 4; // The number of pots
int index = 0; // The index of the current reading
int total = 0; // Running total array
int pintotal[6] = {0,0,0,0,0}; // Pin total
int average[6] = {0,0,0,0,0}; // Pin average
int averagePlus[6] = {0,0,0,0,0};
int averageMinus[6] = {0,0,0,0,0};
int currpotval = 0;
int lowres = 0; // Pin average
int hires = 0; // Pin average
int channel = 1; // Set midi channel to send to 1
int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
int midichannel = 0;

// Button object declarations - 10ms debounce
Bounce leftblue1_buttonObject = Bounce(leftblue1_buttonpin, 10); 
Bounce leftblue2_buttonObject = Bounce(leftblue2_buttonpin, 10); 
Bounce leftred_buttonObject = Bounce(leftred_buttonpin, 10); 
Bounce leftgreen_buttonObject = Bounce(leftgreen_buttonpin, 10); 
Bounce rightblue1_buttonObject = Bounce(rightblue1_buttonpin, 10);
Bounce rightblue2_buttonObject = Bounce(rightblue2_buttonpin, 10);
Bounce rightred_buttonObject = Bounce(rightred_buttonpin, 10);
Bounce rightgreen_buttonObject = Bounce(rightgreen_buttonpin, 10);


void setup() 
  {
      
      // Teensy onboard led  
      pinMode(6, OUTPUT);   

      pinMode(leftblue1_buttonpin, INPUT_PULLUP);
      pinMode(Leftblue2_buttonpin, INPUT_PULLUP);
      pinMode(leftred_buttonpin, INPUT_PULLUP);
      pinMode(leftgreen_buttonpin, INPUT_PULLUP);
      pinMode(rightblue1_buttonpin, INPUT_PULLUP);
      pinMode(rightblue2_buttonpin, INPUT_PULLUP);
      pinMode(rightred_buttonpin, INPUT_PULLUP);
      pinMode(rightgreen_buttonpin, INPUT_PULLUP);
    
      // Button led setup
      pinMode(Left_led_Blue1, OUTPUT);
      pinMode(Left_led_Blue2, OUTPUT);
      pinMode(Left_led_Red, OUTPUT);
      pinMode(Left_led_Green, OUTPUT);
      pinMode(Right_led_Blue1, OUTPUT);
      pinMode(Right_led_Blue2, OUTPUT);
      pinMode(Right_led_Red, OUTPUT);
      pinMode(Right_led_Green, OUTPUT);
    
      Serial.begin(57600);
      Serial.println("Pushbutton Bounce library test:");
  
  
      // Tada code 
      for (int x = 0; x < 3; x++)
        {
        int led_BRIGHT = 255;
        int led_DIM = 20;  
          
        //scene 1
        analogWrite(Left_led_Blue1, led_BRIGHT);
        analogWrite(Left_led_Red, led_BRIGHT);
        delay(25);
        //scene 2
        analogWrite(Left_led_Blue1, led_DIM);
        analogWrite(Left_led_Red, led_DIM);
        analogWrite(Left_led_Blue2, led_BRIGHT);
        analogWrite(Left_led_Green, led_BRIGHT);
        delay(25);
        //scene 3
        analogWrite(Left_led_Blue2, led_DIM);
        analogWrite(Left_led_Green, led_DIM);
        analogWrite(Right_led_Blue1, led_BRIGHT);
        analogWrite(Right_led_Red, led_BRIGHT);
        delay(50);
        //scene 4
        analogWrite(Right_led_Blue1, led_DIM);
        analogWrite(Right_led_Red, led_DIM);
        analogWrite(Right_led_Blue2, led_BRIGHT);
        analogWrite(Right_led_Green, led_BRIGHT);
        delay(50);
        //scene 5
        analogWrite(Right_led_Blue2, led_DIM);
        analogWrite(Right_led_Green, led_DIM);
        analogWrite(Right_led_Blue1, led_BRIGHT);
        analogWrite(Right_led_Red, led_BRIGHT);
        delay(50);
        //scene 6
        analogWrite(Right_led_Blue1, led_DIM);
        analogWrite(Right_led_Red, led_DIM);
        analogWrite(Left_led_Blue2, led_BRIGHT);
        analogWrite(Left_led_Green, led_BRIGHT);
        delay(25);
        //scene 7 
        analogWrite(Left_led_Blue2, led_DIM);
        analogWrite(Left_led_Green, led_DIM);
        analogWrite(Left_led_Blue1, led_BRIGHT);
        analogWrite(Left_led_Red, led_BRIGHT); 
         delay(50); 
        //scene 8 
        analogWrite(Left_led_Blue1, led_DIM);
        analogWrite(Left_led_Red, led_DIM);   
         delay(50); 
        //scene 9 
        }
  }

  // Inits  
  int led_BRIGHT = 255;
  int led_DIM = 20;
  int led_STATUS_LeftBlue1 = 15;
  int led_STATUS_LeftBlue2 = 15;
  int led_STATUS_LeftRed = 15;
  int led_STATUS_LeftGreen = 15;
  int led_STATUS_RightBlue1 = 15;
  int led_STATUS_RightBlue2 = 15;
  int led_STATUS_RightRed = 15;
  int led_STATUS_RightGreen = 15;
  int channel = 1;


// Main loop
void loop() 
  {
    
  // Teensy onboard led
  pinMode(6, OUTPUT);   
  
  
  // Main pot loop
  for (int i = 0; i < pots; i++ )  // pots = pot count + 1
    {
    index = 0;  // Set index to zero
    
    for (int j = 0; j < numReadings; j++ )  // loop to create average reading
      {
      total = total - reading_at[index];
      reading_at[index] = analogRead(i); // read from pot i
      currpotval = reading_at[index];   
      total = total + reading_at[index];
      index = index++;
      pintotal[i] = total;
      }
 
       
       average[i] = (pintotal[i] / numReadings);    // Calculate the average Divide by 8 to make between 0-127
       averagePlus[i] = average[i] + 1;
       averageMinus[i] = average[i] - 1;
       hires = currpotval * 16;
       lowres = currpotval / 8;
       
       midichannel = i + 1;
       
       if (lastreading[i] != average[i]) // If reading is different from the previous
            { 
            if (i < 2) // Hi-res pots
                {  
                usbMIDI.sendPitchBend(hires, midichannel); //send hi-res pot data
                }  
            if (i >= 2)  
                {
                usbMIDI.sendControlChange(i,lowres, midichannel); //send low-res pot data
                }
            }
            
       lastreading[i] = average[i];   // Set last array value to current value
  
  
  
  // Update led output
  analogWrite(Left_led_Blue1, led_STATUS_LeftBlue1);
  analogWrite(Left_led_Blue2, led_STATUS_LeftBlue2);
  analogWrite(Left_led_Red, led_STATUS_LeftRed);
  analogWrite(Left_led_Green, led_STATUS_LeftGreen);
  analogWrite(Right_led_Blue1, led_STATUS_RightBlue1);
  analogWrite(Right_led_Blue2, led_STATUS_RightBlue2); 
  analogWrite(Right_led_Red, led_STATUS_RightRed);
  analogWrite(Right_led_Green, led_STATUS_RightGreen);  
  
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
      led_STATUS_LeftBlue1 = led_BRIGHT;
      Serial.println("Left blue button 1 pressed");
      usbMIDI.sendNoteOn(60, 99, channel);
      }
  if (LeftBlue1_ButtonObject.risingEdge()) 
      {
      led_STATUS_LeftBlue1 = led_DIM;
      Serial.println("Left blue 1 button released"); 
      usbMIDI.sendNoteOff(60, 0, channel);   
      }        
 
  if (LeftBlue2_ButtonObject.fallingEdge()) 
      {
      led_STATUS_LeftBlue2 = led_BRIGHT;
      Serial.println("Left blue 2 button pressed");
      usbMIDI.sendNoteOn(61, 99, channel);
      }
  if (LeftBlue2_ButtonObject.risingEdge()) 
      {
      led_STATUS_LeftBlue2 = led_DIM;
      Serial.println("Left blue 2 button released"); 
      usbMIDI.sendNoteOff(61, 0, channel);   
      }     
 
  if (LeftRed_ButtonObject.fallingEdge()) 
      {
      led_STATUS_LeftRed = led_BRIGHT;
      Serial.println("Left red button pressed");
      usbMIDI.sendNoteOn(62, 99, channel);
      }
  if (LeftRed_ButtonObject.risingEdge()) 
      {
      led_STATUS_LeftRed = led_DIM;
      Serial.println("Left red button released"); 
      usbMIDI.sendNoteOff(62, 0, channel);   
      }                
 
  if (LeftGreen_ButtonObject.fallingEdge()) 
      {
      led_STATUS_LeftGreen = led_BRIGHT;
      Serial.println("Left green button pressed");
      usbMIDI.sendNoteOn(63, 99, channel);
      }
  if (LeftGreen_ButtonObject.risingEdge()) 
      {
      led_STATUS_LeftGreen = led_DIM;
      Serial.println("Left green button released"); 
      usbMIDI.sendNoteOff(63, 0, channel);   
      }            

  // Right buttons code
  if (RightBlue1_ButtonObject.fallingEdge()) 
      {
      led_STATUS_RightBlue1 = led_BRIGHT;
      Serial.println("Right blue 1 button pressed");
      usbMIDI.sendNoteOn(64, 99, channel);
      }
  if (RightBlue1_ButtonObject.risingEdge()) 
      {
      led_STATUS_RightBlue1 = led_DIM;
      Serial.println("Right blue 1 button released"); 
      usbMIDI.sendNoteOff(64, 0, channel);   
      }
 
  if (RightBlue2_ButtonObject.fallingEdge()) 
      {
      led_STATUS_RightBlue2 = led_BRIGHT;
      Serial.println("Right blue 2 button pressed");
      usbMIDI.sendNoteOn(65, 99, channel);
      }
  if (RightBlue2_ButtonObject.risingEdge()) 
      {
      led_STATUS_RightBlue2 = led_DIM;
      Serial.println("Right blue 2 button released"); 
      usbMIDI.sendNoteOff(65, 0, channel);   
      }     
 
  if (RightRed_ButtonObject.fallingEdge()) 
      {
      led_STATUS_RightRed = led_BRIGHT;
      Serial.println("Right red button pressed");
      usbMIDI.sendNoteOn(66, 99, channel);
      }
  if (RightRed_ButtonObject.risingEdge()) 
      {
      led_STATUS_RightRed = led_DIM;
      Serial.println("Right red button released"); 
      usbMIDI.sendNoteOff(66, 0, channel);   
      }                
 
  if (RightGreen_ButtonObject.fallingEdge()) 
      {
      led_STATUS_RightGreen = led_BRIGHT;
      Serial.println("Right green button pressed");
      usbMIDI.sendNoteOn(67, 99, channel);
      }
  if (RightGreen_ButtonObject.risingEdge()) 
      {
      led_STATUS_RightGreen = led_DIM;
      Serial.println("Right green button released"); 
      usbMIDI.sendNoteOff(68, 0, channel);   
      }            

      
  delay(5);  // Delay output by 5ms

}
