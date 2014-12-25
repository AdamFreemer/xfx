

// Declarations 
const int numReadings = 30; // Smoothing amount
int readings[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int pots = 4; // The number of pots
int index = 0; // The index of the current reading
int total = 0; // Running total array
int pintotal[6] = {0,0,0,0,0}; // Pin total
int average[6] = {0,0,0,0,0}; // Pin average
int channel = 1; // Set midi channel to send to 1
int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
int midichannel = 0;
unsigned int converted = 0; 

// Button Declarations
byte previousState1 = HIGH;         // what state was the button last time
unsigned int count1 = 0;            // how many times has it changed to low
unsigned long countAt1 = 0;         // when count changed
unsigned int countPrinted1 = 0;     // last count printed

byte previousState2 = HIGH;         // what state was the button last time
unsigned int count2 = 0;            // how many times has it changed to low
unsigned long countAt2 = 0;         // when count changed
unsigned int countPrinted2 = 0;     // last count printed

#include <Bounce.h>

const int buttonPin1 = 12;
const int buttonPin2 = 13;
Bounce pushbutton1 = Bounce(buttonPin1, 10);  // 10 ms debounce
Bounce pushbutton2 = Bounce(buttonPin2, 10);  // 10 ms debounce

void setup()
  {     

  pinMode(buttonPin1, INPUT_PULLUP); // Button test
  pinMode(buttonPin2, INPUT_PULLUP); // Button test
  
  Serial.begin(31250);   // Standard midi rate
  pinMode(6, OUTPUT);
  }

void loop()
  {
  digitalWrite(6, HIGH);
  
  for (int i = 0; i < pots; i++ )  // Get reading for all potentiometers
    {
    index = 0;  // Set index to zero
    
    for (int j = 0; j < numReadings; j++ )  // Loop to create average reading
        {
        // Subtract the last reading
        total = total - readings[index];
        // Read from the sensor
        readings[index] = analogRead(i);
        // Add the reading to the total
        total = total + readings[index];
        // Advance to the next position in the array
        index = index++;
        pintotal[i] = total;
        }
           
       average[i] = (pintotal[i]/numReadings) / 8;    // Calculate the average Divide by 8 to make between 0-127
       converted = (pintotal[i]/numReadings) * 16;
       midichannel = i + 1;       
       if (lastreading[i] != average[i]) // If reading is different from the previous
            { 
            if (i < 2) // Hi-res pots
                {
                usbMIDI.sendPitchBend(converted, midichannel); //send hi-res pot data
                }  
            if (i >= 2)  
                {
                usbMIDI.sendControlChange(i, average[i], midichannel); //send low-res pot data
                }
            }
       lastreading[i] = average[i];   // Set last array value to current value
    }
    
    
    
    
    
    
    
    
    
    // Button 1 Code
    if (pushbutton1.update() ) 
        {
        if (pushbutton1.fallingEdge()) 
           {
           count1 = count1 + 1;
           countAt1 = millis();
           }
        } 
    else 
        {
        if (count1 != countPrinted1) 
           {
           unsigned long nowMillis = millis();
           if (nowMillis - countAt1 > 100) 
                  {
                  Serial.print("count 1: ");
                  Serial.println(count1);
                  countPrinted1 = count1;
                  }
            }
        }

  
  
      
    
    
    
    // Button 2 Code
    if (pushbutton2.update() ) 
        {
        if (pushbutton2.fallingEdge()) 
           {
           count2 = count2 + 1;
           countAt2 = millis();
           }
        } 
    else 
        {
        if (count2 != countPrinted2) 
           {
           unsigned long nowMillis = millis();
           if (nowMillis - countAt2 > 100) 
                  {
                  Serial.print("count 2: ");
                  Serial.println(count2);
                  countPrinted2 = count2;
                  }
            }
        }

    
    
    
    
    
    
 
    delay(5);  // Delay output by 5ms
}
  
    


  



