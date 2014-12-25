
int onBoardLED =  6;

int bit1 = 0;
int bit2 = 1;
int bit3 = 2;
int bit1status = 


void setup()   
  {  
  Serial.begin(38400);    
  pinMode(onBoardLED, OUTPUT);
  
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit3, OUTPUT);
  }



void loop()                     
 {
 Serial.println("Hello World");
 delay(500);
 
 digitalWrite(onBoardLED, HIGH);
 
 digitalWrite(bit1, HIGH);
 digitalWrite(bit2, LOW);
 digitalWrite(bit3, HIGH);
 
 
 
 }

