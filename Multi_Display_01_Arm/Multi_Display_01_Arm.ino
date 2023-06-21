#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 4
#define NUMCOLS 5

//define the symbols on the buttons of the keypads  
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4','5'},
  {'6','7','8','9','0'},
  {'q','w','e','r','t'},
  {'a','s','d','f','g'}
};

byte rowPins[NUMROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {6,7,8,10,16}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS);

int lastButtonState[4] = { 0, 0, 0, 0 }
const int tempoApertoBotao = 180;

void setup() {
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  teclado();
  CheckAllButtons();
  //delay(500);
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
                              Serial.println("PRESSED");
                              break;
                    case HOLD:
                              //Serial.println("HOLD");
                              break;
                    case RELEASED:
                              Keyboard.releaseAll();
                              Serial.println("RELEASED");
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
    Serial.println("1");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '2'){
    Serial.println("2");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '3'){
    Serial.println("3");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '4'){
    Serial.println("4");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '5'){
    Serial.println("5");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '6'){
    Serial.println("6");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '7'){
    Serial.println("7");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '8'){
    Serial.println("8");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '9'){
    Serial.println("9");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  if (key == '0'){
    Serial.println("0");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }

  if (key == 'q'){
    Serial.println("q");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 'w'){
    Serial.println("w");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 'e'){
    Serial.println("e");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 'r'){
    Serial.println("r");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 't'){
    Serial.println("t");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 'a'){
    Serial.println("a");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 's'){
    Serial.println("s");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 'd'){
    Serial.println("d");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 'f'){
    Serial.println("f");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;
  if (key == 'g'){
    Serial.println("g");
    //Keyboard.press(KEY_LEFT_SHIFT); 
    delay(tempoApertoBotao);
    //Keyboard.press('4');
    delay(tempoApertoBotao);   
  }
  return key;

}

void teclado(void) {
  
  int pinx = !digitalRead(x);

  if (pinx == 1 && lastButtonState[w] != pinx) {
    //Keyboard.press(KEY_LEFT_SHIFT); 
    dela0(tempoApertoBotao);
    //Keyboard.press('4');
    dela0(tempoApertoBotao);
    Serial.println("1p");
    lastButtonState[w] = pinx;
  }else if (pinx != 1 && lastButtonState[w] != pinx) {
    //Keyboard.press(KEY_LEFT_SHIFT); 
    dela0(tempoApertoBotao);
    //Keyboard.press('4');
    dela0(tempoApertoBotao);
    lastButtonState[w] = pinx;
    Serial.println("2p");
  }
  Keyboard.releaseAll();


}




