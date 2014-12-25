
  
  // Pot declarations 
  #include <Bounce.h>
  const int numReadings = 25; // Smoothing amount
  int reading_at[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
  int pots = 4; // The number of pots
  int index = 0; // The index of the current reading
  int total = 0; // Running total array
  int pintotal[6] = {0,0,0,0,0}; // Pin total
  int average[6] = {0,0,0,0,0}; // Pin average
  int averagePlus[6] = {0,0,0,0,0};
  int averageMinus[6] = {0,0,0,0,0};
  int currpotval = 0;
  int lowres = 0; // Pin average
  int hires = 0; // Pin average
  int channel = 1; // Set midi channel to send to 1
  int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
  int midichannel = 0;
  
  // Button declarations
  Bounce LeftButtonBlue1 = Bounce(2, 5);  // 5 = 5 ms debounce time
  Bounce LeftButtonBlue2 = Bounce(4, 5);  
  Bounce LeftButtonRed = Bounce(5, 5);
  Bounce LeftButtonGreen = Bounce(3, 5);
  Bounce RightButtonBlue1 = Bounce(6, 5);
  Bounce RightButtonBlue2 = Bounce(8, 5);
  Bounce RightButtonRed = Bounce(9, 5);
  Bounce RightButtonGreen = Bounce(7, 5);

  // LED declarations
  const int channelbutton = 6;
  pinMode(LeftLEDBlue1, OUTPUT);
  pinMode(LeftButtonBlue2, OUTPUT);
  pinMode(LeftButtonRed, OUTPUT);
  pinMode(LeftButtonGreen, OUTPUT);
  pinMode(RightButtonBlue1, OUTPUT);
  pinMode(RightButtonBlue2, OUTPUT);
  pinMode(RightButtonRed, OUTPUT);
  pinMode(RightButtonGreen, OUTPUT);

  const int redPin =  12;

// Begin main loop
void setup()
  {   
  // Button config  
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  
  pinMode(LeftButtonBlue1, OUTPUT);
  pinMode(LeftButtonBlue2, OUTPUT);
  pinMode(LeftButtonRed, OUTPUT);
  pinMode(LeftButtonGreen, OUTPUT);
  pinMode(RightButtonBlue1, OUTPUT);
  pinMode(RightButtonBlue2, OUTPUT);
  pinMode(RightButtonRed, OUTPUT);
  pinMode(RightButtonGreen, OUTPUT);
  
  // Button LED Configuration
  pinMode(LeftLEDBlue1, OUTPUT);
  pinMode(LeftLEDBlue2, OUTPUT);
  pinMode(LeftLEDRed, OUTPUT);
  pinMode(LeftLEDGreen, OUTPUT);
  pinMode(RightLEDBlue1, OUTPUT);
  pinMode(RightLEDBlue2, OUTPUT);
  pinMode(RightLEDRed, OUTPUT);
  pinMode(RightLEDGreen, OUTPUT);
  
  Serial.begin(31250);  // Standard midi rate
  pinMode(6, OUTPUT);   // Teensy onboard LED
  
  }

void loop() // Execution loop
  {
  digitalWrite(6, 100);
  
  // LED button functionality  
  analogWrite(redPin, 30);
  
  // main pot loop
  for (int i = 0; i < pots; i++ )  // pots = pot count + 1
    {
    index = 0;  // Set index to zero
    
    for (int j = 0; j < numReadings; j++ )  // loop to create average reading
      {
      total = total - reading_at[index];
      reading_at[index] = analogRead(i); // read from pot i
      currpotval = reading_at[index];   
      total = total + reading_at[index];
      index = index++;
      pintotal[i] = total;
      }
 
       
       average[i] = (pintotal[i] / numReadings);    // Calculate the average Divide by 8 to make between 0-127
       averagePlus[i] = average[i] + 1;
       averageMinus[i] = average[i] - 1;
       hires = currpotval * 16;
       lowres = currpotval / 8;
       
       midichannel = i + 1;
       
       if (lastreading[i] != average[i]) // If reading is different from the previous
            { 
            if (i < 2) // Hi-res pots
                {  
                usbMIDI.sendPitchBend(hires, midichannel); //send hi-res pot data
                }  
            if (i >= 2)  
                {
                usbMIDI.sendControlChange(i,lowres, midichannel); //send low-res pot data
                }
            }
            
       lastreading[i] = average[i];   // Set last array value to current value
    }
    
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.

  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();


  // falling = high (not pressed - voltage from pullup resistor)
  // to low (pressed - button connects pin to ground)
  if (button12.fallingEdge()) {
    usbMIDI.sendNoteOn(60, 99, channelbutton);  // 60 = C4
    Serial.println("pin 12 - falling");
  }
  if (button13.fallingEdge()) {
    usbMIDI.sendNoteOn(61, 99, channelbutton);  // 61 = C#4
        Serial.println("pin 13 - falling");
  }  
    
    
    
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button12.risingEdge()) {
    usbMIDI.sendNoteOff(60, 0, channelbutton);  // 60 = C4
        Serial.println("pin 12 - rising");
  }
  if (button13.risingEdge()) {
    usbMIDI.sendNoteOff(61, 0, channelbutton);  // 61 = C#4
        Serial.println("pin 13 - rising");
  }
 
    delay(5);  // Delay output by 5ms
}
  
    


  



