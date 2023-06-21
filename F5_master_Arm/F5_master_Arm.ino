#include <Keyboard.h>

int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};
const int tempoApertoBotao = 80;

void teclado(void) {
  int pin3 = !digitalRead(3);
  int pin4 = !digitalRead(4);
  int pin5 = !digitalRead(5);
  int pin6 = !digitalRead(6);
  int pin7 = !digitalRead(7);
  int pin8 = !digitalRead(8);
  int pin9 = !digitalRead(9);
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
  int state11 = 10;
  int state12 = 11;

  //Emer all jet
  if (pin7 == 1 && lastButtonState[state01] != pin7) {
    //Keyboard.press(KEY_LEFT_CTRL); //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('9');
    delay(500);
    Keyboard.releaseAll();
    //Keyboard.press(KEY_LEFT_CTRL); //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('0');
    delay(tempoApertoBotao);
    Serial.println("emer all jet");
    lastButtonState[state01] = pin7;
  }else if (pin7 != 1 && lastButtonState[state01] != pin7) {
    lastButtonState[state01] = pin7;
    Keyboard.releaseAll();
    Serial.println("emer all jet solto !");
  }

  //______________________
  //select jettson - select position
  if (pin9 == 1 && lastButtonState[state02] != pin9) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("select jettson - select position");
    lastButtonState[state02] = pin9;
    lastButtonState[state04] = 0;
  }else {
    lastButtonState[state02] = pin9;
  }
  //select jettson - all pilones
  if (pin8 == 1 && lastButtonState[state03] != pin8) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('a');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("select jettson - all pilones");
    lastButtonState[state03] = pin8;
    lastButtonState[state04] = 0;
  }else {
    lastButtonState[state03] = pin8;
  }
  //select jettson - off
  if (pin9 == 0 && pin8 == 0 && lastButtonState[state04] != 1) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('o');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("select jettson - off");
    lastButtonState[state04] = 1;
  }

  //______________________  
  //External store - RIPL
  if (pin6 == 1 && lastButtonState[state05] != pin6) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('r');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("External store - RIPL");
    lastButtonState[state05] = pin6;
  }else {
    lastButtonState[state05] = pin6;
  }

  //External store - Bomb
  if (pin5 == 1 && lastButtonState[state06] != pin5) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('b');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("External store - Bomb");
    lastButtonState[state06] = pin5;
  }else {
    lastButtonState[state06] = pin5;
  }

  //External store - Safe
  if (pin4 == 1 && lastButtonState[state07] != pin4) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('s');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("External store - Safe");
    lastButtonState[state07] = pin4;
  }else {
    lastButtonState[state07] = pin4;
  }

  //External store - RKT/DISP
  if (pin3 == 1 && lastButtonState[state08] != pin3) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('d');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("External store - RKT/DISP");
    lastButtonState[state08] = pin3;
  }else {
    lastButtonState[state08] = pin3;
  }

  //Arm on
  if (pin14 == 1 && lastButtonState[state09] != pin14) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_SHIFT);    //Keyboard.press('g');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Arm on");
    lastButtonState[state09] = pin14;
  }else {
    lastButtonState[state09] = pin14;
  }

  //Arm off
  if (pin15 == 1 && lastButtonState[state10] != pin15) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_SHIFT);    //Keyboard.press('b');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Arm off");
    lastButtonState[state10] = pin15;
  }else {
    lastButtonState[state10] = pin15;
  }

  //Bomb Arms cw
  if (pin16 == 1 && lastButtonState[state11] != pin16) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_SHIFT);    //Keyboard.press('e');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Bomb Arms cw");
    lastButtonState[state11] = pin16;
  }else {
    lastButtonState[state11] = pin16;
  }

  //Bomb Arms ccw
  if (pin10 == 1 && lastButtonState[state12] != pin10) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_SHIFT);    //Keyboard.press('w');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Bomb Arms ccw");
    lastButtonState[state12] = pin10;
  }else {
    lastButtonState[state12] = pin10;
  }

}

void setup() {  // initialize the buttons' inputs:
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);09
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  teclado();
  //delay(500);
}




