#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 3
#define NUMCOLS 4

//define the symbols on the buttons of the keypads  
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','0','q','w'}
};

byte rowPins[NUMROWS] = {2,3,4};
byte colPins[NUMCOLS] = {5,6,7,8};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS);

const int tempoApertoBotao = 80;
int lastButtonState[3] = { 0, 0, 0};

void setup() {
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  teclado();
  CheckAllButtons();
  delay(50);
}

void CheckAllButtons(void) {
      if (keypad.getKeys()) {
       for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
           if ( keypad.key[i].stateChanged )   // Only find keys that have changed state.
            {
            switch (keypad.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                              tecladoKeypadMatrix(keypad.key[i].kchar);
                              //Serial.println("PRESSED");
                              break;
                    case HOLD:
                              //Serial.println("HOLD");
                              break;
                    case RELEASED:
                              Keyboard.releaseAll();
                              //Serial.println("RELEASED");
                              break;
                    case IDLE:
                              //Serial.println("IDLE");
                              break;
            }
           }   
         }
     }
}

char tecladoKeypadMatrix(char key) {

  //Arms
  if (key == '1'){
    Serial.println("STEP RIPPLE UP");
    Keyboard.press(KEY_RIGHT_ALT); 
    delay(tempoApertoBotao);
    Keyboard.press('8');
    delay(tempoApertoBotao);   
  }
  if (key == '2'){
    Serial.println("DROP INTVL UP");
    Keyboard.press(KEY_LEFT_ALT); 
    delay(tempoApertoBotao);
    Keyboard.press('8');
    delay(tempoApertoBotao);   
  }
  if (key == '3'){
    Serial.println("DROP INTVL DOWN");
    Keyboard.press(KEY_LEFT_ALT); 
    delay(tempoApertoBotao);
    Keyboard.press('7');
    delay(tempoApertoBotao);   
  }
  if (key == '4'){
    Serial.println("STEP RIPPLE DOWN");
    Keyboard.press(KEY_RIGHT_ALT); 
    delay(tempoApertoBotao);
    Keyboard.press('7');
    delay(tempoApertoBotao);   
  }
  if (key == '5'){
    Serial.println("AWRS UP");
    Keyboard.press(KEY_LEFT_CTRL); 
    delay(tempoApertoBotao);
    Keyboard.press('8');
    delay(tempoApertoBotao);   
  }
  if (key == '6'){
    Serial.println("AWRS DOWN");
    Keyboard.press(KEY_LEFT_CTRL);
    delay(tempoApertoBotao);
    Keyboard.press('7');
    delay(tempoApertoBotao);   
  }
  if (key == '7'){
    Serial.println("Army UP");
    Keyboard.press('8');
    delay(tempoApertoBotao);   
  }
  if (key == '8'){
    Serial.println("Army DOWN");
    Keyboard.press('7');
    delay(tempoApertoBotao);   
  }
  if (key == 'q'){
    Serial.println("Emer sel UP");
    Keyboard.press(KEY_RIGHT_CTRL); 
    delay(tempoApertoBotao);
    Keyboard.press('8');
    delay(tempoApertoBotao);   
  }
  if (key == 'w'){
    Serial.println("Emer sel DOWN");
    Keyboard.press(KEY_RIGHT_CTRL); 
    delay(tempoApertoBotao);
    Keyboard.press('7');
    delay(tempoApertoBotao);   
  }

  return key;
}

void teclado(void) {
  int pin10 = !digitalRead(10);
  int pin16 = !digitalRead(16);

  if (pin10 == 1 && lastButtonState[0] != pin10) {
    Keyboard.press(KEY_LEFT_CTRL); 
    delay(tempoApertoBotao);
    Keyboard.press('j');
    delay(tempoApertoBotao);
    Serial.println("Emer Bomb");
    lastButtonState[0] = pin10;
  }else if (pin10 != 1 && lastButtonState[0] != pin10) {
    //Keyboard.press(KE0_LEFT_SHIFT); 
    //delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);
    lastButtonState[0] = pin10;
    Serial.println("Emer Bomb release");
  }
  Keyboard.releaseAll();

  if (pin16 == 1 && lastButtonState[1] != pin16) {
    Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    Keyboard.press('8');
    delay(tempoApertoBotao);
    Serial.println("MULT SW X1");
    lastButtonState[1] = pin16;
  }else if (pin16 != 1 && lastButtonState[1] != pin16) {
    Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    Keyboard.press('7');
    delay(tempoApertoBotao);
    lastButtonState[1] = pin16;
    Serial.println("MULT SW X10");
  }
  Keyboard.releaseAll();

}




