#include <Keyboard.h>

const int tempoApertoBotao = 150;
int lastButtonState[20] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

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
  int pin16 = !digitalRead(16); 
  int pin14 = !digitalRead(14); 
  int pin15 = !digitalRead(15);

  if (pin2 == 1 && lastButtonState[0] != pin2) {
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('a');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("MASTER ARM");
    lastButtonState[0] = pin2;
  }else if (pin2 == 0 && lastButtonState[0] != pin2){
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('x');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("MASTER ARM else");
    lastButtonState[0] = pin2;
  }

  if (pin3 == 1 && lastButtonState[1] != pin3) {
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('9');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("AUTO ALT");
    lastButtonState[1] = pin3;
  }else if (pin3 == 0 && lastButtonState[1] != pin3){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('9');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("AUTO ALT OFF");
    lastButtonState[1] = pin3;
  }

  if (pin5 == 1 && lastButtonState[4] != pin5) {
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    ////Serial.println("ENGAGE AUTO");
    lastButtonState[4] = pin5;
  }else if (pin5 == 0 && lastButtonState[4] != pin5){
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    ////Serial.println("ENGAGE AUTO else");
    lastButtonState[4] = pin5;
  }

  if (pin6 == 1 && lastButtonState[5] != pin6) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("AUTO HDG");
    lastButtonState[5] = pin6;
    lastButtonState[13] = 0;
  }else {
    lastButtonState[5] = pin6;
  }
  if (pin4 == 1 && lastButtonState[2] != pin4) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("AUTO GT");
    lastButtonState[2] = pin4;
    lastButtonState[13] = 0;
  }else {
    lastButtonState[2] = pin4;
  }
  if (pin6 == 0 && pin4 == 0 && lastButtonState[13] != 1) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("HDG + GT OFF");
    lastButtonState[13] = 1;
  }

  if (pin7 == 1 && lastButtonState[6] != pin7) {
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('c');
    delay(200);
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('v');
    //delay(tempoApertoBotao);
    //Serial.println("ACM");
    lastButtonState[6] = pin7;
  }else if (pin7 == 0 && lastButtonState[6] != pin7){
    Keyboard.releaseAll();
    lastButtonState[6] = pin7;
  }

  if (pin8 == 1 && lastButtonState[7] != pin8) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("AUTO ACL");
    lastButtonState[7] = pin8;
    lastButtonState[14] = 0;
  }else {
    lastButtonState[7] = pin8;
  }
  if (pin9 == 1 && lastButtonState[8] != pin9) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("AUTO VEC/PCD");
    lastButtonState[8] = pin9;
    lastButtonState[14] = 0;
  }else {
    lastButtonState[8] = pin9;
  }
  if (pin8 == 0 && pin9 == 0 && lastButtonState[14] != 1) {
    Keyboard.press(KEY_RIGHT_ALT); Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("VEC/PCD + ACL OFF");
    lastButtonState[14] = 1;
  }

  if (pin10 == 1 && lastButtonState[9] != pin10) {
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('4');
    //delay(tempoApertoBotao);
    //Serial.println("MODE/STP");
    lastButtonState[9] = pin10;
  }else if (pin10 == 0 && lastButtonState[9] != pin10){
    Keyboard.releaseAll();
    lastButtonState[9] = pin10;
  }

  if (pin16 == 1 && lastButtonState[10] != pin16) {
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('3');
    //delay(tempoApertoBotao);
    //Serial.println("MSL PREP");
    lastButtonState[10] = pin16;
  }else if (pin16 == 0 && lastButtonState[10] != pin16){
    Keyboard.releaseAll();
    lastButtonState[10] = pin16;
  }

  if (pin14 == 1 && lastButtonState[11] != pin14) {
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('2');
    //delay(tempoApertoBotao);
    //Serial.println("SW COOL");
    lastButtonState[11] = pin14;
  }else if (pin14 == 0 && lastButtonState[11] != pin14){
    Keyboard.releaseAll();
    lastButtonState[11] = pin14;
  }

  if (pin15 == 1 && lastButtonState[12] != pin15) {
    Keyboard.press(KEY_LEFT_GUI); Keyboard.press('1');
    //delay(tempoApertoBotao);
    //Serial.println("GUN RATE");
    lastButtonState[12] = pin15;
  }else if (pin15 == 0 && lastButtonState[12] != pin15){
    Keyboard.releaseAll();
    lastButtonState[12] = pin15;
  }

}  
