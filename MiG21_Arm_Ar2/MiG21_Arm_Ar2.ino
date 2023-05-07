#include <Keypad.h>
#include <Keyboard.h>

const int tempoApertoBotao = 50;
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
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
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

  if (pin2 == 1 && lastButtonState[state01] != pin2) {
    Keyboard.press(KEY_RIGHT_SHIFT);  Keyboard.press(KEY_INSERT);
    delay(200);
    Keyboard.releaseAll();
    Keyboard.press(KEY_RIGHT_ALT);  Keyboard.press(KEY_INSERT);
    delay(200);
    Keyboard.releaseAll();
    Serial.println("Ext Store OUTBD");
    lastButtonState[state01] = pin2;
  }else if (pin2 == 0 && lastButtonState[state01] != pin2){
    lastButtonState[state01] = pin2;
  }

  if (pin3 == 1 && lastButtonState[state02] != pin3) {
    if(lastChuteState[0] == 0) {
      Keyboard.press(KEY_RIGHT_ALT);    Keyboard.press('d');
      delay(tempoApertoBotao);
      Keyboard.releaseAll();
      Serial.println("DROP Chute Open");
      lastChuteState[0] = 1;
    }else if(lastChuteState[1] == 0) {
      Keyboard.press('p');
      delay(tempoApertoBotao);
      Keyboard.releaseAll();
      Serial.println("DROP Chute Active");
      lastChuteState[1] = 1;
    }else if(lastChuteState[2] == 0) {
      Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press(KEY_RIGHT_SHIFT);   Keyboard.press('d');
      delay(tempoApertoBotao);
      Keyboard.releaseAll();
      Serial.println("DROP Chute Disconect");
      lastChuteState[2] = 1;
    }
    lastButtonState[state02] = pin3;
  }else if (pin3 == 0 && lastButtonState[state02] != pin3){
    if (lastChuteState[0] == 1 && lastChuteState[1] == 1 && lastChuteState[2] == 1) {
      lastChuteState[0] = 0;
      lastChuteState[1] = 0;
      lastChuteState[2] = 0;
      /*Keyboard.press(KEY_RIGHT_ALT);    Keyboard.press('d');
      delay(200);
      Keyboard.releaseAll();*/
      Serial.println("DROP Chute Reload");
    }
    lastButtonState[state02] = pin3;
  }

  if (pin4 == 1 && lastButtonState[state03] != pin4) {
    Keyboard.press(KEY_RIGHT_ALT);    Keyboard.press('=');
    delay(100);
    Keyboard.releaseAll();
    delay(50);
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('=');
    delay(100);
    Keyboard.releaseAll();
    Serial.println("ARMED ON");
    lastButtonState[state03] = pin4;
  }else if (pin4 == 0 && lastButtonState[state03] != pin4){
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press(KEY_RIGHT_SHIFT);   Keyboard.press('=');
    delay(100);
    Keyboard.releaseAll();
    delay(50);
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press(KEY_RIGHT_CTRL);   Keyboard.press('=');
    delay(100);
    Keyboard.releaseAll();
    Serial.println("ARMED OFF");
    lastButtonState[state03] = pin4;
  }

  if (pin5 == 1 && lastButtonState[state04] != pin5) {
    Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("AIR");
    lastButtonState[state04] = pin5;
  }else if (pin5 == 0 && lastButtonState[state04] != pin5){
    Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("GND");
    lastButtonState[state04] = pin5;
  }

  if (pin6 == 1 && lastButtonState[state05] != pin6) {
    Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("SAR");
    lastButtonState[state05] = pin6;
    lastButtonState[state11] = 0;
  }else {
    lastButtonState[state05] = pin6;
  }
  if (pin7 == 1 && lastButtonState[state06] != pin7) {
    Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("IR");
    lastButtonState[state06] = pin7;
    lastButtonState[state11] = 0;
  }else {
    lastButtonState[state06] = pin7;
  }
  if (pin6 == 0 && pin7 == 0 && lastButtonState[state11] != 1) {
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Neutro");
    lastButtonState[state11] = 1;
  }

  
  if (pin8 == 1 && lastButtonState[state07] != pin8) {

    if(lastReloadState[0] == 0){
      Keyboard.press(KEY_LEFT_ALT);    Keyboard.press('1');
      delay(200);
      Keyboard.releaseAll();
      lastReloadState[0] = 1;
      Serial.println("Reloading 1");
    }else if(lastReloadState[1] == 0){
      Keyboard.press(KEY_LEFT_ALT);    Keyboard.press('2');
      delay(200);
      Keyboard.releaseAll();
      lastReloadState[1] = 1;
      Serial.println("Reloading 2");
    }else if(lastReloadState[2] == 0){
      Keyboard.press(KEY_LEFT_ALT);    Keyboard.press('3');
      delay(200);
      Keyboard.releaseAll();
      lastReloadState[2] = 1;
      Serial.println("Reloading 3");
    }
    lastButtonState[state07] = pin8;
  }else if (pin8 == 0 && lastButtonState[state07] != pin8){
    if (lastReloadState[0] == 1 && lastReloadState[1] == 1 && lastReloadState[2] == 1) {
      lastReloadState[0] = 0;
      lastReloadState[1] = 0;
      lastReloadState[2] = 0;
      Serial.println("Reloading Todos");
    }
    lastButtonState[state07] = pin8;
  }

  if (pin9 == 1 && lastButtonState[state08] != pin9) {
    Keyboard.press(KEY_RIGHT_SHIFT);  Keyboard.press(KEY_DELETE);
    delay(200);
    Keyboard.releaseAll();
    Keyboard.press(KEY_RIGHT_ALT);  Keyboard.press(KEY_DELETE);
    delay(200);
    Keyboard.releaseAll();
    Serial.println("Ext Store INBD");
    lastButtonState[state08] = pin9;
  }else if (pin9 == 0 && lastButtonState[state08] != pin9){
    lastButtonState[state08] = pin9;
  }

  if (pin10 == 1 && lastButtonState[state09] != pin10) {
    Keyboard.press(KEY_RIGHT_SHIFT);    Keyboard.press(KEY_PAGE_DOWN);
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Keyboard.press(KEY_RIGHT_CTRL);    Keyboard.press(KEY_PAGE_DOWN);
    delay(300);
    Keyboard.releaseAll();
    Serial.println("Drop Wing tank");
    lastButtonState[state09] = pin10;
  }else if (pin10 == 0 && lastButtonState[state09] != pin10){
    Keyboard.press(KEY_RIGHT_SHIFT);    Keyboard.press(KEY_PAGE_DOWN);
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Drop Wing tank Active");
    lastButtonState[state09] = pin10;
  }

  if (pin16 == 1 && lastButtonState[state10] != pin16) {
    if (lastJATOState[0] == 0) {
      Serial.println("JATO 111"); 
      Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('j');
      delay(tempoApertoBotao);
      Keyboard.releaseAll();
      lastJATOState[0] = 1;
    }else {
      Serial.println(" esle JATO");
      Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(' ');
      delay(300);
      Keyboard.releaseAll();
    }
    

    

    Serial.println("JATO");
    lastButtonState[state10] = pin16;
  }else if (pin16 == 0 && lastButtonState[state10] != pin16){
    lastButtonState[state10] = pin16;
  }

}  

