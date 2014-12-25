

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
void setup()
  {                
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
 
    delay(5);  // Delay output by 5ms
}
  
    


  



