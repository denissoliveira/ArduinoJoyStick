#include <Keyboard.h>

int lastButtonState[11] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0};
const int tempoApertoBotao = 50;

void teclado(void) {
  int pin15 = !digitalRead(15);
  int pin6 = !digitalRead(6);
  int pin14 = !digitalRead(14);
  int pin16 = !digitalRead(16);
  int pin10 = !digitalRead(10);
  int pin7 = !digitalRead(7);
  int pin8 = !digitalRead(8);
  int pin9 = !digitalRead(9);

  if (pin15 == 1 && lastButtonState[0] != pin15) {
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('d');
    delay(tempoApertoBotao);
    //Serial.println(">>>> shift + d");
    lastButtonState[0] = pin15;
  }else if (pin15 != 1 && lastButtonState[0] != pin15) {
    lastButtonState[0] = pin15;
    Keyboard.releaseAll();
    //Serial.println(">>>> shift + d solto");
  }

  if (pin6 == 1 && lastButtonState[1] != pin6) {
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> 7");
    lastButtonState[1] = pin6;
  }else if (pin6 != 1 && lastButtonState[1] != pin6){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> else 7");
    lastButtonState[1] = pin6;
  }

  if (pin14 == 1 && lastButtonState[2] != pin14) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> 6");
    lastButtonState[2] = pin14;
  }else if (pin14 != 1 && lastButtonState[2] != pin14){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> else  6");
    lastButtonState[2] = pin14;
  }

  if (pin16 == 1 && lastButtonState[3] != pin16) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> 5");
    lastButtonState[3] = pin16;
  }else if (pin16 != 1 && lastButtonState[3] != pin16){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> else  5");
    lastButtonState[3] = pin16;
  }

  if (pin10 == 1 && lastButtonState[4] != pin10) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> 4");
    lastButtonState[4] = pin10;
  }else if (pin10 != 1 && lastButtonState[4] != pin10){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> else 4");
    lastButtonState[4] = pin10;
  }

  if (pin7 == 1 && lastButtonState[5] != pin7) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> 3");
    lastButtonState[5] = pin7;
  }else if (pin7 != 1 && lastButtonState[5] != pin7){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> else 3");
    lastButtonState[5] = pin7;
  }

  if (pin8 == 1 && lastButtonState[6] != pin8) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> 2");
    lastButtonState[6] = pin8;
  }else if (pin8 != 1 && lastButtonState[6] != pin8) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> else 2");
    lastButtonState[6] = pin8;
  }

  if (pin9 == 1 && lastButtonState[7] != pin9) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> 1");
    lastButtonState[7] = pin9;
  }else if (pin9 != 1 && lastButtonState[7] != pin9){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println(">>>> else 1");
    lastButtonState[7] = pin9;
  }

}

void setup() {  // initialize the buttons' inputs:
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
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
  delay(500);
}




