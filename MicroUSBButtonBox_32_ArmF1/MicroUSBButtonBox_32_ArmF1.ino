#include <Keypad.h>
#include <Joystick.h>

/*#define NUMBUTTONS 24
#define NUMROWS 6
#define NUMCOLS 4

//define the symbols on the buttons of the keypads  
byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15},
  {16,17,18,19},
  {20,21,22,23}
};

byte rowPins[NUMROWS] = {2, 3, 4, 5, 6, 7}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {10, 16, 14, 15}; //connect to the column pinouts of the keypad*/

#define NUMBUTTONS 12
#define NUMROWS 3
#define NUMCOLS 4

byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
};

byte rowPins[NUMROWS] = {2, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {5, 6, 7, 8}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS); 

//initialize an Joystick with 56 buttons;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 32, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);


void setup() {
  Serial.begin(9600);
  Joystick.begin();
}


void loop() { 
  CheckAllButtons();
  delay(0);
}


void CheckAllButtons(void) {

      if (buttbx.getKeys()) {
       for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
           if ( buttbx.key[i].stateChanged )   // Only find keys that have changed state.
            {
            switch (buttbx.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                              Joystick.pressButton(buttbx.key[i].kchar);
                              delay(420);
                              Joystick.releaseButton(buttbx.key[i].kchar);
                              Serial.println("PRESSED");
                              break;
                    case HOLD:
                              //Joystick.releaseButton(buttbx.key[i].kchar);
                              //Joystick.pressButton(buttbx.key[i].kchar);
                              //delay(220);
                              //Joystick.releaseButton(buttbx.key[i].kchar);
                              Serial.println("HOLD");
                              break;
                    case RELEASED:
                              //Joystick.releaseButton(buttbx.key[i].kchar);
                              Serial.println("RELEASED");
                              break;
                    case IDLE:
                              //Joystick.releaseButton(buttbx.key[i].kchar);
                              Serial.println("IDLE");
                              break;
            }
           }   
         }
     }
}
