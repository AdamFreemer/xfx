


const int numReadings = 30; // Smoothing amount
int readings[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int pots = 2; // The number of pots
int index = 0; // The index of the current reading
int total = 0; // Running total array
int pintotal[6] = {0,0,0,0,0}; // Pin total
int average[6] = {0,0,0,0,0}; // Pin average
unsigned int Converted = 0; // Pin average
int iTEMP = 0; // Temporary Integer variable
int channel = 1; // Set midi channel to send to 1
int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
int val;

void setup()
{                
  Serial.begin(31250);
   pinMode(12, OUTPUT);
}

void loop()
{
  val = analogRead(0);
  Serial.print("analog 0 is: ");
  Serial.println(val);
 
  for (int i = 0; i < pots; i++ ) {  // Get reading for all potentiometers
  index = 0; // Set index to zero
  for (int j = 0; j < numReadings; j++ ) // Loop to create average reading
        {
        total = total - readings[index];  // Subtract the last reading
        readings[index] = analogRead(i);  // Read from the sensor
        total = total + readings[index];  // Add the reading to the total
        index = index++;                  // Advance to the next position in the array
        pintotal[i] = total;
        }
           
  average[i] = (pintotal[i]/numReadings)/8;    // Calculate the average
  Converted =  (pintotal[i]/numReadings) * 16;    // Divide by 8 to make between 0-127
   

  if (lastreading[i] != average[i])
        {
        usbMIDI.sendPitchBend(Converted, 1);
        }
  // Set last array value to current value
lastreading[i] = average[i];
 Serial.print("average i = ");
 Serial.println(average[i]);
  }



  // Delay output by 5ms
  delay(5);
}
 
 
 
 

  
  
  


