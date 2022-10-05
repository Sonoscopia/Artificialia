/* EXOTICA ARDUINO FIRMWARE 
* the game board has 4 pieces
* each piece has 4 magnets, 2 magnets are connected to each other behaving like a switch  
* so each piece has 2 switches (for connectivity reasons: at least one switch should be activated)  
* the 4 pieces have 4 colored cables: black, red, blue and yellow 
* each piece has 4 cables, two cables connect to GND, the other connect to the analog pins (A0 to A7 - portF)
* 
* black1 - A0
* black2 - A1
* red1 - A2
* red2 - A3
* blue1 - A4 
* blue2 - A5
* yellow1 - A6
* yellow2 - A7
* 
* 
* the data is then sent to the serial port to a MaxMSP patch 
*
* Tiago Ângelo 2021
* Sonoscopia - ARTIFICIALIA
*/

uint8_t _prev = 0b11111111;
 

void setup() {
  Serial.begin(9600);
  //pin setup
  pinMode(A0, INPUT_PULLUP); // black1
  pinMode(A1, INPUT_PULLUP); // black2
  pinMode(A2, INPUT_PULLUP); // red1
  pinMode(A3, INPUT_PULLUP); // red2
  pinMode(A4, INPUT_PULLUP); // blue1
  pinMode(A5, INPUT_PULLUP); // blue2
  pinMode(A6, INPUT_PULLUP); // yellow1
  pinMode(A7, INPUT_PULLUP); // yellow2
  
}

void loop() {
  if(_prev != PINF){ // if any input on portF changes send to Serial
    _prev = PINF; 
    Serial.println(_prev, BIN);

    /* THIS WAS CAUSING SOME PIN VALUES TO GET STUCK*/
    /*else{
      Serial.print(digitalRead(A0)); Serial.print(" ");
      Serial.print(digitalRead(A1)); Serial.print(" ");
      Serial.print(digitalRead(A2)); Serial.print(" ");
      Serial.print(digitalRead(A3)); Serial.print(" ");
      Serial.print(digitalRead(A4)); Serial.print(" ");
      Serial.print(digitalRead(A5)); Serial.print(" ");
      Serial.print(digitalRead(A6)); Serial.print(" ");
      Serial.print(digitalRead(A7)); Serial.println();
    }*/
  }
}
