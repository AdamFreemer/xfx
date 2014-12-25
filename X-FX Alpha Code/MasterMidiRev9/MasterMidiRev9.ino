

// Declarations 
const int numReadings = 30; // Smoothing amount
int readings0[numReadings] = {0,0,0,0,0}; int readings1[numReadings] = {0,0,0,0,0}; // Set analog input to 0, pot 1,2
int readings2[numReadings] = {0,0,0,0,0}; int readings3[numReadings] = {0,0,0,0,0}; // Set analog input to 0, pot 3,4
int index0 = 0; int index1 = 0; int index2 = 0; int index3 = 0; // The index of the current reading, pots 1,2,3,4
int total0 = 0; int total1 = 0; int total2 = 0; int total3 = 0; // Running total array, pots 1,2,3,4
int pintotal0[6] = {0,0,0,0,0}; int pintotal1[6] = {0,0,0,0,0}; // Pin total, pots 1,2
int pintotal2[6] = {0,0,0,0,0}; int pintotal3[6] = {0,0,0,0,0}; // Pin total, pots 3,4
int average0[6] = {0,0,0,0,0}; int average1[6] = {0,0,0,0,0}; // Pin average, pots 1,2 
int average2[6] = {0,0,0,0,0}; int average3[6] = {0,0,0,0,0}; // Pin average, pots 3,4
int potnum = 0;
unsigned int midiOut0 = 0; unsigned int midiOut1 = 0; unsigned int midiOut2 = 0; unsigned int midiOut3 = 0;
int midiChan = 0; int midiChan0 = 0; int midiChan1 = 0; int midiChan2 = 0; int midiChan3 = 0; 
int lastreading0[6] = {0,0,0,0,0}; int lastreading1[6] = {0,0,0,0,0}; // Set last readings to 0, pots 1,2 
int lastreading2[6] = {0,0,0,0,0}; int lastreading3[6] = {0,0,0,0,0}; // Set last readings to 0, pots 3,4

void setup()
{                
  Serial.begin(31250);
  pinMode(6, OUTPUT);
 }

void loop()   
    {
    digitalWrite(6, HIGH);
       
// *******************************************************************************  
// Pot 0 : Pitch Fader 1 (L) : MIDI Channel 0 ******************************************** 
      
        index0 = 0;    
    for (int j = 0; j < numReadings; j++ ) // Loop to create average reading

        {
        potnum = 0;
        total0 = total0 - readings0[index0];  // Subtract the last reading
        readings0[index0] = analogRead(potnum);  // Read from the sensor
        total0 = total0 + readings0[index0];  // Add the reading to the total
        index0 = index0++;                  // Advance to the next position in the array
        pintotal0[potnum] = total0;
        }
  
        average0[potnum] = (pintotal0[potnum]/numReadings)/8;             
        midiOut0 =  (pintotal0[potnum] / numReadings) * 16;    // Divide by 8 to make between 0-127   
        midiChan = potnum + 1;
  
    if (lastreading0[potnum] != average0[potnum])
        {
        usbMIDI.sendPitchBend(midiOut0, midiChan);  // Write out to USB
        }
    lastreading0[potnum] = average0[potnum];   // Set last array value to current value


// *******************************************************************************  
// Pot 1 : Pitch Fader 2 (R) : MIDI Channel 1 ******************************************** 
      
        index1 = 0;    
    for (int j = 0; j < numReadings; j++ ) // Loop to create average reading

        {
        potnum = 1;
        total1 = total1 - readings1[index1];  // Subtract the last reading
        readings1[index1] = analogRead(potnum);  // Read from the sensor
        total1 = total1 + readings1[index1];  // Add the reading to the total
        index1 = index1++;                  // Advance to the next position in the array
        pintotal1[potnum] = total1;
        }
   
        average1[potnum] = (pintotal1[potnum]/numReadings)/8;             
        midiOut1 =  (pintotal1[potnum] / numReadings) * 16;    // Divide by 8 to make between 0-127   
        midiChan = potnum + 1;
        
    if (lastreading1[potnum] != average1[potnum])
        {
        usbMIDI.sendPitchBend(midiOut1, midiChan);  // Write out to USB
        }
    lastreading1[potnum] = average1[potnum];   // Set last array value to current value


// ******************************************************************************  
// Pot 2 : Rotary Pot 1 (L) : MIDI Channel 2 ******************************************** 
      
         index2 = 0;   
    for (int j = 0; j < numReadings; j++ ) // Loop to create average reading

        {
        potnum = 2;
        total2 = total2 - readings0[index2];  // Subtract the last reading
        readings2[index2] = analogRead(potnum);  // Read from the sensor
        total2 = total2 + readings2[index2];  // Add the reading to the total
        index2 = index2++;                  // Advance to the next position in the array
        pintotal2[potnum] = total2;
        }
  
        average2[potnum] = (pintotal2[potnum]/numReadings)/8;          
        midiOut2 =  (pintotal2[potnum] / numReadings) / 8;    // Divide by 8 to make between 0-127   
        midiChan = potnum + 1;
        
    if (lastreading2[potnum] != average2[potnum])
        {
        usbMIDI.sendControlChange(1, midiOut2, midiChan);  // Write out to USB
        }
    lastreading2[potnum] = average2[potnum];   // Set last array value to current value
    

// ******************************************************************************  
// Pot 3 : Rotary Pot 2 (R) : MIDI Channel 3 ******************************************** 
      
         index3 = 0;   
    for (int j = 0; j < numReadings; j++ ) // Loop to create average reading

        {
        potnum = 3;
        total0 = total3 - readings3[index3];  // Subtract the last reading
        readings3[index3] = analogRead(potnum);  // Read from the sensor
        total0 = total3 + readings3[index3];  // Add the reading to the total
        index3 = index3++;                  // Advance to the next position in the array
        pintotal3[potnum] = total3;
        }
 
        average3[potnum] = (pintotal3[potnum]/numReadings)/8;              
        midiOut3 =  (pintotal3[potnum] / numReadings) / 8;    // Divide by 8 to make between 0-127   
        midiChan = potnum + 1;
 
    if (lastreading3[potnum] != average3[potnum])
        {
        usbMIDI.sendControlChange(1, midiOut3, midiChan);  // Write out to USB
        }
    lastreading3[potnum] = average3[potnum];   // Set last array value to current value

// ******************************************************************************  

    Serial.print("analog 0 is: ");
    Serial.println(midiOut0);
//    Serial.print("midi out 0 is: ");
//    Serial.println(midiOut0);
    
    Serial.print("analog 1 is: ");
    Serial.println(midiOut1);
//    Serial.print("midi out 1 is: ");
//    Serial.println(midiOut1);

    Serial.print("analog 2 is: ");
    Serial.println(midiOut2);
//    Serial.print("midi out 2 is: ");
//    Serial.println(midiOut2);
    
    Serial.print("analog 3 is: ");
    Serial.println(midiOut3);
//    Serial.print("midi out 3 is: ");
//    Serial.println(midiOut3);


  delay(250); // Delay output by 5ms

}
 

  



