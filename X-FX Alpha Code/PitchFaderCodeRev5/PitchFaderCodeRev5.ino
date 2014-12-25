

// http://philipcunningham.org
// Smoothing hacked from http://www.arduino.cc/en/Tutorial/Smoothing

const int numReadings = 30; // Smoothing amount
int readings[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
int pots = 1; // The number of pots
int index = 0; // The index of the current reading
int total = 0; // Running total array
int pintotal[6] = {0,0,0,0,0}; // Pin total
int average[6] = {0,0,0,0,0}; // Pin average

// by Bob
unsigned int Converted = 0; // Pin average
int ConvertedLOW = 0; // Pin average
int ConvertedHIGH = 0; // Pin average
int iTEMP = 0; // Temporary Integer variable
// End by Bob

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
    analogWrite(12, 20);
    
  val = analogRead(0);
  Serial.print("analog 0 is: ");
  Serial.println(val);
 
  // Get reading for all potentiometers
  for (int i = 0; i < pots; i++ ) {
    
    // Set index to zero
    index = 0;
    
    // Loop to create average reading
    for (int j = 0; j < numReadings; j++ ){
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
           
   // Calculate the average
   // Divide by 8 to make between 0-127
 average[i] = (pintotal[i]/numReadings)/8;
 Converted =  (pintotal[i]/numReadings) * 16;
   
// ***    Convert 10 bit analog to 14 bits by factoring
  
//Converted =  average[i] * 16; // 16 is the scalingfactor for converting from 10-bit res to 14-bit res

// Split the value into two bytes (actually two low bytes of two ints)
iTEMP =   Converted << 9;  // Temporarily store the converted value with the high 8-bits 'lopped off'
ConvertedLOW =   (unsigned int)iTEMP >> 9; // Move what was in the right byte back into the right byte of the output for LOW
ConvertedHIGH =   Converted >> 7; // Get the original 16-bit variable (14 bits used) and 

//ConvertedHIGH =   127; // Get the original 16-bit variable (14 bits used) and 
//ConvertedLOW =  117; // Move what was in the right byte back into the right byte of the output for LOW

// ***    Split 14-bit value into two INTs for sending 
    
// If reading is different from the previous
   if (lastreading[i] != average[i]){
     
// Send midi data
//   usbMIDI.sendControlChange(i, average[i], channel);
//   usbMIDI.sendControlChange(ConvertedLOW, ConvertedHIGH, channel);
//  usbMIDI.sendControlChange(ConvertedHIGH, ConvertedLOW, channel);
// usbMIDI.sendPitchBend(ConvertedLOW, ConvertedHIGH, 229 );
usbMIDI.sendPitchBend(Converted, 1);
 }
  // Set last array value to current value
lastreading[i] = average[i];
 Serial.print("average i = ");
 Serial.println(average[i]);
  }

  // ******************* Added by Bob ***************************
 Serial.print("Converted Value = ");
 Serial.println(Converted);
 Serial.print("Converted HIGH = ");
 Serial.println(ConvertedHIGH);
 Serial.print("Converted LOW = ");
 Serial.println(ConvertedLOW);

  // Delay output by 5ms
  delay(5);
}
 
 
 
 

  
  
  


