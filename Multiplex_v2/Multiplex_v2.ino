
int onBoardLED =  6;

int MultiplexPinSelect1 = 0;
int MultiplexPinSelect2 = 1;
int MultiplexPinSelect3 = 2;

int MultiplexBitStatus1 = 1;
int MultiplexBitStatus2 = 0;
int MultiplexBitStatus3 = 0;


void setup()   
  {  
  Serial.begin(38400);    
  pinMode(onBoardLED, OUTPUT);
  
  pinMode(MultiplexPinSelect1, OUTPUT);
  pinMode(MultiplexPinSelect2, OUTPUT);
  pinMode(MultiplexPinSelect3, OUTPUT);

  }



void loop()                     
 {
 Serial.println("Hello World");
 delay(500);
 
 digitalWrite(onBoardLED, 0);
 
 digitalWrite(MultiplexPinSelect1, MultiplexBitStatus1);
 digitalWrite(MultiplexPinSelect2, MultiplexBitStatus2);
 digitalWrite(MultiplexPinSelect3, MultiplexBitStatus3);
 
 
 
 }

