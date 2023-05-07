#include <Keypad.h>
#include <Keyboard.h>

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // 3 w 01
  pinMode(3, INPUT_PULLUP); // 3 w 01
  pinMode(5, INPUT_PULLUP); // 2 w
  pinMode(8, INPUT_PULLUP); // 3 w 02
  pinMode(9, INPUT_PULLUP); // 3 w 02
  pinMode(6, INPUT_PULLUP); // 3 w 03
  pinMode(7, INPUT_PULLUP); // 3 w 03 
  Keyboard.begin();
}

const int tempoApertoBotao = 100;
int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void loop() { 
  CheckAllButtons();
  delay(10);
}

void CheckAllButtons(void) {
  int pin2 = !digitalRead(2); // 
  int pin3 = !digitalRead(3); // 
  int pin4 = !digitalRead(4); //  
  int pin5 = !digitalRead(5); // 
  int pin6 = !digitalRead(6); // 
  int pin7 = !digitalRead(7); //
  int pin8 = !digitalRead(8); //
  int pin9 = !digitalRead(9); //

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

  //FEUX FORM. FIX
  if (pin2 == 1 && lastButtonState[state01] != pin2) {
    Keyboard.press(KEY_RIGHT_SHIFT);    Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("CLIG");
    lastButtonState[state01] = pin2;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state01] = pin2;
  }
  if (pin3 == 1 && lastButtonState[state02] != pin3) {
    Keyboard.press(KEY_RIGHT_ALT);    Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("FIXE");
    lastButtonState[state02] = pin3;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state02] = pin3;
  }
  if (pin2 == 0 && pin3 == 0 && lastButtonState[state03] != 1) {
    Keyboard.press(KEY_RIGHT_CTRL);    Keyboard.press('l');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("A");
    lastButtonState[state03] = 1;
  }

  //FEUX NAV. CLIG
  if (pin8 == 1 && lastButtonState[state04] != pin8) {
    Keyboard.press(KEY_RIGHT_ALT);    Keyboard.press('n');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("FAIB");
    lastButtonState[state04] = pin8;
    lastButtonState[state06] = 0;
  }else {
    lastButtonState[state04] = pin8;
  }
  if (pin9 == 1 && lastButtonState[state05] != pin9) {
    Keyboard.press(KEY_RIGHT_SHIFT);    Keyboard.press('n');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("FORT");
    lastButtonState[state05] = pin9;
    lastButtonState[state06] = 0;
  }else {
    lastButtonState[state05] = pin9;
  }
  if (pin8 == 0 && pin9 == 0 && lastButtonState[state06] != 1) {
    Keyboard.press(KEY_RIGHT_CTRL);    Keyboard.press('n');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("A");
    lastButtonState[state06] = 1;
  }

  //RADAR EMISS
  if (pin6 == 1 && lastButtonState[state07] != pin6) {
    Keyboard.press(KEY_LEFT_ALT);    Keyboard.press('8');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("A");
    lastButtonState[state07] = pin6;
    lastButtonState[state09] = 0;
  }else {
    lastButtonState[state07] = pin6;
  }
  if (pin7 == 1 && lastButtonState[state08] != pin7) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('8');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("EMIT");
    lastButtonState[state08] = pin7;
    lastButtonState[state09] = 0;
  }else {
    lastButtonState[state08] = pin7;
  }
  if (pin6 == 0 && pin7 == 0 && lastButtonState[state09] != 1) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press('8');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("STBY");
    lastButtonState[state09] = 1;
  }

  if (pin5 == 1 && lastButtonState[state10] != pin5) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('9');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("4L");
    lastButtonState[state10] = pin5;
  }else if (pin5 == 0 && lastButtonState[state10] != pin5){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press('9');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("1L");
    lastButtonState[state10] = pin5;
  }
 
}
