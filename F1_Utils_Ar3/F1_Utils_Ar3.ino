#include <Keypad.h>
#include <Keyboard.h>

const int tempoApertoBotao = 100;

const int ROW_NUM = 3; //four rows
const int COLUMN_NUM = 4; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','q'},
  {'4','5','6','w'},
  {'7','8','9','e'}
  //{'*','0','#'}
};

/*
{CAP,ALT,R,G},
  {EFF,EFF,PA','w'},
  {DETRE',LARG EXT,FLARE,LARGAGE}
*/
byte pin_rows[ROW_NUM] = {2,3,4}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5,6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void teclado(void) {

  int pin9 = !digitalRead(9); // bpz 
  int pin10 = !digitalRead(10); // tel 
  int pin16 = !digitalRead(16); // Fus
  int pin14 = !digitalRead(14); // 2
  int pin15 = !digitalRead(15); //Arm

  int state01 = 0;
  int state02 = 1;
  int state03 = 2;
  int state04 = 3;
  int state05 = 4;
  int state06 = 5;
  int state07 = 6;
  int state08 = 7;

  if (pin15 == 1 && lastButtonState[state07] != pin15) {
    //Keyboard.press(KEY_LEFT_CTRL);  //Keyboard.press(KEY_LEFT_SHIFT);  //Keyboard.press(' '); 
    delay(300);
    Keyboard.releaseAll();
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(' ');
    delay(300);
    Keyboard.releaseAll();
    Serial.println("Arm on");
    lastButtonState[state07] = pin15;
  }else if (pin15 == 0 && lastButtonState[state07] != pin15){
    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press(' ');
    delay(300);
    Keyboard.releaseAll();
    //Keyboard.press(KEY_LEFT_ALT);  //Keyboard.press(KEY_LEFT_CTRL);  //Keyboard.press(' '); 
    delay(300);
    Keyboard.releaseAll();
    Serial.println("Arm off");
    lastButtonState[state07] = pin15;
  }


  //Largage Switch
  //2
  if (pin14 == 1 && lastButtonState[state04] != pin14) {
    //Keyboard.press(KEY_RIGHT_SHIFT);    //Keyboard.press('j');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Largage - 2");
    lastButtonState[state04] = pin14;
    lastButtonState[state06] = 0;
  }else {
    lastButtonState[state04] = pin14;
  }
  //fus
  if (pin16 == 1 && lastButtonState[state05] != pin16) {
    //Keyboard.press(KEY_LEFT_SHIFT);    //Keyboard.press('j');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Largage - fus");
    lastButtonState[state05] = pin16;
    lastButtonState[state06] = 0;
  }else {
    lastButtonState[state05] = pin16;
  }
  //1
  if (pin16 == 0 && pin14 == 0 && lastButtonState[state06] != 1) {
    //Keyboard.press(KEY_RIGHT_CTRL);    //Keyboard.press('j');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("Largage - 1");
    lastButtonState[state06] = 1;
  }


  //______________________
  //Tel
  if (pin10 == 1 && lastButtonState[state01] != pin10) {
    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press(KEY_LEFT_SHIFT);    //Keyboard.press('z');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("TEL");
    lastButtonState[state01] = pin10;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state01] = pin10;
  }
  //Bpz
  if (pin9 == 1 && lastButtonState[state02] != pin9) {
    //Keyboard.press(KEY_LEFT_CTRL);    //Keyboard.press(KEY_LEFT_SHIFT);    //Keyboard.press('z');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("BPZ");
    lastButtonState[state02] = pin9;
    lastButtonState[state03] = 0;
  }else {
    lastButtonState[state02] = pin9;
  }
  //center
  if (pin10 == 0 && pin9 == 0 && lastButtonState[state03] != 1) {
    //Keyboard.press(KEY_LEFT_ALT);    //Keyboard.press(KEY_LEFT_GUI);    //Keyboard.press('z');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Serial.println("CENTER");
    lastButtonState[state03] = 1;
  }

}  

void setup(){
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  Keyboard.begin();
  //Keypad.begin();
  Serial.begin(9600);
}

void loop(){

  //delay(400);

  teclado();

  char key = keypad.getKey(); //KEY_SPACE   KEY_LEFT_GUI

  if (key == '6'){ //PA
    Serial.println(key);
    //Keyboard.press(KEY_RIGHT_SHIFT); //Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }else if (key == '1'){ //CAP
    Serial.println(key);
    //Keyboard.press(KEY_LEFT_CTRL); //Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();;
  }else if (key == '2'){ //ALT
    Serial.println(key);
    //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }else if (key == '3'){ //R
    Serial.println(key);
    //Keyboard.press(KEY_LEFT_ALT); //Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }else if (key == 'q'){ //G
    Serial.println(key);
    //Keyboard.press(KEY_RIGHT_ALT); //Keyboard.press('p');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }

  if (key == '4' || key == '5'){ //EFF.
    Serial.println(key);
    //Keyboard.press(KEY_LEFT_CTRL); //Keyboard.press(KEY_LEFT_GUI); //Keyboard.press('w');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }

  if (key == '9'){ //Flare
    Serial.println(key);
    //Keyboard.press('d');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }

  if (key == '8'){ //Matra Jett - Larg ext
    Serial.println(key);
    //Keyboard.press(KEY_LEFT_CTRL); //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('`');
    delay(300);
    Keyboard.releaseAll();
    //Keyboard.press('`');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
  }

  if (key == '7'){ //Emergence jett - Detre
    Serial.println(key);
    //Keyboard.press(KEY_LEFT_CTRL); //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('j');
    delay(300);
    Keyboard.releaseAll();
    //Keyboard.press(KEY_LEFT_CTRL); //Keyboard.press('j');
    delay(500);
    Keyboard.releaseAll();
  }

  if (key == 'e'){ //Select Jett - Largage
    Serial.println(key);
    //Keyboard.press(KEY_RIGHT_CTRL); //Keyboard.press(KEY_RIGHT_SHIFT); //Keyboard.press('j');
    delay(300);
    Keyboard.releaseAll();
    //Keyboard.press(KEY_LEFT_ALT); //Keyboard.press('j');
    delay(500);
    Keyboard.releaseAll();
  }

}
