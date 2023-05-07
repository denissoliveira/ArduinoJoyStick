#include <Keypad.h>
#include <Keyboard.h>

const int tempoApertoBotao = 250;
int lastButtonState[14] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};
int lastReloadState[3] = { 0, 0, 0};
int lastChuteState[3] = { 0, 0, 0};
int lastJATOState[3] = { 0, 0, 0};

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() { 
  CheckSwithsButtons();
  delay(10);
}

void CheckSwithsButtons(void) {
  int pin2 = !digitalRead(2);
  int pin3 = !digitalRead(3);
  int pin4 = !digitalRead(4);
  int pin5 = !digitalRead(5);
  int pin6 = !digitalRead(6);
  int pin7 = !digitalRead(7);
  int pin8 = !digitalRead(8);
  int pin9 = !digitalRead(9);
  int pin10 = !digitalRead(10);
  int pin14 = !digitalRead(14);
  int pin15 = !digitalRead(15);
  int pin16 = !digitalRead(16);

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
  int state11 = 10;
  int state12 = 11;
  int state13 = 12;
  int state14 = 13;

  if (pin3 == 1 && lastButtonState[state01] != pin3) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('b');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("G");
    lastButtonState[state01] = pin3;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state01] = pin3;
  }
  if (pin2 == 1 && lastButtonState[state02] != pin2) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('u');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("D");
    lastButtonState[state02] = pin2;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state02] = pin2;
  }
  if (pin3 == 0 && pin2 == 0 && lastButtonState[state03] != 1) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('h');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("I");
    lastButtonState[state03] = 1;
  }

  if (pin4 == 1 && lastButtonState[state04] != pin4) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('m');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("INERT");
    lastButtonState[state04] = pin4;
    lastButtonState[state06] = 0;
  }else {
    lastButtonState[state04] = pin4;
  }
  if (pin5 == 1 && lastButtonState[state05] != pin5) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('o');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("INSTANT");
    lastButtonState[state05] = pin5;
    lastButtonState[state06] = 0;
  }else {
    lastButtonState[state05] = pin5;
  }
  if (pin5 == 0 && pin4 == 0 && lastButtonState[state06] != 1) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('k');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("RETARD");
    lastButtonState[state06] = 1;
  }

  if (pin6 == 1 && lastButtonState[state07] != pin6) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('0');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("DIST.x 10M +");
    lastButtonState[state07] = pin6;
  }else if (pin6 == 0 && lastButtonState[state07] != pin6){
    lastButtonState[state07] = pin6;
  }

  if (pin7 == 1 && lastButtonState[state08] != pin7) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('9');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("DIST.x 10M -");
    lastButtonState[state08] = pin7;
  }else if (pin7 == 0 && lastButtonState[state08] != pin7){
    lastButtonState[state08] = pin7;
  }

  if (pin8 == 1 && lastButtonState[state09] != pin8) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('8');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("NB +");
    lastButtonState[state09] = pin8;
  }else if (pin8 == 0 && lastButtonState[state09] != pin8){
    lastButtonState[state09] = pin8;
  }

  if (pin9 == 1 && lastButtonState[state10] != pin9) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("NB -");
    lastButtonState[state10] = pin9;
  }else if (pin9 == 0 && lastButtonState[state10] != pin9){
    lastButtonState[state10] = pin9;
  }

  if (pin10 == 1 && lastButtonState[state11] != pin10) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('=');
    delay(tempoApertoBotao);
    Serial.println("PRES");
    lastButtonState[state11] = pin10;
  }else if (pin10 == 0 && lastButtonState[state11] != pin10){
    Keyboard.releaseAll();
    lastButtonState[state11] = pin10;
  }

  if (pin16 == 1 && lastButtonState[state12] != pin16) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('-');
    delay(tempoApertoBotao);
    Serial.println("TEST");
    lastButtonState[state12] = pin16;
  }else if (pin16 == 0 && lastButtonState[state12] != pin16){
    Keyboard.releaseAll();
    lastButtonState[state12] = pin16;
  }

  if (pin14 == 1 && lastButtonState[state13] != pin14) {
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('i');
    delay(tempoApertoBotao);
    Serial.println("CAN. ROQ S530");
    lastButtonState[state13] = pin14;
  }else if (pin14 == 0 && lastButtonState[state13] != pin14){
    Keyboard.releaseAll();
    lastButtonState[state13] = pin14;
  }

  if (pin15 == 1 && lastButtonState[state14] != pin15) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('i');
    delay(tempoApertoBotao);
    Serial.println("AUTO");
    lastButtonState[state14] = pin15;
  }else if (pin15 == 0 && lastButtonState[state14] != pin15){
    Keyboard.releaseAll();
    lastButtonState[state14] = pin15;
  }

}  

