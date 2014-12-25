
#include <Bounce.h>
  
#define Left_LED_Blue1 27
#define Left_LED_Blue2 1
#define Left_LED_Red 14
#define Left_LED_Green 0
#define Right_LED_Blue1 15
#define Right_LED_Blue2 26
#define Right_LED_Red 25
#define Right_LED_Green 16
  
  // Pot & fader declarations
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
  
  // Button declarations






// LED declarations
  const int channelbutton = 6;
  pinMode(LeftButtonBlue1, OUTPUT);
  pinMode(LeftButtonBlue2, OUTPUT);
  pinMode(LeftButtonRed, OUTPUT);
  pinMode(LeftButtonGreen, OUTPUT);
  pinMode(RightButtonBlue1, OUTPUT);
  pinMode(RightButtonBlue2, OUTPUT);
  pinMode(RightButtonRed, OUTPUT);
  pinMode(RightButtonGreen, OUTPUT);

  const int redPin =  12;

// Begin main loop
void setup()
  {   
    

    
    

  
  Serial.begin(31250);  // Standard midi rate
  pinMode(6, OUTPUT);   // Internal LED declarations
  
  }

void loop() // Execution loop
  {
  
    digitalWrite(6, 100); //Internal LED
  


  
  // main pot loop
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
 
       
       average[i] = (pintotal[i] / numReadings); // Calculate the average Divide by 8 to make between 0-127
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
    }

    


}
  
    


  



