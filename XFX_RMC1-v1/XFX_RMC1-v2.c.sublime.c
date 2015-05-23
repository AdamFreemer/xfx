
//****** XF-X RMC-1 v 1.0 ******//
int ver = 7;

// Bounce library import
#include <Bounce.h>


int inputpin = 0;  
const int numReadings = 3; 
int midichannel = 0; // Analog input midi channels

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED : Teensy 3.1 has an LED connected on pin 13
int sensorValue = 0;  // variable to store the value coming from the sensor


void setup() 
  {
      // Teensy onboard led  
      pinMode(ledPin, OUTPUT);   

      Serial.begin(57600);
      Serial.print("XF-X Firmware v1.0");
      Serial.println(ver);
        
    }


void loop() // Main operation loop
  {

  
}
