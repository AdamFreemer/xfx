

// analog input inits
int inputpin = 0;  
const int numReadings = 10; 
int midichannel = 0;

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



void setup()
{

  Serial.begin(57600);  
  
  // initialize all readingsin array to 0 for pot1
  for (int thisReading1 = 0; thisReading1 < numReadings; thisReading1++)
    {
    readings1[thisReading1] = 0;          
    }    
  // initialize all readingsin array to 0 for pot2
  for (int thisReading2 = 0; thisReading2 < numReadings; thisReading2++)
    {
    readings1[thisReading2] = 0;          
    }
  // initialize all readingsin array to 0 for pot3
  for (int thisReading3 = 0; thisReading3 < numReadings; thisReading3++)
    {
    readings1[thisReading3] = 0;          
    }
  // initialize all readingsin array to 0 for pot4
  for (int thisReading4 = 0; thisReading4 < numReadings; thisReading4++)
    {
    readings1[thisReading4] = 0;          
    }

}

void loop() 
  {  
  
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
      Serial.println(hires1); 
      
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
      usbMIDI.sendControlChange(inputpin, lowres3, midichannel); //send low-res pot data
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
      usbMIDI.sendControlChange(inputpin, lowres4, midichannel); //send low-res pot data  
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
  
  
  
  
  
  delay(5);  



}
