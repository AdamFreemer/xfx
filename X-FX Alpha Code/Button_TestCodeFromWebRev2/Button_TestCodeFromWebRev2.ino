#include <Bounce.h>

const int buttonPin = 2;
Bounce pushbutton = Bounce(buttonPin, 10);  // 10 ms debounce

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(27, OUTPUT);
  Serial.begin(57600);
  Serial.println("Pushbutton Bounce library test:");
}

byte previousState = HIGH;         // what state was the button last time
unsigned int count = 0;            // how many times has it changed to low
unsigned long countAt = 0;         // when count changed
unsigned int countPrinted = 0;     // last count printed
int LEDStatus = 0;

void loop() {

  if { (pushbutton.fallingEdge()) {
              analogWrite(27, 255);
              
      count = count + 1;
      countAt = millis();
    }
  } else 
    {
 
    if (count != countPrinted) 
      {
      unsigned long nowMillis = millis();
      if (nowMillis - countAt > 100) 
        {
        Serial.print("count: ");
        Serial.println(count);
        countPrinted = count;
        }
      }
    }
    
  if (pushbutton.update()) {
    if (pushbutton.risingEdge()) {
              analogWrite(27, 40);
              
    }
  }


}
