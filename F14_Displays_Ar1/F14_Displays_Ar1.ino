#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 2
#define NUMCOLS 5

char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4','5'},
  {'6','7','8','9','0'},
  //{'q','w','e','r','t'},
  //{'a','s','d','f','g'}
};

byte rowPins[NUMROWS] = {2,3}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {4,5,6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS); 

const int tempoApertoBotao = 150;
int lastButtonState[20] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT_PULLUP);
  //pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);

  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() { 
  CheckAllButtons();
  CheckSwithsButtons();
  delay(10);
}

void CheckSwithsButtons(void) {
  int pin9 = !digitalRead(9); 
  //int pin10 = !digitalRead(10); 
  int pin16 = !digitalRead(16); 
  int pin14 = !digitalRead(14); 
  int pin15 = !digitalRead(15);
  int pin18 = !digitalRead(18); 
  int pin19 = !digitalRead(19); 

  int pin20 = !digitalRead(20); 
  int pin21 = !digitalRead(21);
  int pin0 = !digitalRead(0); 

  if (pin9 == 1 && lastButtonState[0] != pin9) {
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HSD ECM ORIDE");
    lastButtonState[0] = pin9;
  }else if (pin9 == 0 && lastButtonState[0] != pin9){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HSD ECM OFF");
    lastButtonState[0] = pin9;
  }

  if (pin16 == 1 && lastButtonState[1] != pin16) {
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HSD MODE NAV");
    lastButtonState[1] = pin16;
    //lastButtonState[10] = 0;
  }else if (pin16 == 0 && lastButtonState[1] != pin16){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HSD MODE TID");
    lastButtonState[1] = pin16;
  }


  if (pin14 == 1 && lastButtonState[3] != pin14) {
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HUD DECLUTTER ON");
    lastButtonState[3] = pin14;
  }else if (pin14 == 0 && lastButtonState[3] != pin14){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HUD DECLUTTER OFF");
    lastButtonState[3] = pin14;
  }

  if (pin15 == 1 && lastButtonState[4] != pin15) {
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HUD AWL ILS");
    lastButtonState[4] = pin15;
  }else if (pin15 == 0 && lastButtonState[4] != pin15){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("HUD AWL ACL");
    lastButtonState[4] = pin15;
  }

  if (pin18 == 1 && lastButtonState[5] != pin18) {
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("VDI AWL ILS");
    lastButtonState[5] = pin18;
  }else if (pin18 == 0 && lastButtonState[5] != pin18){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("VDI AWL ACL");
    lastButtonState[5] = pin18;
  }

  if (pin19 == 1 && lastButtonState[6] != pin19) {
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("VDI MODE TV");
    lastButtonState[6] = pin19;
  }else if (pin19 == 0 && lastButtonState[6] != pin19){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("VDI MODE NORM");
    lastButtonState[6] = pin19;
  }

  if (pin20 == 1 && lastButtonState[7] != pin20) {
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("POWER HSD/ECM ON");
    lastButtonState[7] = pin20;
  }else if (pin20 == 0 && lastButtonState[7] != pin20){
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("POWER HSD/ECM OFF");
    lastButtonState[7] = pin20;
  }
  
  if (pin21 == 1 && lastButtonState[8] != pin21) {
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("POWER HUD ON");
    lastButtonState[8] = pin21;
  }else if (pin21 == 0 && lastButtonState[8] != pin21){
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("POWER HUD OFF");
    lastButtonState[8] = pin21;
  }

  if (pin0 == 1 && lastButtonState[9] != pin0) {
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("POWER VDI ON");
    lastButtonState[9] = pin0;
  }else if (pin0 == 0 && lastButtonState[9] != pin0){
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("POWER VDI OFF");
    lastButtonState[9] = pin0;
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
                              tecladoKeypadMatrix(keypad.key[i].kchar);
                              //Serial.println("PRESSED");
                              break;
                    case HOLD:
                              //Serial.println("HOLD");
                              break;
                    case RELEASED:
                              //Serial.println("RELEASED");
                              break;
                    case IDLE:
                              Keyboard.releaseAll();
                              //Serial.println("IDLE");
                              break;
            }
           }   
         }
     }
}


char tecladoKeypadMatrix(char key) {
  if (key == '1'){
    Serial.println("TACAN");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('6');
    delay(tempoApertoBotao);
    
  }
  if (key == '2'){
    Serial.println("DEST");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('7');
    delay(tempoApertoBotao);
    
  }
  if (key == '3'){
    Serial.println("AWL/PCD");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('8');
    delay(tempoApertoBotao);
    
  }
  if (key == '4'){
    Serial.println("VEC");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('9');
    delay(tempoApertoBotao);
    
  }
  if (key == '5'){
    Serial.println("MAN");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('0');
    delay(tempoApertoBotao);
    
  }
  if (key == '6'){
    Serial.println("T O.");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('1');
    delay(tempoApertoBotao);
    
  }
  if (key == '7'){
    Serial.println("CRUISE");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('2');
    delay(tempoApertoBotao);
    
  }
  if (key == '8'){
    Serial.println("A/A");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('3');
    delay(tempoApertoBotao);
    
  }
  if (key == '9'){
    Serial.println("A/G");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('4');
    delay(tempoApertoBotao);
    
  }
  if (key == '0'){
    Serial.println("LDG");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('5');
    delay(tempoApertoBotao);
    
  }
  return key;
}
