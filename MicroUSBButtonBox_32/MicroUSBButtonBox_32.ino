#include <Keypad.h>
#include <Joystick.h>

// Define o tamanho da matriz de botões
//const int numLinhas = 6;
//const int numColunas = 6;

// Define os pinos digitais para as linhas e colunas dos botões
//const int linhas[numLinhas] = {2, 3, 4, 5, 6, 7};
//const int colunas[numColunas] = {8, 9, 10, 14, 15, 16};

#define NUMBUTTONS 36
#define NUMROWS 6
#define NUMCOLS 6


//define the symbols on the buttons of the keypads
byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3,4,5},
  {6,7,8,9,10,11},
  {12,13,14,15,16,17},
  {18,19,20,21,22,23},
  {24,25,26,27,28,29},
  {20,31,32,33,34,35}
};


byte rowPins[NUMROWS] = {2, 3, 4, 5, 6, 7}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {8, 9, 10, 14, 15, A0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS); 

//initialize an Joystick with 56 buttons;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_JOYSTICK, 36, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);


void setup() {
  Joystick.begin();
}


void loop() { 
  CheckAllButtons();
  delay(0);
}


void CheckAllButtons(void) {
      if (buttbx.getKeys())
    {
       for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
           if ( buttbx.key[i].stateChanged )   // Only find keys that have changed state.
            {
            switch (buttbx.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    case HOLD:
                              Joystick.pressButton(buttbx.key[i]) //setButton(buttbx.key[i].kchar, 1);
                              delay(50);
                              
                              break;
                    case RELEASED:
                    case IDLE:
                              Joystick.setButton(buttbx.key[i].kchar, 0);
                              break;
            }
           }   
         }
         
     }
}
