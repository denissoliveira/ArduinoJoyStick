#include <Keypad.h>
#include <Keyboard.h>

const int tempoApertoBotao = 80;
int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};
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

  if (pin2 == 1 && lastButtonState[state01] != pin2) {
    Keyboard.press(KEY_LEFT_ALT);  Keyboard.press('6');
    delay(200);
    Keyboard.releaseAll();
    //Serial.println("Locked beam on");
    lastButtonState[state01] = pin2;
  }else if (pin2 == 0 && lastButtonState[state01] != pin2){
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('6');
    delay(200);
    Keyboard.releaseAll();
    //Serial.println("Locked beam off");
    lastButtonState[state01] = pin2;
  }

  if (pin3 == 1 && lastButtonState[state02] != pin3) {
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Low Off");
    lastButtonState[state02] = pin3;
    lastButtonState[state04] = 0;
  }else {
    lastButtonState[state02] = pin3;
  }
  if (pin4 == 1 && lastButtonState[state03] != pin4) {
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Low on");
    lastButtonState[state03] = pin4;
    lastButtonState[state04] = 0;
  }else {
    lastButtonState[state03] = pin4;
  }
  if (pin3 == 0 && pin4 == 0 && lastButtonState[state04] != 1) {
    Keyboard.press(KEY_LEFT_ALT);  Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Low Sby");
    lastButtonState[state04] = 1;
  }

  if (pin5 == 1 && lastButtonState[state05] != pin5) {
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press(KEY_LEFT_SHIFT);   Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar on");
    lastButtonState[state05] = pin5;
    lastButtonState[state07] = 0;
  }else {
    lastButtonState[state05] = pin5;
  }
  if (pin6 == 1 && lastButtonState[state06] != pin6) {
     Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar Off");
    lastButtonState[state06] = pin6;
    lastButtonState[state07] = 0;
  }else {
    lastButtonState[state06] = pin6;
  }
  if (pin5 == 0 && pin6 == 0 && lastButtonState[state07] != 1) {
    Keyboard.press(KEY_LEFT_ALT);  Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar Sby");
    lastButtonState[state07] = 1;
  }

}  

