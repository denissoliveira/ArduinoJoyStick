#include <Keyboard.h>
int buttState[20] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

int tempoApertoBotao = 80;

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
  //pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
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
  int pin18 = !digitalRead(18);
  int pin19 = !digitalRead(19);
  int pin20 = !digitalRead(20);
  int pin21 = !digitalRead(21);

  if (pin9 == 1 && buttState[7] != pin9) {
    Keyboard.press('6');    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar A");
    buttState[7] = pin9;
  }else if (pin9 == 0 && buttState[7] != pin9){
    buttState[7] = pin9;
  }

  if (pin8 == 1 && buttState[6] != pin8) {
    Keyboard.press('7');    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar P CH");
    buttState[6] = pin8;
  }else if (pin8 == 0 && buttState[6] != pin8){
    buttState[6] = pin8;
  }

  if (pin7 == 1 && buttState[5] != pin7) {
    Keyboard.press('8');    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar SIL");
    buttState[5] = pin7;
  }else if (pin7 == 0 && buttState[5] != pin7){
    buttState[5] = pin7;
  }

  if (pin6 == 1 && buttState[4] != pin6) {
    Keyboard.press('9');    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar EM");
    buttState[4] = pin6;
  }else if (pin6 == 0 && buttState[4] != pin6){
    buttState[4] = pin6;
  }

  if (pin2 == 1 && buttState[0] != pin2) {
    Keyboard.press('v');    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("VISU");
    buttState[0] = pin2;
  }else if (pin2 == 0 && buttState[0] != pin2){
    buttState[0] = pin2;
  }

  if (pin5 == 1 && buttState[3] != pin5) {
    Keyboard.press('d');    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("DEC");
    buttState[3] = pin5;
  }else if (pin5 == 0 && buttState[3] != pin5){
    buttState[3] = pin5;
  }

  if (pin3 == 1 && buttState[1] != pin3) {
    Keyboard.press(KEY_LEFT_ALT);  Keyboard.press('x');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Z");
    buttState[1] = pin3;
  }else if (pin3 == 0 && buttState[1] != pin3){
    Keyboard.press(KEY_LEFT_ALT);  Keyboard.press('s');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.print(" Else : "); //Serial.println("S");
    buttState[1] = pin3;
  }

  if (pin4 == 1 && buttState[2] != pin4) {
    Keyboard.press(KEY_RIGHT_CTRL);   Keyboard.press('b');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("B");
    buttState[2] = pin4;
  }else if (pin4 == 0 && buttState[2] != pin4){
    Keyboard.press(KEY_RIGHT_ALT);  Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.print(" Else : "); //Serial.println("PPI");
    buttState[2] = pin4;
  }

  /*if (pin4 == 1 && buttState[2] != pin4) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("B");
    buttState[2] = pin4;
  }else if (pin4 == 0 && buttState[2] != pin4){
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.print(" Else : "); //Serial.println("PPI");
    buttState[2] = pin4;
  }*/

  if (pin18 == 1 && buttState[14] != pin18) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('f');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("BFR");
    buttState[14] = pin18;
    buttState[19] = 0;
  }else {
    buttState[14] = pin18;
  }
  if (pin19 == 1 && buttState[13] != pin19) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('h');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("HFR");
    buttState[13] = pin19;
    buttState[19] = 0;
  }else {
    buttState[13] = pin19;
  }
  if (pin18 == 0 && pin19 == 0 && buttState[19] != 1) {
    Keyboard.press(KEY_RIGHT_ALT);    Keyboard.press('e');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("HFR + BFR");
    buttState[19] = 1;
  }

  if (pin15 == 1 && buttState[11] != pin15) {
    Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("4");
    buttState[11] = pin15;
    buttState[18] = 0;
  }else {
    buttState[11] = pin15;
  }
  if (pin14 == 1 && buttState[10] != pin14) {
    Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("1");
    buttState[10] = pin14;
    buttState[18] = 0;
  }else {
    buttState[10] = pin14;
  }
  if (pin15 == 0 && pin14 == 0 && buttState[18] != 1) {
    Keyboard.press(KEY_LEFT_GUI);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("2");
    buttState[18] = 1;
  }

  if (pin10 == 1 && buttState[8] != pin10) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("60");
    buttState[8] = pin10;
    buttState[17] = 0;
  }else {
    buttState[8] = pin10;
  }
  if (pin16 == 1 && buttState[9] != pin16) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("15");
    buttState[9] = pin16;
    buttState[17] = 0;
  }else {
    buttState[9] = pin16;
  }
  if (pin10 == 0 && pin16 == 0 && buttState[17] != 1) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("30");
    buttState[17] = 1;
  }

  if (pin21 == 1 && buttState[15] != pin21) {
    Keyboard.press(KEY_RIGHT_SHIFT);    Keyboard.press('=');
    delay(tempoApertoBotao);
    //Serial.println("Distancia + ");
    buttState[15] = pin21;
  }else if (pin21 == 0 && buttState[15] != pin21){
    Keyboard.releaseAll();
    buttState[15] = pin21;
  }

  if (pin20 == 1 && buttState[16] != pin20) {
    Keyboard.press(KEY_RIGHT_SHIFT);    Keyboard.press('-');
    delay(tempoApertoBotao);
    //Serial.println("Distancia - ");
    buttState[16] = pin20;
  }else if (pin20 == 0 && buttState[16] != pin20){
    Keyboard.releaseAll();
    buttState[16] = pin20;
  }

}  

