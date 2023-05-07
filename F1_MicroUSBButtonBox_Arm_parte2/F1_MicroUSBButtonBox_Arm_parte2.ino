#include <Keypad.h>

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // 3 w 01
  pinMode(3, INPUT_PULLUP); // 3 w 01
  pinMode(5, INPUT_PULLUP); // 2 w
  pinMode(8, INPUT_PULLUP); // 3 w 02
  pinMode(9, INPUT_PULLUP); // 3 w 02
  pinMode(6, INPUT_PULLUP); // 3 w 03
  pinMode(7, INPUT_PULLUP); // 3 w 03 
}

const int tempoApertoBotao = 150;

void loop() { 
  CheckAllButtons();
  delay(10);
}

void CheckAllButtons(void) {
      
      pressButton2Way(!digitalRead(5), 0, 1, 0);
      //pressButton2Way(!digitalRead(9), 10, 11, 1);
      //pressButton2Way(!digitalRead(A0), 12, 13, 2);
      //pressButton2Way(!digitalRead(A1), 14, 15, 3);

      pressButton3Way(!digitalRead(2), !digitalRead(3), 3, 4, 5 , 1);
      pressButton3Way(!digitalRead(8), !digitalRead(9), 6, 7, 8 , 4);
      pressButton3Way(!digitalRead(6), !digitalRead(7), 9, 10, 11 , 7);
      //pressButton3Way(!digitalRead(A2), !digitalRead(A3), 25, 26, 27 , 15);

      /*if (buttbx.getKeys()) {
       for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
           if ( buttbx.key[i].stateChanged )   // Only find keys that have changed state.
            {
            switch (buttbx.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                              Joystick.pressButton(buttbx.key[i].kchar); 
                              //Serial.println("PRESSED");
                              break;
                    case HOLD:
                              Joystick.releaseButton(buttbx.key[i].kchar);
                              //Serial.println("HOLD");
                              break;
                    case RELEASED:
                              Joystick.releaseButton(buttbx.key[i].kchar);
                              //Serial.println("RELEASED");
                              break;
                    case IDLE:
                              Joystick.releaseButton(buttbx.key[i].kchar);
                              //Serial.println("IDLE");
                              break;
            }
           }   
         }
     }*/
}
