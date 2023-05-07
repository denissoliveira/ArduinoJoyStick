#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 4
#define NUMCOLS 5

//define the symbols on the buttons of the keypads  
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4','5'},
  {'6','7','8','9','0'},
  {'q','w','e','r','t'},
  {'a','s','d','f','g'}
};

byte rowPins[NUMROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {6,7,8,10,16}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS); 

const int tempoApertoBotao = 150;
int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void setup() {
  Serial.begin(9600);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() { 
  CheckAllButtons();
  CheckSwithsButtons();
  delay(10);
}

void CheckSwithsButtons(void) {
  int pin14 = !digitalRead(14); 
  int pin15 = !digitalRead(15); 


  int state01 = 0;
  int state02 = 1;
  int state03 = 2;
  int state04 = 3;

  if (pin14 == 1 && lastButtonState[state01] != pin14) {
    Keyboard.press('0');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    ////Serial.println("Arm off");
    lastButtonState[state01] = pin14;
  }else if (pin14 == 0 && lastButtonState[state01] != pin14){
    Keyboard.press('0');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    Keyboard.press(KEY_LEFT_CTRL);Keyboard.press('6');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    ////Serial.println("Arm on");
    lastButtonState[state01] = pin14;
  }

  if (pin15 == 1 && lastButtonState[state02] != pin15) {
    Keyboard.press('-');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    ////Serial.println("Jett on");
    lastButtonState[state02] = pin15;
  }else if (pin15 == 0 && lastButtonState[state02] != pin15){
    Keyboard.press('-');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    ////Serial.println("Jett Off");
    lastButtonState[state02] = pin15;
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
                              ////Serial.println("HOLD");
                              break;
                    case RELEASED:
                              Keyboard.releaseAll();
                              //Serial.println("RELEASED");
                              break;
                    case IDLE:
                              ////Serial.println("IDLE");
                              break;
            }
           }   
         }
     }
}


char tecladoKeypadMatrix(char key) {

  //Arms
  if (key == '1'){
    //Serial.println("Weapons Store 5");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('5');
    delay(tempoApertoBotao);
    
  }
  if (key == '2'){
    //Serial.println("Weapons Store 1");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('1');
    delay(tempoApertoBotao);
    
  }
  if (key == '3'){
    //Serial.println("Weapons Store 4");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('4');
    delay(tempoApertoBotao);
    
  }
  if (key == '4'){
    //Serial.println("Weapons Store 3");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('3');
    delay(tempoApertoBotao);
    
  }
  if (key == '5'){
    //Serial.println("Weapons Store 2");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('2');
    delay(tempoApertoBotao);
    
  }
  if (key == '6'){
    //Serial.println("PCA 5");
    Keyboard.press('5');
    delay(tempoApertoBotao);
    
  }
  if (key == '7'){
    //Serial.println("PCA 1");
    Keyboard.press('1');
    delay(tempoApertoBotao);
    
  }
  if (key == '8'){
    //Serial.println("PCA 4");
    Keyboard.press('4');
    delay(tempoApertoBotao);
    
  }
  if (key == '9'){
    //Serial.println("PCA 3");
    Keyboard.press('3');
    delay(tempoApertoBotao);
    
  }
  if (key == '0'){
    //Serial.println("PCA 2");
    Keyboard.press('2');
    delay(tempoApertoBotao);
    
  }
  if (key == 'q'){
    //Serial.println("q");
    Keyboard.press(KEY_RIGHT_CTRL); Keyboard.press('p');
    delay(tempoApertoBotao);
    
  }
  if (key == 'w'){
    //Serial.println("Altitude Hold");
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('a');
    delay(tempoApertoBotao);
  }
  if (key == 'e'){
    //Serial.println("e");
    //Keyboard.press('0');
    delay(tempoApertoBotao);
  }
  if (key == 'r'){
    //Serial.println("r");
    //Keyboard.press('0');
    delay(tempoApertoBotao);
  }
  if (key == 't'){
    //Serial.println("t");
    //Keyboard.press('0');
    delay(tempoApertoBotao);
  }
  if (key == 'a'){
    //Serial.println("Atitude Hold");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('a');
    delay(tempoApertoBotao);
  }
  if (key == 's'){
    //Serial.println("AG Gun");
    Keyboard.press(KEY_LEFT_CTRL);Keyboard.press('0');
    delay(tempoApertoBotao);
    
  }
  if (key == 'd'){
    //Serial.println("Autopilot");
    Keyboard.press('a');
    delay(tempoApertoBotao);
    
  }
  if (key == 'f'){
    //Serial.println("WayPoint next");
    Keyboard.press('n');
    delay(tempoApertoBotao);
    
  }
  if (key == 'g'){
    //Serial.println("WayPoint previus");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('n');
    delay(tempoApertoBotao);
    
  }
  return key;
}
