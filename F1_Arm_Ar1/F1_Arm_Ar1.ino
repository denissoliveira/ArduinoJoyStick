#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 2
#define NUMCOLS 4

//define the symbols on the buttons of the keypads  
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'}
};

byte rowPins[NUMROWS] = {2,3}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {4,5,6,7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS); 

const int tempoApertoBotao = 100;
int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void setup() {
  Serial.begin(9600);
  //pinMode(0, INPUT_PULLUP); 
  //pinMode(1, INPUT_PULLUP); 
  pinMode(8, INPUT_PULLUP); // 3 w 01
  pinMode(9, INPUT_PULLUP); // 3 w 01
  pinMode(10, INPUT_PULLUP); // 3 w 02
  pinMode(16, INPUT_PULLUP); // 3 w 02
  pinMode(14, INPUT_PULLUP); // 2 w 
  pinMode(15, INPUT_PULLUP); // 3 w 03 
  pinMode(18, INPUT_PULLUP); // 3 w 03 (A0)
  //pinMode(A1, INPUT_PULLUP); 
  //pinMode(A2, INPUT_PULLUP); 
  //pinMode(A3, INPUT_PULLUP); 
  Keyboard.begin();
  
}

void loop() { 
  CheckAllButtons();
  tecladoKeypadMatrix();
  delay(0);
}


void CheckAllButtons(void) {

  int pin8 = !digitalRead(8); // 
  int pin9 = !digitalRead(9); // 
  int pin10 = !digitalRead(10); //  
  int pin16 = !digitalRead(16); // 
  int pin14 = !digitalRead(14); // 
  int pin15 = !digitalRead(15); //
  int pin18 = !digitalRead(18); //

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

  //VISEUR
  if (pin8 == 1 && lastButtonState[state01] != pin8) {
    Keyboard.press(KEY_LEFT_ALT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("A");
    lastButtonState[state01] = pin8;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state01] = pin8;
  }
  if (pin9 == 1 && lastButtonState[state02] != pin9) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("VISEUR");
    lastButtonState[state02] = pin9;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state02] = pin9;
  }
  if (pin9 == 0 && pin8 == 0 && lastButtonState[state03] != 1) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("M");
    lastButtonState[state03] = 1;
  }

  if (pin18 == 1 && lastButtonState[state04] != pin18) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("CPC");
    lastButtonState[state04] = pin18;
  }else if (pin18 == 0 && lastButtonState[state04] != pin18){
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("SALV");
    lastButtonState[state04] = pin18;
  }

  if (pin15 == 1 && lastButtonState[state05] != pin15) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("INST");
    lastButtonState[state05] = pin15;
    lastButtonState[state07] = 0;
  }else {
    lastButtonState[state05] = pin15;
  }
  if (pin14 == 1 && lastButtonState[state06] != pin14) {
    Keyboard.press(KEY_LEFT_ALT);    Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("INERT");
    lastButtonState[state06] = pin14;
    lastButtonState[state07] = 0;
  }else {
    lastButtonState[state06] = pin14;
  }
  if (pin15 == 0 && pin14 == 0 && lastButtonState[state07] != 1) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("RET");
    lastButtonState[state07] = 1;
  }

  if (pin10 == 1 && lastButtonState[state08] != pin10) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("EX");
    lastButtonState[state08] = pin10;
    lastButtonState[state10] = 0;
  }else {
    lastButtonState[state08] = pin10;
  }
  if (pin16 == 1 && lastButtonState[state09] != pin16) {
    Keyboard.press(KEY_LEFT_ALT);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("IN");
    lastButtonState[state09] = pin16;
    lastButtonState[state10] = 0;
  }else {
    lastButtonState[state09] = pin16;
  }
  if (pin10 == 0 && pin16 == 0 && lastButtonState[state10] != 1) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("1 + 2");
    lastButtonState[state10] = 1;
  }

}

//4 3 2 1
//8 7 6 5
void tecladoKeypadMatrix(void) {
  char key = keypad.getKey(); //KEY_SPACE   KEY_LEFT_GUI

  //Arms buttons
  if (key == '4'){ //EXT G
    //Serial.println("EXT G");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('4');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '3'){ //MG FUS
    //Serial.println("MG FUS");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('3');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '2'){  //CAN A
    //Serial.println("CAN A");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('2');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '1'){ //BOMB VOIL
    //Serial.println("BOMB VOIL");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('1');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '8'){ //EXT D
    //Serial.println("EXT D");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('8');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '7'){ //MD
    //Serial.println("MD");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('7');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '6'){  //CAN S ROQ
    //Serial.println("CAN S ROQ");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
  if (key == '5'){ //BOMB FUS
    //Serial.println("BOMB FUS");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('5');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }
}
