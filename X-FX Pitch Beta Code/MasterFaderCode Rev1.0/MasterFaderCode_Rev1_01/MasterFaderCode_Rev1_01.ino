
// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 15;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputPin = 0;
int currpotval = 0;
unsigned int diff = 0;

void setup()
{
  // initialize serial communication with computer:
  Serial.begin(9600);                  
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;          
}

void loop() 

  {  
  total= total - readings[index];      
  readings[index] = analogRead(inputPin);    
  total= total + readings[index];   
  currpotval = total;  
  index = index + 1;                    

  if (index >= numReadings) // if we're at the end of the array... 
      {  
      index = 0;                          
      }  

  average = total / numReadings;        
  
  delay(20);  
  
  diff =  readings[index] - average;
  
  if (diff > 1 )
  {
  Serial.print("current readings ");
  Serial.print(readings[index]);
  Serial.print(" average ");
  Serial.println(average); 
  
  Serial.print(" diff ");
  Serial.println(diff); 
  
  }
  



}
