#include <MIDI.h>

//////**** RMC-1 Rev0 Beta5 ********//////

const int numReadings = 10; // This adjusts the number of array samples, 5 is low, 10 is on the high side
int readDelay = 200;       // This is the delay in microseconds before the an analog pin reads from the multiplexer

int bit1 = 2;
int bit2 = 1;
int bit4 = 0;

int analogPin0 = 0;
int analogPin1 = 1;
int analogPin2 = 2;
int analogPin3 = 3;

int midi_channel_1 = 1;

int readings1[numReadings];
int myIndex1 = 0;
int total1 = 0;
int average1 = 0;
int current1 = 0;

void setup()
{
  // initialize serial communication with computer:
  //Serial.begin(57600);

  // Digital bus initialize
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  
  // initialize all the readings to 0: Pot 1
  for (int thisReading1 = 0; thisReading1 < numReadings; thisReading1++)
    readings1[thisReading1] = 0;
}

void loop() {
  Serial.print(" Avr1: ");
  Serial.println(readings1[myIndex1]);

  digitalWrite(bit1, HIGH);
  digitalWrite(bit2, LOW);
  digitalWrite(bit4, LOW);
  delayMicroseconds(readDelay);
  total1 = total1 - readings1[myIndex1];
  readings1[myIndex1] = analogRead(analogPin1);
  total1 = total1 + readings1[myIndex1];
  myIndex1 = myIndex1 + 1;
  if (myIndex1 >= numReadings) myIndex1 = 0;
  average1 = (total1 / (numReadings * 8));

    usbMIDI.sendControlChange(1, average1, midi_channel_1);

}
