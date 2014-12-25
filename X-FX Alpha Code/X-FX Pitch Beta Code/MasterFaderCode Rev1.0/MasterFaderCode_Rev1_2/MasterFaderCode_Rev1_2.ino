
const int numReadings = 15;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputpin = 0;
int currpotval = 0;
unsigned int diff = 0;
int totalpot = 4;

void setup()
{

  Serial.begin(9600);                  
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    {
    readings[thisReading] = 0;          
    }
}

void loop() 

  {  
    
  for ( int inputpin = 0; inputpin < totalpot; inputpin++ )
      {  
      total= total - readings[index];      
      readings[index] = analogRead(inputpin);    
      total= total + readings[index];   
      currpotval = total;  
      index = index + 1;                    
    
      if (index >= numReadings) 
        {  
        index = 0;                          
        }  
    
      average = total / numReadings;        
      
      delay(20);  
      
      diff =  readings[index] - average;
      
      if (diff > 1)
        {       
           if (inputpin < 2) // Hi-res pots
              {  
              //usbMIDI.sendPitchBend(hires, midichannel); //send hi-res pot data
              // print current data send
              Serial.print("Transmit pitch fader data slide: "); 
              Serial.print(inputpin);
              Serial.print(" value: ");
              Serial.println(average);
              } 
              
           if (inputpin >= 2) // Low-res pots
              {  
              //usbMIDI.sendPitchBend(hires, midichannel); //send hi-res pot data
              // print current data send
              Serial.print("Transmit rotary fader data: "); 
              Serial.print(inputpin);
              Serial.print(" value: ");
              Serial.println(average);
              } 
        } 
          
          
        Serial.print("current readings ");
        Serial.print(readings[index]);
        Serial.print(" average ");
        Serial.println(average); 
        
        Serial.print(" diff ");
        Serial.println(diff); 
        }


  }
