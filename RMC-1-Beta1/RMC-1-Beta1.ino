#include <MIDI.h>


//////**** RMC-1 Rev0 Beta5 ********//////    
//////**** September 18th, 2015 ****//////  
//////**** By Adam Freemer ***//////

const int numReadings = 13; // This adjusts the number of array samples, 5 is low, 10 is on the high side
int readDelay = 100;       // This is the delay in microseconds before the an analog pin reads from the multiplexer

int bit1 = 2;
int bit2 = 1;
int bit4 = 0;
int analogPin0 = 0;
int analogPin1 = 1;
int analogPin2 = 2;
int analogPin3 = 3;
int select1 = 0;
int select2 = 0;
int select3 = 0;
int select4 = 0;
int selection = 0;
int midi_channel_1 = 1;
int midi_channel_2 = 2;

////// ONE //////////////////

int readings1[numReadings];     
int myIndex1 = 0;                
int total1 = 0;                 
int average1 = 0;             
int current1 = 0;

int readings2[numReadings];     
int myIndex2 = 0;                  
int total2 = 0;                
int average2 = 0;               
int current2 = 0;

int readings3[numReadings];  
int myIndex3 = 0;            
int total3 = 0;                
int average3 = 0;        
int current3 = 0;

int readings4[numReadings];  
int myIndex4 = 0;                
int total4 = 0;          
int average4 = 0;    
int current4 = 0;

////////////////////////////

////// TWO //////////////////

int readings5[numReadings];     
int myIndex5 = 0;                
int total5 = 0;                 
int average5 = 0;             
int current5 = 0;

int readings6[numReadings];     
int myIndex6 = 0;                  
int total6 = 0;                
int average6 = 0;               
int current6 = 0;

int readings7[numReadings];  
int myIndex7 = 0;            
int total7 = 0;                
int average7 = 0;        
int current7 = 0;

int readings8[numReadings];  
int myIndex8 = 0;                
int total8 = 0;          
int average8 = 0;    
int current8 = 0;

////////////////////////////

////// THREE //////////////////

int readings9[numReadings];     
int myIndex9 = 0;                
int total9 = 0;                 
int average9 = 0;             
int current9 = 0;

int readings10[numReadings];     
int myIndex10 = 0;                  
int total10 = 0;                
int average10 = 0;               
int current10 = 0;

int readings11[numReadings];  
int myIndex11 = 0;            
int total11 = 0;                
int average11 = 0;        
int current11 = 0;

int readings12[numReadings];  
int myIndex12 = 0;                
int total12 = 0;          
int average12 = 0;    
int current12 = 0;

////////////////////////////

////// FOUR //////////////////

int readings13[numReadings];     
int myIndex13 = 0;                
int total13 = 0;                 
int average13 = 0;             
int current13 = 0;

int readings14[numReadings];     
int myIndex14 = 0;                  
int total14 = 0;                
int average14 = 0;               
int current14 = 0;

int readings15[numReadings];  
int myIndex15 = 0;            
int total15 = 0;                
int average15 = 0;        
int current15 = 0;

int readings16[numReadings];  
int myIndex16 = 0;                
int total16 = 0;          
int average16 = 0;    
int current16 = 0;

////////////////////////////

////// CHANNELS ////////////

int readings17[numReadings];     
int myIndex17 = 0;                
int total17 = 0;                 
int average17 = 0;             
int current17 = 0;

int readings18[numReadings];     
int myIndex18 = 0;                  
int total18 = 0;                
int average18 = 0;               
int current18 = 0;

int readings19[numReadings];  
int myIndex19 = 0;            
int total19 = 0;                
int average19 = 0;        
int current19 = 0;


int readings20[numReadings];  
int myIndex20 = 0;                
int total20 = 0;          
int average20 = 0;    
int current20 = 0;

////////////////////////////

////// OUTPUTS ////////?////

int readings21[numReadings];     
int myIndex21 = 0;                
int total21 = 0;                 
int average21 = 0;             
int current21 = 0;

int readings22[numReadings];     
int myIndex22 = 0;                  
int total22 = 0;                
int average22 = 0;               
int current22 = 0;

int readings23[numReadings];  
int myIndex23 = 0;            
int total23 = 0;                
int average23 = 0;        
int current23 = 0;

int readings24[numReadings];  
int myIndex24 = 0;                
int total24 = 0;          
int average24 = 0;    
int current24 = 0;

////////////////////////////

////// TOP ROW ////////?////

int readings25[numReadings];     
int myIndex25 = 0;                
int total25 = 0;                 
int average25 = 0;             
int current25 = 0;

int readings26[numReadings];     
int myIndex26 = 0;                  
int total26 = 0;                
int average26 = 0;               
int current26 = 0;

int readings27[numReadings];  
int myIndex27 = 0;            
int total27 = 0;                
int average27 = 0;        
int current27 = 0;

int readings28[numReadings];  
int myIndex28 = 0;                
int total28 = 0;          
int average28 = 0;    
int current28 = 0;

////////////////////////////

void setup()
{
  // initialize serial communication with computer:
  Serial.begin(57600);
  
  // Digital bus initialize  
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);  
  
  
  
  ////// ONE //////////////////
  
  // initialize all the readings to 0: Pot 1
  for (int thisReading1 = 0; thisReading1 < numReadings; thisReading1++)
    readings1[thisReading1] = 0;    
    
  // initialize all the readings to 0: Pot 2
  for (int thisReading2 = 0; thisReading2 < numReadings; thisReading2++)
    readings2[thisReading2] = 0;      

  // initialize all the readings to 0: Pot 3
  for (int thisReading3 = 0; thisReading3 < numReadings; thisReading3++)
    readings3[thisReading3] = 0;      

  // initialize all the readings to 0: Pot 4
  for (int thisReading4 = 0; thisReading4 < numReadings; thisReading4++)
    readings4[thisReading4] = 0;  

  ////// TWO //////////////////
  
  // initialize all the readings to 0: Pot 5
  for (int thisReading5 = 0; thisReading5 < numReadings; thisReading5++)
    readings6[thisReading5] = 0;    
    
  // initialize all the readings to 0: Pot 6
  for (int thisReading6 = 0; thisReading6 < numReadings; thisReading6++)
    readings6[thisReading6] = 0;      

  // initialize all the readings to 0: Pot 7
  for (int thisReading7 = 0; thisReading7 < numReadings; thisReading7++)
    readings7[thisReading7] = 0;      

  // initialize all the readings to 0: Pot 8
  for (int thisReading8 = 0; thisReading8 < numReadings; thisReading8++)
    readings8[thisReading8] = 0;  

  ////// THREE //////////////////
  
  // initialize all the readings to 0: Pot 9
  for (int thisReading9 = 0; thisReading9 < numReadings; thisReading9++)
    readings9[thisReading9] = 0;    
    
  // initialize all the readings to 0: Pot 10
  for (int thisReading10 = 0; thisReading10 < numReadings; thisReading10++)
    readings10[thisReading10] = 0;      

  // initialize all the readings to 0: Pot 11
  for (int thisReading11 = 0; thisReading11 < numReadings; thisReading11++)
    readings11[thisReading11] = 0;      

  // initialize all the readings to 0: Pot 12
  for (int thisReading12 = 0; thisReading12 < numReadings; thisReading12++)
    readings12[thisReading12] = 0;  

  ////// FOUR //////////////////
  
  // initialize all the readings to 0: Pot 13
  for (int thisReading13 = 0; thisReading13 < numReadings; thisReading13++)
    readings13[thisReading13] = 0;    
    
  // initialize all the readings to 0: Pot 14
  for (int thisReading14 = 0; thisReading14 < numReadings; thisReading14++)
    readings14[thisReading14] = 0;      

  // initialize all the readings to 0: Pot 15
  for (int thisReading15 = 0; thisReading15 < numReadings; thisReading15++)
    readings15[thisReading15] = 0;      

  // initialize all the readings to 0: Pot 16
  for (int thisReading16 = 0; thisReading16 < numReadings; thisReading16++)
    readings15[thisReading16] = 0;  

  ////// CHANNELS //////////////////
  
  // initialize all the readings to 0: Pot 17
  for (int thisReading17 = 0; thisReading17 < numReadings; thisReading17++)
    readings17[thisReading17] = 0;    
    
  // initialize all the readings to 0: Pot 18
  for (int thisReading18 = 0; thisReading18 < numReadings; thisReading18++)
    readings18[thisReading18] = 0;      

  // initialize all the readings to 0: Pot 19
  for (int thisReading19 = 0; thisReading19 < numReadings; thisReading19++)
    readings19[thisReading19] = 0;      

  // initialize all the readings to 0: Pot 20
  for (int thisReading20 = 0; thisReading20 < numReadings; thisReading20++)
    readings20[thisReading20] = 0;  
  
  ////// OUTPUTS //////////////////
  
  // initialize all the readings to 0: Pot 21
  for (int thisReading21 = 0; thisReading21 < numReadings; thisReading21++)
    readings21[thisReading21] = 0;    
    
  // initialize all the readings to 0: Pot 22
  for (int thisReading22 = 0; thisReading22 < numReadings; thisReading22++)
    readings22[thisReading22] = 0;      

  // initialize all the readings to 0: Pot 23
  for (int thisReading23 = 0; thisReading23 < numReadings; thisReading23++)
    readings23[thisReading23] = 0;      

  // initialize all the readings to 0: Pot 24
  for (int thisReading24 = 0; thisReading24 < numReadings; thisReading24++)
    readings24[thisReading24] = 0;  
  
  ////// TOP ROW //////////////////
  
  // initialize all the readings to 0: Pot 25
  for (int thisReading25 = 0; thisReading25 < numReadings; thisReading25++)
    readings25[thisReading25] = 0;    
    
  // initialize all the readings to 0: Pot 26
  for (int thisReading26 = 0; thisReading26 < numReadings; thisReading26++)
    readings26[thisReading26] = 0;      

  // initialize all the readings to 0: Pot 27
  for (int thisReading27 = 0; thisReading27 < numReadings; thisReading27++)
    readings27[thisReading27] = 0;      

  // initialize all the readings to 0: Pot 28
  for (int thisReading28 = 0; thisReading28 < numReadings; thisReading28++)
    readings28[thisReading28] = 0;     
}

void loop() {
  
  Serial.print("Select: "); 
  Serial.print(select1); 
  Serial.print(select2); 
  Serial.print(select3); 
  Serial.print(select4); 

  Serial.print("   A1: "); 
  Serial.print(average1);  
  Serial.print(" A2: "); 
  Serial.print(average2); 
  Serial.print(" A3: "); 
  Serial.print(average3);  
  Serial.print(" A4: "); 
  Serial.print(average4);  

  Serial.print("   A5: "); 
  Serial.print(average5);  
  Serial.print(" A6: "); 
  Serial.print(average6); 
  Serial.print(" A7: "); 
  Serial.print(average7);  
  Serial.print(" A8: "); 
  Serial.print(average8); 
  
  Serial.print("   A9: "); 
  Serial.print(average9);  
  Serial.print(" A10: "); 
  Serial.print(average10); 
  Serial.print(" A11: "); 
  Serial.print(average11);  
  Serial.print(" A12: "); 
  Serial.print(average12); 

  Serial.print("    A13: "); 
  Serial.print(average13);  
  Serial.print(" A14: "); 
  Serial.print(average14); 
  Serial.print(" A15: "); 
  Serial.print(average15);  
  Serial.print(" A16: xx"); 

  
  Serial.print("    A17: "); 
  Serial.print(average17);  
  Serial.print(" A18: "); 
  Serial.print(average18); 
  Serial.print(" A19: "); 
  Serial.print(average19);  
  Serial.print(" A20: "); 
  Serial.print(average20);  
  
  Serial.print("    A21: "); 
  Serial.print(average21);  
  Serial.print(" A22: "); 
  Serial.print(average22); 
  Serial.print(" A23: "); 
  Serial.print(average23);  
  Serial.print(" A24: "); 
  Serial.print(average24);  
  
  Serial.print("    A25: "); 
  Serial.print(average25);  
  Serial.print(" A26: "); 
  Serial.print(average26); 
  Serial.print(" A27: "); 
  Serial.print(average27);  
  Serial.print(" A28: "); 
  Serial.println(average28);  
  
  ///// SELECT KNOB ///////////////////////////
  select1 = digitalRead(20);
  select2 = digitalRead(21);
  select3 = digitalRead(22);
  select4 = digitalRead(23);
  
  if ((select1 == LOW) && (select2 == HIGH) && (select3 == HIGH) && (select4 == HIGH)) {
    usbMIDI.sendNoteOn(60, 99, 3);
    usbMIDI.sendNoteOff(61, 0, 3);
    usbMIDI.sendNoteOff(62, 0, 3);
    usbMIDI.sendNoteOff(63, 0, 3);
    selection = 1;
  } 
  if ((select1 == HIGH) && (select2 == LOW) && (select3 == HIGH) && (select4 == HIGH)) {
    usbMIDI.sendNoteOff(60, 0, 3);
    usbMIDI.sendNoteOn(61, 99, 3);
    usbMIDI.sendNoteOff(62, 0, 3);
    usbMIDI.sendNoteOff(63, 0, 3);
    selection = 2;
  }
  if ((select1 == HIGH) && (select2 == HIGH) && (select3 == LOW) && (select4 == HIGH)) {
    usbMIDI.sendNoteOff(60, 0, 3);
    usbMIDI.sendNoteOff(61, 0, 3);
    usbMIDI.sendNoteOn(62, 99, 3);
    usbMIDI.sendNoteOff(63, 0, 3);
    selection = 3;
  }
  if ((select1 == HIGH) && (select2 == HIGH) && (select3 == HIGH) && (select4 == LOW)) {
    usbMIDI.sendNoteOff(60, 0, 3);
    usbMIDI.sendNoteOff(61, 0, 3);
    usbMIDI.sendNoteOff(62, 0, 3);
    usbMIDI.sendNoteOn(63, 99, 3);
    selection = 4;
  }
 
  ///////////////////////////////////////////////  
  
  
  
  ///// COLUMN ONE /////////////////////////////////
  
  ///// HIGH //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total1 = total1 - readings1[myIndex1];   
  readings1[myIndex1] = analogRead(analogPin1); 
  total1= total1 + readings1[myIndex1];       
  myIndex1 = myIndex1 + 1;                    
  if (myIndex1 >= numReadings) myIndex1 = 0;                           
  average1 = (total1 / (numReadings*8)); 
  if ((average1 != current1)) {
    usbMIDI.sendControlChange(1, average1, midi_channel_1);
  }
  current1 = average1;
  
  ///// MID //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total2 = total2 - readings2[myIndex2];   
  readings2[myIndex2] = analogRead(analogPin1); 
  total2 = total2 + readings2[myIndex2];       
  myIndex2 = myIndex2 + 1;                    
  if (myIndex2 >= numReadings) myIndex2 = 0;                           
  average2 = (total2 / (numReadings*8)); 
  if ((average2 != current2) && (average2 > 64) && (average2 < 63)) {
    usbMIDI.sendControlChange(2, average2, midi_channel_1);
  }
  current2 = average2;
    
  ///// LOW //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total3 = total3 - readings3[myIndex3];   
  readings3[myIndex3] = analogRead(analogPin1); 
  total3 = total3 + readings3[myIndex3];       
  myIndex3 = myIndex3 + 1;                    
  if (myIndex3 >= numReadings) myIndex3 = 0;                           
  average3 = (total3 / (numReadings*8)); 
  if ((average3 != current3) && (average3 > 64) && (average3 < 63)) {
    usbMIDI.sendControlChange(3, average3, midi_channel_1);
  }
  current3 = average3;
    
  ///// FILTER //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total4 = total4 - readings4[myIndex4];   
  readings4[myIndex4] = analogRead(analogPin1); 
  total4 = total4 + readings4[myIndex4];       
  myIndex4 = myIndex4 + 1;                    
  if (myIndex4 >= numReadings) myIndex4 = 0;                           
  average4 = (total4 / (numReadings*8)); 
  if ((average4 != current4) && (average4 > 64) && (average4 < 63)) {
    usbMIDI.sendControlChange(4, average4, midi_channel_1);
  }
  current4 = average4;
  
  ///////////////////////////////////////////////
    

  ///// COLUMN TWO /////////////////////////////////
  
  ///// HIGH //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total5 = total5 - readings5[myIndex5];   
  readings5[myIndex5] = analogRead(analogPin1); 
  total5 = total5 + readings5[myIndex5];       
  myIndex5 = myIndex5 + 1;                    
  if (myIndex5 >= numReadings) myIndex5 = 0;                           
  average5 = (total5 / (numReadings*8)); 
  if ((average1 != current1) && (average1 > 64) && (average1 < 63)) {
    usbMIDI.sendControlChange(5, average5, midi_channel_1);
  }
  current5 = average5;
  
  ///// MID //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total6 = total6 - readings6[myIndex6];   
  readings6[myIndex6] = analogRead(analogPin1); 
  total6 = total6 + readings6[myIndex6];       
  myIndex6 = myIndex6 + 1;                    
  if (myIndex6 >= numReadings) myIndex6 = 0;                           
  average6 = (total6 / (numReadings*8)); 
  if ((average6 != current6) && (average6 > 64) && (average6 < 63)) {
    usbMIDI.sendControlChange(6, average6, midi_channel_1);
  }
  current6 = average6;
    
  ///// LOW //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total7 = total7 - readings7[myIndex7];   
  readings7[myIndex7] = analogRead(analogPin1); 
  total7 = total7 + readings7[myIndex7];       
  myIndex7 = myIndex7 + 1;                    
  if (myIndex7 >= numReadings) myIndex7 = 0;                           
  average7 = (total7 / (numReadings*8)); 
  if ((average7 != current7) && (average7 > 64) && (average7 < 63)) {
    usbMIDI.sendControlChange(7, average7, midi_channel_1);
  }
  current7 = average7;
    
  ///// FILTER //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total8 = total8 - readings8[myIndex8];   
  readings8[myIndex8] = analogRead(analogPin1); 
  total8 = total8 + readings8[myIndex8];       
  myIndex8 = myIndex8 + 1;                    
  if (myIndex8 >= numReadings) myIndex8 = 0;                           
  average8 = (total8 / (numReadings*8)); 
  if ((average8 != current8) && (average8 > 64) && (average8 < 63)) {
    usbMIDI.sendControlChange(8, average8, midi_channel_1);
  }
  current8 = average8;
  
  ///////////////////////////////////////////////    
    
    
    
  ///// COLUMN THREE /////////////////////////////////
  
  ///// HIGH //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total9 = total9 - readings9[myIndex9];   
  readings9[myIndex9] = analogRead(analogPin0); 
  total9 = total9 + readings9[myIndex9];       
  myIndex9 = myIndex9 + 1;                    
  if (myIndex9 >= numReadings) myIndex9 = 0;                           
  average9 = (total9 / (numReadings*8)); 
  if ((average9 != current9) && (average9 > 64) && (average9 < 63)) {
    usbMIDI.sendControlChange(9, average9, midi_channel_1);
  }
  current9 = average9;
  
  ///// MID //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total10 = total10 - readings10[myIndex10];   
  readings10[myIndex10] = analogRead(analogPin0); 
  total10 = total10 + readings10[myIndex10];       
  myIndex10 = myIndex10 + 1;                    
  if (myIndex10 >= numReadings) myIndex10 = 0;                           
  average10 = (total10 / (numReadings*8)); 
  if ((average10 != current10) && (average10 > 64) && (average10 < 63)) {
    usbMIDI.sendControlChange(10, average10, midi_channel_1);
  }
  current10 = average10;
  
  ///// LOW //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total11 = total11 - readings11[myIndex11];   
  readings11[myIndex11] = analogRead(analogPin0); 
  total11 = total11 + readings11[myIndex11];       
  myIndex11 = myIndex11 + 1;                    
  if (myIndex11 >= numReadings) myIndex11 = 0;                           
  average11 = (total11 / (numReadings*8)); 
  if ((average11 != current11) && (average11 > 64) && (average11 < 63)) {
    usbMIDI.sendControlChange(11, average11, midi_channel_1);
  }
  current11 = average11;
  
  ///// FILTER //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total12 = total12 - readings12[myIndex12];   
  readings12[myIndex12] = analogRead(analogPin0); 
  total12 = total12 + readings12[myIndex12];       
  myIndex12 = myIndex12 + 1;                    
  if (myIndex12 >= numReadings) myIndex12 = 0;                           
  average12 = (total12 / (numReadings*8)); 
  if ((average12 != current12) && (average12 > 64) && (average12 < 63)) {
    usbMIDI.sendControlChange(12, average12, midi_channel_1);
  }
  current12 = average12;
  
  ///////////////////////////////////////////////
    

  ///// OUTPUTS /////////////////////////////////
  
  ///// AUX 2 //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total13 = total13 - readings13[myIndex13];   
  readings13[myIndex13] = analogRead(analogPin0); 
  total13= total13 + readings13[myIndex13];       
  myIndex13 = myIndex13 + 1;                    
  if (myIndex13 >= numReadings) myIndex13 = 0;                           
  average13 = (total13 / (numReadings*8)); 
  if (average13 != current13) {
    usbMIDI.sendControlChange(13, average13, midi_channel_1);
  }
  current13 = average13;
  
  ///// AUX 1 //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total14 = total14 - readings14[myIndex14];   
  readings14[myIndex14] = analogRead(analogPin0); 
  total14 = total14 + readings14[myIndex14];       
  myIndex14 = myIndex14 + 1;                    
  if (myIndex14 >= numReadings) myIndex14 = 0;                           
  average14 = (total14 / (numReadings*8)); 
  if (average14 != current14) {
    usbMIDI.sendControlChange(14, average14, midi_channel_1);
  }
  current14 = average14;
  
  ///// HEADPHONE //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total15 = total15 - readings15[myIndex15];   
  readings15[myIndex15] = analogRead(analogPin0); 
  total15 = total15 + readings15[myIndex15];       
  myIndex15 = myIndex15 + 1;                    
  if (myIndex15 >= numReadings) myIndex15 = 0;                           
  average15 = (total15 / (numReadings*8)); 
  if (average15 != current15) {
    usbMIDI.sendControlChange(15, average15, midi_channel_1);
  }
  current15 = average15;
  
  ///// UNUSED //////
//  digitalWrite(bit1, HIGH);
//  digitalWrite(bit2, HIGH);
//  digitalWrite(bit4, HIGH);
//  delayMicroseconds(readDelay);
//  total16 = total16 - readings16[myIndex16];   
//  readings16[myIndex16] = analogRead(analogPin0); 
//  total16 = total16 + readings16[myIndex16];       
//  myIndex16 = myIndex16 + 1;                    
//  if (myIndex16 >= numReadings) myIndex16 = 0;                           
//  average16 = (total16 / (numReadings*8)); 
//  if (average16 != current16) {
//    usbMIDI.sendControlChange(16, average16, midi_channel_1);
//  }
//  current16 = average16;
//  
  ///////////////////////////////////////////////        
    
    
    
   
  ///// COLUMN 4 /////////////////////////////////
  
  ///// ONE //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total17 = total17 - readings17[myIndex17];   
  readings17[myIndex17] = analogRead(analogPin2); 
  total17 = total17 + readings17[myIndex17];       
  myIndex17 = myIndex17 + 1;                    
  if (myIndex17 >= numReadings) myIndex17 = 0;                           
  average17 = (total17 / (numReadings*8)); 
  if ((average17 != current17) && (average17 > 64) && (average17 < 63)) {
    usbMIDI.sendControlChange(17, average17, midi_channel_1);
  }
  current17 = average17;
  
  ///// TWO //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total18 = total18 - readings18[myIndex18];   
  readings18[myIndex18] = analogRead(analogPin2); 
  total18 = total18 + readings18[myIndex18];       
  myIndex18 = myIndex18 + 1;                    
  if (myIndex18 >= numReadings) myIndex18 = 0;                           
  average18 = (total18 / (numReadings*8)); 
  if ((average18 != current18) && (average18 > 64) && (average18 < 63)) {
    usbMIDI.sendControlChange(18, average18, midi_channel_1);
  }
  current18 = average18;
  
  ///// THREE //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total19 = total19 - readings19[myIndex19];   
  readings19[myIndex19] = analogRead(analogPin2); 
  total19 = total19 + readings19[myIndex19];       
  myIndex19 = myIndex19 + 1;                    
  if (myIndex19 >= numReadings) myIndex19 = 0;                           
  average19 = (total19 / (numReadings*8)); 
  if ((average19 != current19) && (average19 > 64) && (average19 < 63)) {
    usbMIDI.sendControlChange(19, average19, midi_channel_1);
  }
  current19 = average19;
  
  ///// FOUR //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total20 = total20 - readings20[myIndex20];   
  readings20[myIndex20] = analogRead(analogPin2); 
  total20 = total20 + readings20[myIndex20];       
  myIndex20 = myIndex20 + 1;                    
  if (myIndex20 >= numReadings) myIndex20 = 0;                           
  average20 = (total20 / (numReadings*8)); 
  if ((average20 != current20) && (average20 > 64) && (average20 < 63)) {
    usbMIDI.sendControlChange(20, average20, midi_channel_1);
  }
  current20 = average20;
  
  ///////////////////////////////////////////////
    
    


  ///// CHANNEL KNOBS /////////////////////////////////
  
  ///// 1 //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total21 = total21 - readings21[myIndex21];   
  readings21[myIndex21] = analogRead(analogPin2); 
  total21 = total21 + readings21[myIndex21];       
  myIndex21 = myIndex21 + 1;                    
  if (myIndex21 >= numReadings) myIndex21 = 0;                           
  average21 = (total21 / (numReadings*8)); 
  if (average21 != current21) {
    usbMIDI.sendControlChange(21, average21, midi_channel_1);
  }
  current21 = average21;
  
  ///// 2 //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total22 = total22 - readings22[myIndex22];   
  readings22[myIndex22] = analogRead(analogPin2); 
  total22 = total22 + readings22[myIndex22];       
  myIndex22 = myIndex22 + 1;                    
  if (myIndex22 >= numReadings) myIndex22 = 0;                           
  average22 = (total22 / (numReadings*8)); 
  if (average22 != current22) {
    usbMIDI.sendControlChange(22, average22, midi_channel_1);
  }
  current22 = average22;
  
  ///// 3 //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total23 = total23 - readings23[myIndex23];   
  readings23[myIndex23] = analogRead(analogPin2); 
  total23 = total23 + readings23[myIndex23];       
  myIndex23 = myIndex23 + 1;                    
  if (myIndex23 >= numReadings) myIndex23 = 0;                           
  average23 = (total23 / (numReadings*8)); 
  if (average23 != current23) {
    usbMIDI.sendControlChange(23, average23, midi_channel_1);
  }
  current23 = average23;
  
  ///// 4 //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, HIGH);
  delayMicroseconds(readDelay);
  total24 = total24 - readings24[myIndex24];   
  readings24[myIndex24] = analogRead(analogPin2); 
  total24 = total24 + readings24[myIndex24];       
  myIndex24 = myIndex24 + 1;                    
  if (myIndex24 >= numReadings) myIndex24 = 0;                           
  average24 = (total24 / (numReadings*8)); 
    if (average24 != current24) {
    usbMIDI.sendControlChange(24, average24, midi_channel_1);
  }
  
//  
  ///////////////////////////////////////////////      


  ///// ROW TOP /////////////////////////////////
  
  ///// COLUMN 1 //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total25 = total25 - readings25[myIndex25];   
  readings25[myIndex25] = analogRead(analogPin3); 
  total25 = total25 + readings25[myIndex25];       
  myIndex25 = myIndex25 + 1;                    
  if (myIndex25 >= numReadings) myIndex25 = 0;                           
  average25 = (total25 / (numReadings*8)); 
  if (average25 != current25) {
    usbMIDI.sendControlChange(25, average25, midi_channel_1);
  }
  current25 = average25;
  
  ///// COLUMN 2 //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total26 = total26 - readings26[myIndex26];   
  readings26[myIndex26] = analogRead(analogPin3); 
  total26 = total26 + readings26[myIndex26];       
  myIndex26 = myIndex26 + 1;                    
  if (myIndex26 >= numReadings) myIndex26 = 0;                           
  average26 = (total26 / (numReadings*8)); 
  if (average26 != current26) {
    usbMIDI.sendControlChange(26, average26, midi_channel_1);
  }
  current26 = average26;
    
  ///// COLUMN 3 //////
  digitalWrite(bit1, LOW);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total27 = total27 - readings27[myIndex27];   
  readings27[myIndex27] = analogRead(analogPin3); 
  total27 = total27 + readings27[myIndex27];       
  myIndex27 = myIndex27 + 1;                    
  if (myIndex27 >= numReadings) myIndex27 = 0;                           
  average27 = (total27 / (numReadings*8)); 
  if (average27 != current27) {
    usbMIDI.sendControlChange(27, average27, midi_channel_1);
  }
  current27 = average27;
    
  ///// COLUMN 4 //////
  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, HIGH);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total28 = total28 - readings28[myIndex28];   
  readings28[myIndex28] = analogRead(analogPin3); 
  total28 = total28 + readings28[myIndex28];       
  myIndex28 = myIndex28 + 1;                    
  if (myIndex28 >= numReadings) myIndex28 = 0;                           
  average28 = (total28 / (numReadings*8)); 
  if (average28 != current28) {
    usbMIDI.sendControlChange(28, average28, midi_channel_1);
  }
  current28 = average28;
  
  ///////////////////////////////////////////////







  
}
