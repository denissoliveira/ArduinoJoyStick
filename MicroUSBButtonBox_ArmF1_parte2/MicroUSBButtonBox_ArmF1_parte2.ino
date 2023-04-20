#include <Keypad.h>
#include <Joystick.h>

#define NUMBUTTONS 13
/*#define NUMROWS 2
#define NUMCOLS 4

//define the symbols on the buttons of the keypads  
byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3},
  {4,5,6,7}
};

byte rowPins[NUMROWS] = {2,3}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {4,5,6,7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS); */

//initialize an Joystick with 56 buttons;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, NUMBUTTONS, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);


void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // 3 w 01
  pinMode(3, INPUT_PULLUP); // 3 w 01
  pinMode(5, INPUT_PULLUP); // 2 w
  pinMode(8, INPUT_PULLUP); // 3 w 02
  pinMode(9, INPUT_PULLUP); // 3 w 02
  pinMode(6, INPUT_PULLUP); // 3 w 03
  pinMode(7, INPUT_PULLUP); // 3 w 03 
  //pinMode(15, INPUT_PULLUP); // 3 w 03 
  //pinMode(18, INPUT_PULLUP); // 3 w 03 (A0)
  //pinMode(A1, INPUT_PULLUP); 
  //pinMode(A2, INPUT_PULLUP); 
  //pinMode(A3, INPUT_PULLUP); 
  Joystick.begin();
}

const int tempoApertoBotao = 150;

void pressButton(int numBotao) {
  Joystick.pressButton(numBotao);
  delay(tempoApertoBotao);
  Joystick.releaseButton(numBotao);
}

int lastButtonState[16] = { 0, 0, 0, 0, 0 ,0 ,0, 0 ,0 ,0, 0 ,0 ,0, 0 ,0 ,0 }; 
int lastButtonStateSize = sizeof(lastButtonState) / sizeof(int);

void pressButton2Way(int pinState, int joyButton, int joyButton2, int lastButtonStateNumb) {
  if (lastButtonState[lastButtonStateNumb] != pinState && pinState == 1) {
    pressButton(joyButton);
    lastButtonState[lastButtonStateNumb] = pinState;
    Serial.print("if ");Serial.println(pinState);
  }else if (lastButtonState[lastButtonStateNumb] != pinState && pinState == 0) {
    pressButton(joyButton2);
    lastButtonState[lastButtonStateNumb] = pinState;
    Serial.print("else if ");Serial.println(pinState);
  }
}

void pressButton3Way(int pinState1, int pinState2, int joyButton1, int joyButton2, int joyButton3,int initialArrayState) {

  int currentButtonStateA0 = pinState1;
  int currentButtonStateA1 = pinState2;
  int state01 = initialArrayState; 
  int state02 = initialArrayState + 1;
  int state03 = initialArrayState + 2;


  for (int i = 0; i < 3; i++) {
    if (currentButtonStateA0 == 1 && lastButtonState[state01] == 0) {
      pressButton(joyButton1);
      lastButtonState[state01] = currentButtonStateA0;
      lastButtonState[state02] = 0;
      lastButtonState[state03] = 0;
      Serial.print("currentButtonStateA0 ");Serial.println(currentButtonStateA0);
    }else if (currentButtonStateA0 != 1 && currentButtonStateA1 != 1 && lastButtonState[state02] == 0) {
      pressButton(joyButton2);
      lastButtonState[state01] = 0;
      lastButtonState[state02] = 1;
      lastButtonState[state03] = 0;
      Serial.print("lastButtonState[state02] ");Serial.println(lastButtonState[state02]);
    }else if (currentButtonStateA1 == 1 && lastButtonState[state03] == 0) {
      pressButton(joyButton3);
      lastButtonState[state01] = 0;
      lastButtonState[state02] = 0;
      lastButtonState[state03] = currentButtonStateA1;
      Serial.print("currentButtonStateA1 ");Serial.println(currentButtonStateA1);
    }
  }
}


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
