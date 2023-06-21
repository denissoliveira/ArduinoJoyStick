#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 3
#define NUMCOLS 3

//define the symbols on the buttons of the keypads  
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};

byte rowPins[NUMROWS] = {2,5,7}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {3,4,6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS);

const int tempoApertoBotao = 150;
int lastButtonState[14] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() { 
  CheckAllButtons();
  CheckSwithsButtons();
  delay(10);
}

char tecladoKeypadMatrix(char key) {

  if (key == '1'){
    //Serial.println("HUD Brilho -");
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('h');
    delay(tempoApertoBotao);
    
  }
  if (key == '2'){
    //Serial.println("HUD Brilho +");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('h');
    delay(tempoApertoBotao);
    
  }
  if (key == '3'){
    //Serial.println("HUD Color");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('h');
    delay(tempoApertoBotao);
    
  }
  if (key == '4'){
    //Serial.println("WayPoint next");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.print("`");//Keyboard.press("'");
    delay(tempoApertoBotao);
    
  }
  if (key == '5'){
    //Serial.println("Special After IR Jamming");
    Keyboard.press(KEY_LEFT_SHIFT);Keyboard.press('e');
    delay(tempoApertoBotao);
    
  }
  if (key == '6'){
    //Serial.println("WayPoint previus");
    Keyboard.press(KEY_LEFT_SHIFT);Keyboard.print("`");//Keyboard.press("'");
    delay(tempoApertoBotao);
    
  }
  if (key == '7'){
    //Serial.println("ASP-17 Raise");
    Keyboard.press(KEY_RIGHT_SHIFT);Keyboard.press('h');
    delay(tempoApertoBotao);
    
  }
  if (key == '8'){
    //Serial.println("Audible Warning");
    Keyboard.press(KEY_RIGHT_SHIFT);Keyboard.press('n');
    delay(tempoApertoBotao);
    
  }
  if (key == '9'){
    //Serial.println("ASP-17 Lower");
    Keyboard.press(KEY_RIGHT_ALT);Keyboard.press('h');
    delay(tempoApertoBotao);
    
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
                              ////Serial.println("PRESSED");
                              break;
                    case HOLD:
                              ////Serial.println("HOLD");
                              break;
                    case RELEASED:
                              Keyboard.releaseAll();
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

void CheckSwithsButtons(void) {

  int pin8 = !digitalRead(8); 
  int pin9 = !digitalRead(9); 
  int pin10 = !digitalRead(10); 
  int pin16 = !digitalRead(16); 
  int pin14 = !digitalRead(14); 
  int pin15 = !digitalRead(15); 
  int pin18 = !digitalRead(18); 
  int pin19 = !digitalRead(19); 
  int pin20 = !digitalRead(20); 

  if (pin8 == 1 && lastButtonState[5] != pin8) {
     Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press(KEY_HOME);
    delay(400);
    Keyboard.releaseAll();
    //Serial.println("Eng R Start");
    lastButtonState[5] = pin8;
  }else if (pin8 == 0 && lastButtonState[5] != pin8){
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press(KEY_END);
    delay(400);
    Keyboard.releaseAll();
    //Serial.println("Eng R Stop");
    lastButtonState[5] = pin8;
  }

  if (pin9 == 1 && lastButtonState[6] != pin9) {
    Keyboard.press(KEY_RIGHT_ALT);Keyboard.press(KEY_HOME);
    delay(400);
    Keyboard.releaseAll();
    //Serial.println("Eng L Start");
    lastButtonState[6] = pin9;
  }else if (pin9 == 0 && lastButtonState[6] != pin9){
    Keyboard.press(KEY_RIGHT_ALT);Keyboard.press(KEY_END);
    delay(400);
    Keyboard.releaseAll();
    //Serial.println("Eng L Stop");
    lastButtonState[6] = pin9;
  }

  if (pin10 == 1 && lastButtonState[7] != pin10) {
    Keyboard.press(KEY_RIGHT_SHIFT);Keyboard.press('h');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Hud Filter On");
    lastButtonState[7] = pin10;
  }else if (pin10 == 0 && lastButtonState[7] != pin10){
    Keyboard.press(KEY_RIGHT_SHIFT);Keyboard.press('h');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Hud Filter Off");
    lastButtonState[7] = pin10;
  }

  if (pin16 == 1 && lastButtonState[8] != pin16) {
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Folding Wings On");
    lastButtonState[8] = pin16;
  }else if (pin16 == 0 && lastButtonState[8] != pin16){
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Folding Wings Off");
    lastButtonState[8] = pin16;
  }

  if (pin14 == 1 && lastButtonState[9] != pin14) {
    Keyboard.press(KEY_LEFT_ALT);Keyboard.press('q');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Nose Wheel Steering On");
    lastButtonState[9] = pin14;
  }else if (pin14 == 0 && lastButtonState[9] != pin14){
    Keyboard.press(KEY_LEFT_ALT);Keyboard.press('q');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Nose Wheel Steering Off");
    lastButtonState[9] = pin14;
  }

  if (pin15 == 1 && lastButtonState[10] != pin15) {
    Keyboard.press(KEY_LEFT_ALT);Keyboard.press('i');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Intake FOD Auto");
    lastButtonState[10] = pin15;
  }else if (pin15 == 0 && lastButtonState[10] != pin15){
    Keyboard.press(KEY_LEFT_ALT);Keyboard.press('i');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Intake FOD Off");
    lastButtonState[10] = pin15;
  }

  if (pin18 == 1 && lastButtonState[11] != pin18) {
    Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Light Cockpit On");
    lastButtonState[11] = pin18;
  }else if (pin18 == 0 && lastButtonState[11] != pin18){
    Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Light Cockpit Off");
    lastButtonState[11] = pin18;
  }

  if (pin19 == 1 && lastButtonState[12] != pin19) {
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Light Nav On");
    lastButtonState[12] = pin19;
  }else if (pin19 == 0 && lastButtonState[12] != pin19){
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Light Nav Off");
    lastButtonState[12] = pin19;
  }

  if (pin20 == 1 && lastButtonState[13] != pin20) {
    Keyboard.press(KEY_RIGHT_SHIFT);Keyboard.press('l');
    delay(tempoApertoBotao);
    //Keyboard.print("`");
    Keyboard.releaseAll();
    //Serial.println("Electric Power On");
    lastButtonState[13] = pin20;
  }else if (pin20 == 0 && lastButtonState[13] != pin20){
    Keyboard.press(KEY_RIGHT_SHIFT);Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Electric Power Off");
    lastButtonState[13] = pin20;
  }

}  

