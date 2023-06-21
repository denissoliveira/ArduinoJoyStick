#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 5
#define NUMCOLS 6

//define the symbols on the buttons of the keypads  
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4','5','y'},
  {'6','7','8','9','0','u'},
  {'q','w','e','r','t','i'},
  {'a','s','d','f','g','o'},
  {'z','x','c','v','b','p'}
};

byte rowPins[NUMROWS] = {2,4,6,8,10}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {3,5,7,9,16,14}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS); 

const int tempoApertoBotao = 150;
int lastButtonState[13] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void setup() {
  Serial.begin(9600);
  pinMode(15, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() { 
  CheckAllButtons();
  CheckSwithsButtons();
  delay(10);
}

void CheckSwithsButtons(void) {
  int pin15 = !digitalRead(15); 
  int pin18 = !digitalRead(18); 
  int pin19 = !digitalRead(19); 

  if (pin15 == 1 && lastButtonState[0] != pin15) {
    Keyboard.press(KEY_LEFT_CTRL);    Keyboard.press('f');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Flaps Up");
    lastButtonState[0] = pin15;
    lastButtonState[2] = 0;
  }else {
    lastButtonState[0] = pin15;
  }
  if (pin18 == 1 && lastButtonState[1] != pin18) {
    Keyboard.press(KEY_LEFT_SHIFT);    Keyboard.press('f');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Flaps Landing");
    lastButtonState[1] = pin18;
    lastButtonState[2] = 0;
  }else {
    lastButtonState[1] = pin18;
  }
  if (pin18 == 0 && pin15 == 0 && lastButtonState[2] != 1) {
    Keyboard.press('f');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Flaps Donw");
    lastButtonState[2] = 1;
  }

  if (pin19 == 1 && lastButtonState[3] != pin19) {
    Keyboard.press(KEY_LEFT_CTRL);  Keyboard.press('c');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("canopy");
    lastButtonState[3] = pin19;
  }else if (pin19 != 1 && lastButtonState[3] != pin19) {
    Keyboard.press(KEY_LEFT_CTRL);  Keyboard.press('c');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("canopy");
    lastButtonState[3] = pin19;
  }

}  

void CheckAllButtons(void) {
      if (keypad.getKeys()) {
       for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
           if ( keypad.key[i].stateChanged )   // Only find keys that have changed state.
            {
            switch (keypad.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                              tecladoKeypadMatrix(keypad.key[i].kchar);
                              //Serial.println("PRESSED");
                              break;
                    case HOLD:
                              //Serial.println("HOLD");
                              break;
                    case RELEASED:
                              Keyboard.releaseAll();
                              //Serial.println("RELEASED");
                              break;
                    case IDLE:
                              //Serial.println("IDLE");
                              break;
            }
           }   
         }
     }
}


char tecladoKeypadMatrix(char key) {

  //Arms
  if (key == '1'){
    Serial.println("Dragging Chute");
    Keyboard.press('p');
    delay(tempoApertoBotao);
    
  }
  if (key == '2'){
    Serial.println("Cut of Burst");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('c');
    delay(tempoApertoBotao);
    
  }
  if (key == '3'){
    //Serial.println("Auto Altitude");
    Keyboard.press('h'); //Keyboard.press('4');
    delay(tempoApertoBotao);
    
  }
  if (key == '4'){
    //Serial.println("Auto desconect");
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('9');
    delay(tempoApertoBotao);
    
  }
  if (key == '5'){
    //Serial.println("Auto Atitude");
    Keyboard.press('a');
    delay(tempoApertoBotao);
    
  }
  if (key == '6'){
    //Serial.println("Weapons Jettison");
    Keyboard.press(KEY_LEFT_CTRL);Keyboard.press('w');
    delay(tempoApertoBotao);
    
  }
  if (key == '7'){
    //Serial.println("Weapons Launch override");
    Keyboard.press(KEY_LEFT_ALT);Keyboard.press('w');
    delay(tempoApertoBotao);
    
  }
  if (key == '8'){
    //Serial.println("Ripple -");
    Keyboard.press(KEY_LEFT_SHIFT);Keyboard.press('v');
    delay(tempoApertoBotao);
    
  }
  if (key == '9'){
    //Serial.println("Weapons Change");
    Keyboard.press('d');
    delay(tempoApertoBotao);
    
  }
  if (key == '0'){
    //Serial.println("Ripple +");
    Keyboard.press('v');
    delay(tempoApertoBotao);
    
  }
  if (key == 'q'){
    //Serial.println("Flare");
    Keyboard.press(KEY_DELETE); //Keyboard.press('p');
    delay(tempoApertoBotao);
    
  }
  if (key == 'w'){
    //Serial.println("Chaff");
    Keyboard.press(KEY_INSERT); //Keyboard.press(KEY_LEFT_SHIFT); //Keyboard.press('a');
    delay(tempoApertoBotao);
  }
  if (key == 'e'){
    //Serial.println("Ripple Quant");
    Keyboard.press(KEY_LEFT_CTRL);Keyboard.press(' ');
    delay(tempoApertoBotao);
  }
  if (key == 'r'){
    //Serial.println("Salvo mode");
    Keyboard.press(KEY_LEFT_CTRL);Keyboard.press('v');
    delay(tempoApertoBotao);
  }
  if (key == 't'){
    Serial.println("t");
    ////Keyboard.press('0');
    delay(tempoApertoBotao);
  }
  if (key == 'a'){
    //Serial.println("Night Vision Flir");
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press('o');
    delay(tempoApertoBotao);
  }
  if (key == 's'){
    //Serial.println("Laser Designator Ranger");
    Keyboard.press(KEY_RIGHT_SHIFT);Keyboard.press('o');
    delay(tempoApertoBotao);
    
  }
  if (key == 'd'){
    //Serial.println("Target Spec Size -");
    Keyboard.press(KEY_RIGHT_ALT);Keyboard.press('-');
    delay(tempoApertoBotao);
    
  }
  if (key == 'f'){
    Serial.println("Jettison Fuel Tanks");
    Keyboard.press(KEY_LEFT_ALT);Keyboard.press('r');
    delay(tempoApertoBotao);
    
  }
  if (key == 'g'){
    //Serial.println("Target Spec Size +");
    Keyboard.press(KEY_RIGHT_ALT);Keyboard.press('=');
    delay(tempoApertoBotao);
    
  }
  if (key == 'z'){
    //Serial.println("Radar ELINT Pod");
    Keyboard.press('i');
    delay(tempoApertoBotao);
  }
  if (key == 'x'){
    //Serial.println("Radar Pulse Repeat Freq");
    Keyboard.press(KEY_RIGHT_SHIFT); Keyboard.press('i');
    delay(tempoApertoBotao);
  }
  if (key == 'c'){
    //Serial.println("Target Range +");
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press('=');
    delay(tempoApertoBotao);
    
  }
  if (key == 'v'){
    //Serial.println("Target Range -");
    Keyboard.press(KEY_RIGHT_CTRL);Keyboard.press('-');
    delay(tempoApertoBotao);
    
  }
  if (key == 'b'){
    Serial.println("b");
    //Keyboard.press('n');
    delay(tempoApertoBotao);
    
  }
  if (key == 'y'){
    //Serial.println("Cannon");
    Keyboard.press('c');
    delay(tempoApertoBotao);
  }
  if (key == 'u'){
    //Serial.println("Weapons PRS/SGL");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(' ');
    delay(tempoApertoBotao);
  }
  if (key == 'i'){
    //Serial.println("ECM");
    Keyboard.press('e');
    delay(tempoApertoBotao);
    
  }
  if (key == 'o'){
    //Serial.println("Electro Optical / CCRP");
    Keyboard.press('o');
    delay(tempoApertoBotao);
    
  }
  if (key == 'p'){
    //Serial.println("Radar RWS/TWS");
    Keyboard.press(KEY_RIGHT_ALT);Keyboard.press('i');
    delay(tempoApertoBotao);
    
  }

  return key;
}
