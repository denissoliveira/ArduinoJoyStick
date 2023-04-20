#include "Keyboard.h"

int lastButtonState[11] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0};
const int tempoApertoBotao = 250;

void pressButton(void) {
  //Joystick.pressButton(numBotao);
  delay(tempoApertoBotao);
  //Joystick.releaseButton(numBotao);
}

void pressButton(int pinState, int lastButtonStateNumb, int bt) {
  if (pinState == 1 && lastButtonState[lastButtonStateNumb] != pinState) {
    pressButton();
    Serial.print("Pressinou o botao : "); Serial.println(bt);
    lastButtonState[lastButtonStateNumb] = pinState;
  }else {
    lastButtonState[lastButtonStateNumb] = pinState;
    Serial.print("Else : "); Serial.println(bt);
  }
}

void teclado(void) {
  int pin2 = !digitalRead(2);
  int pin3 = !digitalRead(3);
  int pin4 = !digitalRead(4);
  int pin5 = !digitalRead(5);
  int pin6 = !digitalRead(6);
  int pin7 = !digitalRead(7);
  int pin8 = !digitalRead(8);
  int pin9 = !digitalRead(9);
  int pin10 = !digitalRead(10);
  int pin16 = !digitalRead(16);

  if (pin2 == 1 && lastButtonState[0] != pin2) {
    //Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    //Keyboard.press(KEY_DELETE);
    Keyboard.press('5');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 2");
    lastButtonState[0] = pin2;
  }else {
    lastButtonState[0] = pin2;
  }

  if (pin3 == 1 && lastButtonState[1] != pin3) {
    Keyboard.press(KEY_LEFT_ALT);
    //Keyboard.press(KEY_DELETE);
    Keyboard.press('6');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 3");
    lastButtonState[1] = pin3;
  }else {
    lastButtonState[1] = pin3;
  }

  if (pin4 == 1 && lastButtonState[2] != pin4) {
    //Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    //Keyboard.press(KEY_DELETE);
    Keyboard.press('7');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 4");
    lastButtonState[2] = pin4;
  }else {
    lastButtonState[2] = pin4;
  }

  if (pin5 == 1 && lastButtonState[3] != pin5) {
    //Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    //Keyboard.press(KEY_DELETE);
    Keyboard.press('8');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 5");
    lastButtonState[3] = pin5;
  }else {
    lastButtonState[3] = pin5;
  }

  if (pin6 == 1 && lastButtonState[4] != pin6) {
    //Keyboard.press(KEY_LEFT_CTRL);
    //Keyboard.press(KEY_LEFT_ALT);
    //Keyboard.press(KEY_DELETE);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('4');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 6");
    lastButtonState[4] = pin6;
  }else {
    lastButtonState[4] = pin6;
  }

  if (pin7 == 1 && lastButtonState[5] != pin7) {
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('3');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 7");
    lastButtonState[5] = pin7;
  }else {
    lastButtonState[5] = pin7;
  }

  if (pin8 == 1 && lastButtonState[6] != pin8) {
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('2');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 8");
    lastButtonState[6] = pin8;
  }else {
    lastButtonState[6] = pin8;
  }

  if (pin9 == 1 && lastButtonState[7] != pin9) {
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press('1');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 9");
    lastButtonState[7] = pin9;
  }else {
    lastButtonState[7] = pin9;
  }

  if (pin10 == 1 && lastButtonState[8] != pin10) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('1');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 10");
    lastButtonState[8] = pin10;
    lastButtonState[10] = 0;
  }else {
    lastButtonState[8] = pin10;
  }

  if (pin16 == 1 && lastButtonState[9] != pin16) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('3');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 16");
    lastButtonState[9] = pin16;
    lastButtonState[10] = 0;
  }else {
    lastButtonState[9] = pin16;
  }

  if (pin16 == 0 && pin10 == 0 && lastButtonState[10] != 1) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('2');
    delay(100);
    Keyboard.releaseAll();
    Serial.println(">>>> 17");
    Serial.println(lastButtonState[10]);
    lastButtonState[10] = 1;
  }

}

void setup() {  // initialize the buttons' inputs:
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

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  teclado();
  delay(500);
}




