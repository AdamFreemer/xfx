

const int redPin =  12;
const int greenPin =  15;
const int bluePin =  14;

void setup()
{                
  Serial.begin(38400);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

int val;

void loop()                     
{
  val = analogRead(0);
  Serial.print("analog 0 is: ");
  Serial.println(val);
  
  if (val < 200) {
      analogWrite(redPin, 15); 
      analogWrite(greenPin, 0); 
      analogWrite(bluePin, 0);     
      }

  if (val >= 200 && val <= 400) {
      analogWrite(redPin, 5); 
      analogWrite(greenPin, 7); 
      analogWrite(bluePin, 0);      
      }


  if (val >= 400 && val <= 600) {
      analogWrite(redPin, 0); 
      analogWrite(greenPin, 15); 
      analogWrite(bluePin, 0);      
      }

 
  if (val >= 600 && val <= 800) {
      analogWrite(redPin, 0); 
      analogWrite(greenPin, 7); 
      analogWrite(bluePin, 5);      
      }

 
  if (val > 800) {
      analogWrite(redPin, 0); 
      analogWrite(greenPin, 0); 
      analogWrite(bluePin, 15);   
      }
  
  delay(25);
  
  
  
  
}

