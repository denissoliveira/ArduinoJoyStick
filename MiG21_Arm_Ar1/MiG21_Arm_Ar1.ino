#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 2
#define NUMCOLS 6

//define the symbols on the buttons of the keypads  
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4','5','6'},
  {'7','8','9','0','-','N'}
};

byte rowPins[NUMROWS] = {8,9}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {2,3,4,5,6,7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS); 

const int tempoApertoBotao = 50;
int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT_PULLUP); // 3 w 02
  pinMode(16, INPUT_PULLUP); // 3 w 02
  pinMode(14, INPUT_PULLUP); // 3 w 03
  pinMode(15, INPUT_PULLUP); // 3 w 03 
  Keyboard.begin();
}

void loop() { 
  CheckAllButtons();
  CheckSwithsButtons();
  delay(10);
}

void CheckSwithsButtons(void) {
  int pin10 = !digitalRead(10);
  int pin16 = !digitalRead(16);
  int pin14 = !digitalRead(14); 
  int pin15 = !digitalRead(15); 


  int state01 = 0;
  int state02 = 1;
  int state03 = 2;
  int state04 = 3;
  int state05 = 4;
  int state06 = 5;
  int state07 = 6;
  int state08 = 7;
  int state09 = 8;
  int state10 = 9;

  if (pin10 == 1 && lastButtonState[state01] != pin10) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("GN");
    lastButtonState[state01] = pin10;
  }else if (pin10 == 0 && lastButtonState[state01] != pin10){
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("LNC");
    lastButtonState[state01] = pin10;
  }

  if (pin16 == 1 && lastButtonState[state02] != pin16) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("S");
    lastButtonState[state02] = pin16;
  }else if (pin16 == 0 && lastButtonState[state02] != pin16){
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("B");
    lastButtonState[state02] = pin16;
  }

  if (pin14 == 1 && lastButtonState[state03] != pin14) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("AUT");
    lastButtonState[state03] = pin14;
  }else if (pin14 == 0 && lastButtonState[state03] != pin14){
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("MAN");
    lastButtonState[state03] = pin14;
  }

  if (pin15 == 1 && lastButtonState[state04] != pin15) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("MSL");
    lastButtonState[state04] = pin15;
  }else if (pin15 == 0 && lastButtonState[state04] != pin15){
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("GYRO");
    lastButtonState[state04] = pin15;
  }

}  

void CheckAllButtons(void) {
      if (keypad.getKeys()) {
       for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
           if ( keypad.key[i].stateChanged )   // Only find keys that have changed state.
            {
            switch (keypad.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                              ////Serial.println("PRESSED");
                              break;
                    case HOLD:
                              tecladoKeypadMatrix(keypad.key[i].kchar);
                              ////Serial.println("HOLD");
                              break;
                    case RELEASED:
                              ////Serial.println("RELEASED");
                              break;
                    case IDLE:
                              ////Serial.println("IDLE");
                              break;
            }
           }   
         }
     }
}


char tecladoKeypadMatrix(char key) {

  //Arms
  if (key == '1'){
    //Serial.println("1");
    Keyboard.press('9');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '2'){
    //Serial.println("2");
    Keyboard.press('8');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '3'){
    //Serial.println("3");
    Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '4'){
    //Serial.println("4");
    Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '5'){
    //Serial.println("5");
    Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '6'){
    //Serial.println("6");
    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '7'){
    //Serial.println("7");
    Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '8'){
    //Serial.println("8");
    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '9'){
    //Serial.println("9");
    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '0'){
    //Serial.println("0");
    Keyboard.press('-');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '-'){
    //Serial.println("-");
    Keyboard.press('0');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  return key;
}
