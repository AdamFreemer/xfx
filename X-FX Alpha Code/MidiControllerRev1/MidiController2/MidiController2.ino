

// http://philipcunningham.org
// Smoothing hacked from http://www.arduino.cc/en/Tutorial/Smoothing

const int numReadings = 30; // Smoothing amount
int readings[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int pots = 1; // The number of pots
int index = 0; // The index of the current reading
int total = 0; // Running total array
int pintotal[6] = {0,0,0,0,0}; // Pin total
int average[6] = {0,0,0,0,0}; // Pin average
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
  // LED turn on
    analogWrite(12, 20);
    
  val = analogRead(0);
//  Serial.print("analog 0 is: ");
 // Serial.println(val);
 

  
  // Get reading for all potentiometers
//  for (int i = 0; i < pots; i++ ) {
    
    // Set index to zero
    index = 0;
    
    // Loop to create average reading
    for (int j = 0; j < numReadings; j++ ){
      // Subtract the last reading
      total = total - readings[index];
      // Read from the sensor
      readings[index] = analogRead(0);
      // Add the reading to the total
      total = total + readings[index];
      // Advance to the next position in the array
      index = index++;
      pintotal[i] = total;
    }
           
   // Calculate the average
   // Divide by 8 to make between 0-127
   average[i] = (pintotal[i]/numReadings)/8;
   
   // If reading is different from the previous
   if (lastreading[i] != average[i]){
     
         Serial.print("midi send is: ");
  Serial.println(i);
  
     
     
   // Send midi data
   usbMIDI.sendControlChange(i, average[i], channel);
  }
  // Set last array value to current value
  lastreading[i] = average[i];
  }
  // Delay output by 5ms
  delay(5);
  

}
 
 
 
 

  
  
  


