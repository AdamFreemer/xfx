
//****** XF-X RMC-1 Testing ******//


int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED : Teensy 3.1 has an LED connected on pin 13
int sensorValue = 0;  // variable to store the value coming from the sensor


void setup()
{                
  Serial.begin(57600);
  pinMode(13, OUTPUT);  // Onboard LED
}

int val;

void loop()                     
{
  analogWrite(13, 255);
  val = analogRead(0);
  Serial.print("analog 0 is: ");
  Serial.println(val);
  delay(250);
}
