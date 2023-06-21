#include <Keypad.h>
#include <Keyboard.h>

#define NUMROWS 5
#define NUMCOLS 6

// 5 x 6 -> 2 - 14 ->   A0 A1 A2 e 15
char keys[NUMROWS][NUMCOLS] = {
  {'1','2','3','4','5','y'},
  {'6','7','8','9','0','u'},
  {'q','w','e','r','t','i'},
  {'a','s','d','f','g','o'},
  {'z','x','c','v','b','p'}
};

byte rowPins[NUMROWS] = {2,3,4,5,6}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {7,8,9,10,16,14}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, NUMROWS, NUMCOLS); 

const int tempoApertoBotao = 150;
int lastButtonState[12] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

void setup() {
  Serial.begin(9600);
  pinMode(15, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
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
  int pin20 = !digitalRead(20); 

  if (pin15 == 1 && lastButtonState[0] != pin15) {
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('o');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Bomb-bay Open");
    lastButtonState[0] = pin15;
  }else if (pin15 == 0 && lastButtonState[0] != pin15){
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('o');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Bomb-bay close");
    lastButtonState[0] = pin15;
  }

  if (pin18 == 1 && lastButtonState[1] != pin18) {
    Keyboard.press('h');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Hook on");
    lastButtonState[1] = pin18;
  }else if (pin18 == 0 && lastButtonState[1] != pin18){
    Keyboard.press('h');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Hook off");
    lastButtonState[1] = pin18;
  }

  if (pin19 == 1 && lastButtonState[2] != pin19) {
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('j');
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Jettison");
    lastButtonState[2] = pin19;
  }else if (pin19 == 0 && lastButtonState[2] != pin19){
    lastButtonState[2] = pin19;
  }

  if (pin20 == 1 && lastButtonState[3] != pin20) {
    Keyboard.press(KEY_LEFT_CTRL); delay(tempoApertoBotao);
    Keyboard.press(KEY_PAGE_UP); delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar on");
    lastButtonState[3] = pin20;
  }else if (pin20 == 0 && lastButtonState[3] != pin20){
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_PAGE_UP);
    delay(tempoApertoBotao);
    Keyboard.releaseAll();
    //Serial.println("Radar off");
    lastButtonState[3] = pin20;
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
                              ////Serial.println("PRESSED");
                              break;
                    case HOLD:
                              ////Serial.println("HOLD");
                              break;
                    case RELEASED:
                              Keyboard.releaseAll();
                              ////Serial.println("RELEASED");
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
    //Serial.println("1 Wing Leveler");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('a');
    delay(tempoApertoBotao);
    
  }
  if (key == '2'){
    //Serial.println("2 Waypoint -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('w');
    delay(tempoApertoBotao);
    
  }
  if (key == '3'){
    //Serial.println("3 Autopilot");
    Keyboard.press('a');
    delay(tempoApertoBotao);
    
  }
  if (key == '4'){
    //Serial.println("4 Jump neext Encounter");
    Keyboard.press(KEY_LEFT_ALT); Keyboard.press('n');
    delay(tempoApertoBotao);
    
  }
  if (key == '5'){
    //Serial.println("5 EJECT");
    delay(500);
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(KEY_ESC);
    delay(tempoApertoBotao);
    
  }
  if (key == '6'){
    //Serial.println("6 Radar mode +");
    Keyboard.press(KEY_PAGE_UP);
    delay(tempoApertoBotao);
    
  }
  if (key == '7'){
    //Serial.println("7 Radar target - ");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(KEY_HOME);
    delay(tempoApertoBotao);
    
  }
  if (key == '8'){
    //Serial.println("8 Radar mode -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(KEY_PAGE_UP);
    delay(tempoApertoBotao);
    
  }
  if (key == '9'){
    //Serial.println("9 Radar rander -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(KEY_PAGE_DOWN);
    delay(tempoApertoBotao);
    
  }
  if (key == '0'){
    //Serial.println("0 Radar target + ");
    Keyboard.press(KEY_HOME);
    delay(tempoApertoBotao);
    
  }
  if (key == 'q'){
    //Serial.println("q Engine");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('i');
    delay(tempoApertoBotao);
    
  }
  if (key == 'w'){
    //Serial.println("w Chaff");
    Keyboard.press('c');
    delay(tempoApertoBotao);
  }
  if (key == 'e'){
    //Serial.println("e Nav light");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('l');
    delay(tempoApertoBotao);
  }
  if (key == 'r'){
    //Serial.println("r Flare");
    Keyboard.press('x');
    delay(tempoApertoBotao);
  }
  if (key == 't'){
    //Serial.println("t Drop Tanks");
    Keyboard.press(KEY_LEFT_CTRL); Keyboard.press('d');
    delay(tempoApertoBotao);
  }
  if (key == 'a'){
    //Serial.println("a Air-Air +");
    Keyboard.press(KEY_BACKSPACE);
    delay(tempoApertoBotao);
  }
  if (key == 'g'){
    //Serial.println("g Gun Mode +");
    Keyboard.press(';');
    delay(tempoApertoBotao);
    
  }
  if (key == 's'){
    //Serial.println("s Gun Mode -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(';');
    delay(tempoApertoBotao);
    
  }
  if (key == 'd'){
    //Serial.println("d Air-Air -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(KEY_BACKSPACE);
    delay(tempoApertoBotao);
    
  }
  if (key == 'z'){
    //Serial.println("z Air-gnd +");
    Keyboard.press('\\');
    delay(tempoApertoBotao);
  }
  if (key == 'x'){
    //Serial.println("x Ripple qnt -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(']');
    delay(tempoApertoBotao);
    
  }
  if (key == 'c'){
    //Serial.println("c Air-gnd -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('\\');
    delay(tempoApertoBotao);
    
  }
  if (key == 'v'){
    //Serial.println("v Ripple int -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('[');
    delay(tempoApertoBotao);
    
  }
  if (key == 'b'){
    //Serial.println("b Ripple qnt +");
    Keyboard.press(']');
    delay(tempoApertoBotao);

  } 

  if (key == 'y'){
    //Serial.println("y Waypoint +");
    Keyboard.press('w');
    delay(tempoApertoBotao);

  }
  if (key == 'u'){
    //Serial.println("u Radar rander +");
    Keyboard.press(KEY_PAGE_DOWN);
    delay(tempoApertoBotao);

  } 
  if (key == 'i'){
    //Serial.println("i ECM");
    Keyboard.press('z');
    delay(tempoApertoBotao);

  } 
  if (key == 'o'){
    //Serial.println("o Gunsight +");
    Keyboard.press('\'');
    delay(tempoApertoBotao);

  } 
  if (key == 'f'){
    //Serial.println("f Gunsight -");
    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('\'');
    delay(tempoApertoBotao);
    
  }
  if (key == 'p'){
    //Serial.println("p Ripple int +");
    Keyboard.press('[');
    delay(tempoApertoBotao);

  } 
  return key;
}
