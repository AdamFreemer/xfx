

// Declarations for HI Res POTs
const int numReadings = 30; // Smoothing amount
int readings[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int pots = 2; // The number of pots
int index = 0; // The index of the current reading
int total = 0; // Running total array
int pintotal[6] = {0,0,0,0,0}; // Pin total
int average[6] = {0,0,0,0,0}; // Pin average
unsigned int Converted = 0; // Pin average
int channel = 1; // Set midi channel to send to 1
int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
int val;


// Declarations for LowResPots
boolean LowResPots = true; // Make TRUE if you add two low=res pots
int NumOfLowResPots = 2; // If we have LowResPots, here's the number of them

const int LRPnumReadings = 30; // Smoothing amount
int LRPreadings[LRPnumReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int LRP_index = 0; // The index of the current reading
int LRP_total = 0; // Running total array
int LRP_lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
int LRP_pintotal[6] = {0,0,0,0,0}; // Pin total
int LRP_average[6] = {0,0,0,0,0}; // Pin average

void setup()
{                
  Serial.begin(31250);
  pinMode(6, OUTPUT);
 }

void loop()    //  MAIN PROGRAM LOOP
{
  val = analogRead(0);
  Serial.print("analog 0 is: ");
  Serial.println(val);
 
digitalWrite(6, HIGH);
 
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
        usbMIDI.sendPitchBend(Converted, i);
        }
  // Set last array value to current value
lastreading[i] = average[i];
 Serial.print("average i = ");
 Serial.println(average[i]);
  Serial.print("Channel i = ");
 Serial.println(i);
  }


// *******************************************************************************  
// *******************************************************************************  
  

if  (LowResPots) {    /// Code only executes if there are any 0-127 (Low Res) Pots
  delay(5);
  for (int i = 2; i < (NumOfLowResPots + 2); i++ ) {  // Get reading for the Low-res potentiometers
  LRP_index = 0; // Set index to zero
  for (int j = 0; j < LRPnumReadings; j++ ) // Loop to create average reading
        {
        LRP_total = LRP_total - LRPreadings[ LRP_index];  // Subtract the last reading
        LRPreadings[LRP_index] = analogRead(i);  // Read from the sensor
        LRP_total = LRP_total + LRPreadings[ LRP_index];  // Add the reading to the total
        LRP_index = LRP_index++;                  // Advance to the next position in the array
        LRP_pintotal[i] = LRP_total;
        }
           
  LRP_average[i] = (LRP_pintotal[i]/LRPnumReadings)/8;    // Calculate the average
 
  if (LRP_lastreading[i] != LRP_average[i])
        {
        usbMIDI.sendControlChange(1, LRP_average[i], i);  // Write out to USB
        }
  // Set last array value to current value
LRP_lastreading[i] = LRP_average[i];
 Serial.print("LRP_average i = ");
 Serial.println(LRP_average[i]);
  Serial.print("Channel i = ");
 Serial.println(i);
 }

}


// Delay output by 5ms
  delay(5);


}
 

  
  



