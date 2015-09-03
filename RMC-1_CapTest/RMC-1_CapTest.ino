
const int numReadings = 9; 
int readDelay = 2000;       
int midi_channel_1 = 1;
int readings1[numReadings];     
int myIndex1 = 0;                
int total1 = 0;                 
int average1 = 0;             
int current1 = 0;
int thresh = 1;


int analogPin1 = 1;
int bit1 = 2;
int bit2 = 1;
int bit4 = 0;


void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  
  pinMode(13, OUTPUT);

  for (int thisReading1 = 0; thisReading1 < numReadings; thisReading1++)
    readings1[thisReading1] = 0;    
}


void loop() {
  Frien
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  
  
  total1 = total1 - readings1[myIndex1];
  readings1[myIndex1] = analogRead(analogPin1); 
  delayMicroseconds(readDelay);
  total1= total1 + readings1[myIndex1];       
  myIndex1 = myIndex1 + 1;                    
  if (myIndex1 >= numReadings) myIndex1 = 0;                           
  average1 = (total1 / (numReadings*8));
  if (average1 >= (current1 + thresh) )  {
    usbMIDI.sendControlChange(1, average1, midi_channel_1);
    analogWrite(13, 255);
    Serial.print("   A1: "); 
    Serial.println(average1);    
  }
  else if (average1 <= (current1 - thresh) )  {
    usbMIDI.sendControlChange(1, average1, midi_channel_1);
    analogWrite(13, 255);
    Serial.print("   A1: "); 
    Serial.println(average1);    
  }    
  else {
      analogWrite(13, 0);
  }
  current1 = average1;
  
}
