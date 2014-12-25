  
  
  // Pot declarations 
  #include <Bounce.h>
  const int numReadings = 30; // Smoothing amount
  int readings[numReadings] = {0,0,0,0,0}; // Set the readings from the analog input to 0
  int pots = 4; // The number of pots
  int lastreading[6] = {0,0,0,0,0}; // Set the last readings to 0
  int POTReading = 0; // Set the last readings to 0
  int midichannel = 0;
  const int deadbandLowRes = 2;
  const int deadbandHighRes = 1;
  int LowResReading = 0;
  unsigned int HighResReading = 0;
 
  // Button declarations
  Bounce button1 = Bounce(1, 5);  // 5 = 5 ms debounce time
  Bounce button2 = Bounce(2, 5);  
  Bounce button3 = Bounce(3, 5);
  Bounce button4 = Bounce(4, 5);
  Bounce button5 = Bounce(5, 5);
  Bounce button6 = Bounce(6, 5);
  Bounce button7 = Bounce(7, 5);
  Bounce button8 = Bounce(8, 5);
  Bounce button12 = Bounce(12, 5);
  Bounce button13 = Bounce(13, 5);
  const int channelbutton = 6;
  
  // Begin main loop
  void setup()
    {   
    // Button config  
    // Configure the pins for input mode with pullup resistors.
    // The pushbuttons connect from each pin to ground.  
    pinMode(1, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);  
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT_PULLUP);
  
    Serial.begin(31250);   // Standard midi rate
    pinMode(6, OUTPUT);
    }
  
  void loop()
    {
    digitalWrite(6, HIGH);
    
    for (int i = 0; i < pots; i++ )  // Get reading for all potentiometers
      {
 
    POTReading = analogRead(i);
     Serial.print("POTReading = ");
    Serial.println(POTReading);
    LowResReading = POTReading /8;
    HighResReading = POTReading * 16;
    midichannel = i + 1;       
 
                if ((i < 2) && (POTReading <= (lastreading[i] - deadbandHighRes))   || (POTReading >= (lastreading[i] + deadbandHighRes)))// Hi-res pots
                  {
                  usbMIDI.sendPitchBend(HighResReading, midichannel); //send hi-res pot data
                  }  
              if ((i >= 2) && (POTReading <= (lastreading[i] - deadbandLowRes))   || (POTReading >= (lastreading[i] + deadbandLowRes))) 
                  {
                  usbMIDI.sendControlChange(i, LowResReading, midichannel); //send low-res pot data
                  }

         lastreading[i] = POTReading;   // Set last array value to current value
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
    button12.update();
    button13.update();
      
  
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
      
      
      
   
      delay(500);  // Delay output by 5ms
  }
    
      
  
  
    
  
  

