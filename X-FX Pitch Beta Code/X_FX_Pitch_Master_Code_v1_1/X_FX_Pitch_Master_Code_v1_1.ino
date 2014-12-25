
// XF-X Pitch v1.1


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
const int numReadings = 5; // Smoothing amount
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
int channel = 6; // Button midi channel
int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
int midichannel = 0; // potentiometer midi channel default

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
      pinMode(leftblue2_buttonpin, INPUT_PULLUP);
      pinMode(leftred_buttonpin, INPUT_PULLUP);
      pinMode(leftgreen_buttonpin, INPUT_PULLUP);
      pinMode(rightblue1_buttonpin, INPUT_PULLUP);
      pinMode(rightblue2_buttonpin, INPUT_PULLUP);
      pinMode(rightred_buttonpin, INPUT_PULLUP);
      pinMode(rightgreen_buttonpin, INPUT_PULLUP);
    
      // Button led setup
      pinMode(left_led_blue1, OUTPUT);
      pinMode(left_led_blue2, OUTPUT);
      pinMode(left_led_red, OUTPUT);
      pinMode(left_led_green, OUTPUT);
      pinMode(right_led_blue1, OUTPUT);
      pinMode(right_led_blue2, OUTPUT);
      pinMode(right_led_red, OUTPUT);
      pinMode(right_led_green, OUTPUT);
    
      Serial.begin(57600);
      Serial.println("XF-X Firmware v1.1");
  
  
      // Tada code 
      for (int x = 0; x < 3; x++)
        {
        int led_bright = 255;
        int led_dim = 20;  
          
        //scene 1
        analogWrite(left_led_blue1, led_bright);
        analogWrite(left_led_red, led_bright);
        delay(25);
        //scene 2
        analogWrite(left_led_blue1, led_dim);
        analogWrite(left_led_red, led_dim);
        analogWrite(left_led_blue2, led_bright);
        analogWrite(left_led_green, led_bright);
        delay(25);
        //scene 3
        analogWrite(left_led_blue2, led_dim);
        analogWrite(left_led_green, led_dim);
        analogWrite(right_led_blue1, led_bright);
        analogWrite(right_led_red, led_bright);
        delay(50);
        //scene 4
        analogWrite(right_led_blue1, led_dim);
        analogWrite(right_led_red, led_dim);
        analogWrite(right_led_blue2, led_bright);
        analogWrite(right_led_green, led_bright);
        delay(50);
        //scene 5
        analogWrite(right_led_blue2, led_dim);
        analogWrite(right_led_green, led_dim);
        analogWrite(right_led_blue1, led_bright);
        analogWrite(right_led_red, led_bright);
        delay(50);
        //scene 6
        analogWrite(right_led_blue1, led_dim);
        analogWrite(right_led_red, led_dim);
        analogWrite(left_led_blue2, led_bright);
        analogWrite(left_led_green, led_bright);
        delay(25);
        //scene 7 
        analogWrite(left_led_blue2, led_dim);
        analogWrite(left_led_green, led_dim);
        analogWrite(left_led_blue1, led_bright);
        analogWrite(left_led_red, led_bright); 
        delay(50); 
        //scene 8 
        analogWrite(left_led_blue1, led_dim);
        analogWrite(left_led_red, led_dim);   
        delay(50); 
        //scene 9 
        }
    }

  // Inits  
  int led_bright = 255;
  int led_dim = 20;
  int led_status_leftblue1 = 15;
  int led_status_leftblue2 = 15;
  int led_status_leftred = 15;
  int led_status_leftgreen = 15;
  int led_status_rightblue1 = 15;
  int led_status_rightblue2 = 15;
  int led_status_rightred = 15;
  int led_status_rightgreen = 15;



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
 
       
   average[i] = (pintotal[i] / numReadings);    
   averagePlus[i] = average[i] + 1;
   averageMinus[i] = average[i] - 1;
   hires = currpotval * 16; // hi-res 10-bit control
   lowres = currpotval / 8; // low-res 7-bit control
   
   midichannel = i + 1;
   
   if (lastreading[i] != average[i]) // If reading is different from the previous
        { 
        if (i < 2) // Hi-res pots
            {  
            usbMIDI.sendPitchBend(hires, midichannel); //send hi-res pot data
              // print current data send
              Serial.print("Transmit pitch fader data slide: "); 
              Serial.print(i);
              Serial.print(" value = "); 
              Serial.println(pintotal[i]);
            }  
        if (i >= 2)  
            {
            usbMIDI.sendControlChange(i,lowres, midichannel); //send low-res pot data
              // print current data send
              Serial.print("Transmit rotary fader pot: ");
              Serial.print(i);
              Serial.print(" value = "); 
              Serial.println(pintotal[i]);
            }
        }
        
   lastreading[i] = average[i];   // Set last array value to current value
  
  
  
  
  
  
  // LED button code starts
  
  // Update led output
  analogWrite(left_led_blue1, led_status_leftblue1);
  analogWrite(left_led_blue2, led_status_leftblue2);
  analogWrite(left_led_red, led_status_leftred);
  analogWrite(left_led_green, led_status_leftgreen);
  analogWrite(right_led_blue1, led_status_rightblue1);
  analogWrite(right_led_blue2, led_status_rightblue2); 
  analogWrite(right_led_red, led_status_rightred);
  analogWrite(right_led_green, led_status_rightgreen);  
  
  // Update Button objects
  leftblue1_buttonObject.update();
  leftblue2_buttonObject.update();
  leftred_buttonObject.update();
  leftgreen_buttonObject.update();  
  rightblue1_buttonObject.update();
  rightblue2_buttonObject.update();
  rightred_buttonObject.update();
  rightgreen_buttonObject.update();
  
  // Left buttons code   
  if (leftblue1_buttonObject.fallingEdge()) 
      {
      led_status_leftblue1 = led_bright;
      Serial.println("Left blue button 1 pressed");
      usbMIDI.sendNoteOn(60, 99, channel);
      }
  if (leftblue1_buttonObject.risingEdge()) 
      {
      led_status_leftblue1 = led_dim;
      Serial.println("Left blue 1 button released"); 
      usbMIDI.sendNoteOff(60, 0, channel);   
      }        
 
  if (leftblue2_buttonObject.fallingEdge()) 
      {
      led_status_leftblue2 = led_bright;
      Serial.println("Left blue 2 button pressed");
      usbMIDI.sendNoteOn(61, 99, channel);
      }
  if (leftblue2_buttonObject.risingEdge()) 
      {
      led_status_leftblue2 = led_dim;
      Serial.println("Left blue 2 button released"); 
      usbMIDI.sendNoteOff(61, 0, channel);   
      }     
 
  if (leftred_buttonObject.fallingEdge()) 
      {
      led_status_leftred = led_bright;
      Serial.println("Left red button pressed");
      usbMIDI.sendNoteOn(62, 99, channel);
      }
  if (leftred_buttonObject.risingEdge()) 
      {
      led_status_leftred = led_dim;
      Serial.println("Left red button released"); 
      usbMIDI.sendNoteOff(62, 0, channel);   
      }                
 
  if (leftgreen_buttonObject.fallingEdge()) 
      {
      led_status_leftgreen = led_bright;
      Serial.println("Left green button pressed");
      usbMIDI.sendNoteOn(63, 99, channel);
      }
  if (leftgreen_buttonObject.risingEdge()) 
      {
      led_status_leftgreen = led_dim;
      Serial.println("Left green button released"); 
      usbMIDI.sendNoteOff(63, 0, channel);   
      }            

  // Right buttons code
  if (rightblue1_buttonObject.fallingEdge()) 
      {
      led_status_rightblue1 = led_bright;
      Serial.println("Right blue 1 button pressed");
      usbMIDI.sendNoteOn(64, 99, channel);
      }
  if (rightblue1_buttonObject.risingEdge()) 
      {
      led_status_rightblue1 = led_dim;
      Serial.println("Right blue 1 button released"); 
      usbMIDI.sendNoteOff(64, 0, channel);   
      }
 
  if (rightblue2_buttonObject.fallingEdge()) 
      {
      led_status_rightblue2 = led_bright;
      Serial.println("Right blue 2 button pressed");
      usbMIDI.sendNoteOn(65, 99, channel);
      }
  if (rightblue2_buttonObject.risingEdge()) 
      {
      led_status_rightblue2 = led_dim;
      Serial.println("Right blue 2 button released"); 
      usbMIDI.sendNoteOff(65, 0, channel);   
      }     
 
  if (rightred_buttonObject.fallingEdge()) 
      {
      led_status_rightred = led_bright;
      Serial.println("Right red button pressed");
      usbMIDI.sendNoteOn(66, 99, channel);
      }
  if (rightred_buttonObject.risingEdge()) 
      {
      led_status_rightred = led_dim;
      Serial.println("Right red button released"); 
      usbMIDI.sendNoteOff(66, 0, channel);   
      }                
 
  if (rightgreen_buttonObject.fallingEdge()) 
      {
      led_status_rightgreen = led_bright;
      Serial.println("Right green button pressed");
      usbMIDI.sendNoteOn(67, 99, channel);
      }
  if (rightgreen_buttonObject.risingEdge()) 
      {
      led_status_rightgreen = led_dim;
      Serial.println("Right green button released"); 
      usbMIDI.sendNoteOff(68, 0, channel);   
      }            

      
  delay(5);  // Delay output by 5ms

  }
}
