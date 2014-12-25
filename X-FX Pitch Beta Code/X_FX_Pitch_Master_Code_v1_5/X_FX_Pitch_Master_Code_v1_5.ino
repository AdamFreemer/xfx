
//****** XF-X Pitch v1.4 ******//


// Bounce library import
#include <Bounce.h>

// analog input inits
int inputpin = 0;  
const int numReadings = 1; 
int midichannel = 0; // Analog input midi channels
int channel = 6; // Button midi channels

// pot 1 inits (fader 1)
int readings1[numReadings];      // readings from the analog input
int index1 = 0;                  // index of the current reading
int total1 = 0;                  // running total
int average1 = 0;                // average       
unsigned int diff1 = 0;          // differential
int hires1 = 0;

// pot 2 inits (fader 2)
int readings2[numReadings];      // readings from the analog input
int index2 = 0;                  // index of the current reading
int total2 = 0;                  // running total
int average2 = 0;                // average       
unsigned int diff2 = 0;          // differential
int hires2 = 0;

// pot 3 inits (rotary 1)
int readings3[numReadings];      // readings from the analog input
int index3 = 0;                  // index of the current reading
int total3 = 0;                  // running total
int average3 = 0;                // average       
unsigned int diff3 = 0;          // differential
int lowres3 = 0;

// pot 4 inits (rotary 2)
int readings4[numReadings];      // readings from the analog input
int index4 = 0;                  // index of the current reading
int total4 = 0;                  // running total
int average4 = 0;                // average       
unsigned int diff4 = 0;          // differential
int lowres4 = 0;

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

   
      // Button switch setup
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
          
           
      // Analog input setups
      for (int thisReading1 = 0; thisReading1 < numReadings; thisReading1++) // initialize all readingsin array to 0 for pot1
        {
        readings1[thisReading1] = 0;          
        }          
      for (int thisReading2 = 0; thisReading2 < numReadings; thisReading2++) // initialize all readingsin array to 0 for pot2
        {  
        readings2[thisReading2] = 0;          
        }      
      for (int thisReading3 = 0; thisReading3 < numReadings; thisReading3++) // initialize all readingsin array to 0 for pot3
        {
        readings3[thisReading3] = 0;          
        }
      for (int thisReading4 = 0; thisReading4 < numReadings; thisReading4++) // initialize all readingsin array to 0 for pot4
        {
        readings4[thisReading4] = 0;          
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




void loop() // Main operation loop
  {
  
  
  delay(5);  // Delay output by 5ms
    
  // Teensy onboard led
  pinMode(6, OUTPUT);   
  

  // pot 1 execution code block (fader 1) ////////////////////////
  inputpin = 0; 
  midichannel = 1; 
  total1 = total1 - readings1[index1];      
  readings1[index1] = analogRead(inputpin);    
  total1 = total1 + readings1[index1];   
  index1 = index1 + 1;                    
  if (index1 >= numReadings) //reset index to beginning of array 
      {  
      index1 = 0;                          
      }  
  average1 = total1 / numReadings;        
  diff1 =  readings1[index1] - average1;
  hires1 = average1 * 16;
  if ( diff1 > 1 )
      {
      usbMIDI.sendPitchBend(hires1, midichannel); //send hi-res pot data
      Serial.print("current readings 1 ");
      Serial.print(readings1[index1]);
      Serial.print(" average 1 ");
      Serial.println(average1);     
      Serial.print(" diff 1 ");
      Serial.println(diff1); 
      Serial.print(" hires1 ");
 
      }
  /////////////////////////////////////////////////////////////////
  
  // pot 2 execution code block (fader 2) /////////////////////////
  inputpin = 1;  
  midichannel = 2; 
  total2 = total2 - readings2[index2];      
  readings2[index2] = analogRead(inputpin);    
  total2 = total2 + readings2[index2];   
  index2 = index2 + 1;                    
  if (index2 >= numReadings) //reset index to beginning of array
      {  
      index2 = 0;                          
      }  
  average2 = total2 / numReadings;        
  diff2 =  readings2[index2] - average2;
  hires2 = average2 * 16;  
  if ( diff2 > 1 )
      {
      usbMIDI.sendPitchBend(hires2, midichannel); //send hi-res pot data
      Serial.print("current readings 2 ");
      Serial.print(readings2[index2]);
      Serial.print(" average 2 ");
      Serial.println(average2);     
      Serial.print(" diff 2 ");
      Serial.println(diff2); 
      Serial.print(" hires2 ");
      Serial.println(hires2);       
      }
  /////////////////////////////////////////////////////////////////
  
  // pot 3 execution code block (rotary fader 3) //////////////////
  inputpin = 2;  
  midichannel = 3; 
  total3 = total3 - readings3[index3];      
  readings3[index3] = analogRead(inputpin);    
  total3 = total3 + readings3[index3];   
  index3 = index3 + 1;                    
  if (index3 >= numReadings) //reset index to beginning of array
      {  
      index3 = 0;                          
      }  
  average3 = total3 / numReadings;        
  diff3 = readings3[index3] - average3;
  lowres3 = average3 / 8; 
  if ( diff3 > 1 )
      {
      usbMIDI.sendPitchBend(lowres3, midichannel); //send low-res pot data
      Serial.print("current readings 3 ");
      Serial.print(readings3[index3]);
      Serial.print(" average 3 ");
      Serial.println(average3);     
      Serial.print(" diff 3 ");
      Serial.println(diff3); 
      Serial.print(" lowres3 ");
      Serial.println(lowres3);       
      }
  /////////////////////////////////////////////////////////////////
  
  // pot 4 execution code block (rotary fader 4) //////////////////
  inputpin = 3;  
  midichannel = 4; 
  total4 = total4 - readings4[index4];      
  readings4[index4] = analogRead(inputpin);    
  total4 = total4 + readings4[index4];   
  index4 = index4 + 1;                    
  if (index4 >= numReadings) //reset index to beginning of array
      {  
      index4 = 0;                          
      }  
  average4 = total4 / numReadings;        
  diff4 = readings4[index4] - average4;
  lowres4 = average4 / 8;   
  if ( diff4 > 1 )
      {
      usbMIDI.sendPitchBend(lowres4, midichannel); //send low-res pot data  
      Serial.print("current readings 4 ");
      Serial.print(readings4[index4]);
      Serial.print(" average 4 ");
      Serial.println(average4);     
      Serial.print(" diff 4 ");
      Serial.println(diff4);
      Serial.print(" lowres4 ");
      Serial.println(lowres4);          
      }
  /////////////////////////////////////////////////////////////////




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

      


  
}
