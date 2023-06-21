#include <Keyboard.h>

int lastButtonState[15] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};
const int tempoApertoBotao = 80;

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
  int pin14 = !digitalRead(14);
  int pin15 = !digitalRead(15);
  int pinA0 = !digitalRead(18);

  if (pin2 == 1 && lastButtonState[0] != pin2) {
    //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("LONG");
    lastButtonState[0] = pin2;
  }else if (pin2 != 1 && lastButtonState[0] != pin2) {
    //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('4');
    delay(tempoApertoBotao);
    lastButtonState[0] = pin2;
    Keyboard.releaseAll();
    Serial.println("SHORT");
  }

  if (pin3 == 1 && lastButtonState[1] != pin3) {
    //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("PROFILE");
    lastButtonState[1] = pin3;
  }else if (pin3 != 1 && lastButtonState[1] != pin3) {
    //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('2');
    delay(tempoApertoBotao);
    lastButtonState[1] = pin3;
    Keyboard.releaseAll();
    Serial.println("PLAN");
  }

  if (pin4 == 1 && lastButtonState[2] != pin4) {
    //Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("WEAPONS 5");
    lastButtonState[2] = pin4;
  }else if (pin4 != 1 && lastButtonState[2] != pin4) {
    //Keyboard.press('5');
    delay(tempoApertoBotao);
    lastButtonState[2] = pin4;
    Keyboard.releaseAll();
    Serial.println("WEAPONS 5 OFF");
  }

  if (pin5 == 1 && lastButtonState[3] != pin5) {
    //Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("WEAPONS 4");
    lastButtonState[3] = pin5;
  }else if (pin5 != 1 && lastButtonState[3] != pin5) {
    //Keyboard.press('4');
    delay(tempoApertoBotao);
    lastButtonState[3] = pin5;
    Keyboard.releaseAll();
    Serial.println("WEAPONS 4 OFF");
  }

  if (pin6 == 1 && lastButtonState[4] != pin6) {
    //Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("WEAPONS 3");
    lastButtonState[4] = pin6;
  }else if (pin6 != 1 && lastButtonState[4] != pin6) {
    //Keyboard.press('3');
    delay(tempoApertoBotao);
    lastButtonState[4] = pin6;
    Keyboard.releaseAll();
    Serial.println("WEAPONS 3 OFF");
  }

  if (pin7 == 1 && lastButtonState[5] != pin7) {
    //Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("WEAPONS 2");
    lastButtonState[5] = pin7;
  }else if (pin7 != 1 && lastButtonState[5] != pin7) {
    //Keyboard.press('2');
    delay(tempoApertoBotao);
    lastButtonState[5] = pin7;
    Keyboard.releaseAll();
    Serial.println("WEAPONS 2 OFF");
  }

  if (pin8 == 1 && lastButtonState[6] != pin8) {
    //Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("WEAPONS 1");
    lastButtonState[6] = pin8;
  }else if (pin8 != 1 && lastButtonState[6] != pin8) {
    //Keyboard.press('1');
    delay(tempoApertoBotao);
    lastButtonState[6] = pin8;
    Keyboard.releaseAll();
    Serial.println("WEAPONS 1 OFF");
  }

  if (pin9 == 1 && lastButtonState[7] != pin9) {
    //Keyboard.press('0');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("MASTER ON");
    lastButtonState[7] = pin9;
  }else if (pin9 != 1 && lastButtonState[7] != pin9) {
    //Keyboard.press('0');
    delay(tempoApertoBotao);
    lastButtonState[7] = pin9;
    Keyboard.releaseAll();
    Serial.println("MASTER OFF");
  }

  if (pin14 == 1 && lastButtonState[8] != pin14) {
    //Keyboard.press('9');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("GUNS READY");
    lastButtonState[8] = pin14;
  }else if (pin14 != 1 && lastButtonState[8] != pin14) {
    //Keyboard.press('9');
    delay(tempoApertoBotao);
    lastButtonState[8] = pin14;
    Keyboard.releaseAll();
    Serial.println("GUNS OFF");
  }

  //BDHI
  if (pin15 == 1 && lastButtonState[9] != pin15) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("NAV CMPTR");
    lastButtonState[9] = pin15;
    lastButtonState[11] = 0;
  }else {
    lastButtonState[9] = pin15;
  }
  if (pinA0 == 1 && lastButtonState[10] != pinA0) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("NAV PAC");
    lastButtonState[10] = pinA0;
    lastButtonState[11] = 0;
  }else {
    lastButtonState[10] = pinA0;
  }
  if (pin15 == 0 && pinA0 == 0 && lastButtonState[11] != 1) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("TACAN");
    lastButtonState[11] = 1;
  }

  //ARM NOSE
  if (pin10 == 1 && lastButtonState[12] != pin10) {
    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("ARM NOSE & TAIL");
    lastButtonState[12] = pin10;
    lastButtonState[14] = 0;
  }else {
    lastButtonState[12] = pin10;
  }
  if (pin16 == 1 && lastButtonState[13] != pin16) {
    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("ARM TAIL");
    lastButtonState[13] = pin16;
    lastButtonState[14] = 0;
  }else {
    lastButtonState[13] = pin16;
  }
  if (pin10 == 0 && pin16 == 0 && lastButtonState[14] != 1) {
    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("ARM OFF");
    lastButtonState[14] = 1;
  }

}

void setup() {
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
  pinMode(18, INPUT_PULLUP);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  teclado();
  //delay(500);
}




