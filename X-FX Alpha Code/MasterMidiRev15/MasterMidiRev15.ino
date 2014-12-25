

// Pot declarations 
#include <Bounce.h>
const int numReadings = 5; // Smoothing amount
int readings[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int pots = 4; // The number of pots
int index = 0; // The index of the current reading
int total = 0; // Running total array
int pintotal[6] = {0,0,0,0,0}; // Pin total
int average[6] = {0,0,0,0,0}; // Pin average
int currpotval = 0;
int lowres = 0; // Pin average
int hires = 0; // Pin average
int channel = 1; // Set midi channel to send to 1
int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
int midichannel = 0;


// Button declarations
Bounce button1 = Bounce(1, 5);  // 5 = 5 ms debounce time
Bounce button2 = Bounce(2, 5);  
Bounce button3 = Bounce(3, 5);
Bounce button4 = Bounce(4, 5);
Bounce button5 = Bounce(5, 5);
Bounce button6 = Bounce(6, 5);
Bounce button7 = Bounce(7, 5);
Bounce button8 = Bounce(8, 5);
Bounce button12 = Bounce(12, 5);
Bounce button13 = Bounce(13, 5);
const int channelbutton = 6;

// Begin main loop
void setup()
  {   
  // Button config  
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

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
        currpotval = readings[index];
        
        total = total + readings[index];
        // Advance to the next position in the array
        index = index++;
        pintotal[i] = total;
        }
           
       average[i] = (pintotal[i]/numReadings);    // Calculate the average Divide by 8 to make between 0-127
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
                usbMIDI.sendControlChange(i, lowres, midichannel); //send low-res pot data
                }
            }
       lastreading[i] = average[i];   // Set last array value to current value
    }
    
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.

  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button12.update();
  button13.update();
    

  // falling = high (not pressed - voltage from pullup resistor)
  // to low (pressed - button connects pin to ground)
  if (button12.fallingEdge()) {
    usbMIDI.sendNoteOn(60, 99, channelbutton);  // 60 = C4
    Serial.println("pin 12 - falling");
  }
  if (button13.fallingEdge()) {
    usbMIDI.sendNoteOn(61, 99, channelbutton);  // 61 = C#4
        Serial.println("pin 13 - falling");
  }  
    
    
    
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button12.risingEdge()) {
    usbMIDI.sendNoteOff(60, 0, channelbutton);  // 60 = C4
        Serial.println("pin 12 - rising");
  }
  if (button13.risingEdge()) {
    usbMIDI.sendNoteOff(61, 0, channelbutton);  // 61 = C#4
        Serial.println("pin 13 - rising");
  }
    
    
    
 
    delay(5);  // Delay output by 5ms
}
  
    


  



