int redPin =  12;
int greenPin =  15;
int bluePin =  14;

void setup()   {                
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int redIntensity = 0;

void loop()                     
{
  // set all 3 pins to the desired intensity
  analogWrite(redPin, redIntensity);
  analogWrite(greenPin, 20 - redIntensity);
  analogWrite(bluePin, 0);
  
  // remain at this color, but not for very long
  delay(50);
  
  // increase the red
  redIntensity = redIntensity + 1;
  
  // since 255 is the maximum, set it back to 0
  // when it increments beyond 255
  if (redIntensity > 20) {
    redIntensity = 0;
  }
}
