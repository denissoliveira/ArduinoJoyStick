#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   3, 0,                  // Button Count, Hat Switch Count
                   false, false, false,   // X and Y, but no Z Axis
                   false, false, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering


void setup() {
  // Initialize Button Pins
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  Serial.begin(9600);

  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int tempoApertoBotao = 50;
// Last state of the button
int lastButtonState[3] = { 0, 0, 0 };
int lastButtonStateSize = sizeof(lastButtonState) / sizeof(int);
byte buttons[NUMROWS][NUMCOLS] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15},
  {16,17,18,19},
  {20,21,22,23}
};
byte rowPins[NUMROWS] = {2, 3, 4, 5, 6, 7}; //connect to the row pinouts of the keypad
byte colPins[NUMCOLS] = {10, 16, 14, 15}; //connect to the column pinouts of the keypad

void pressButton(int numBotao) {
  Joystick.pressButton(numBotao);
  delay(tempoApertoBotao);
  Joystick.releaseButton(numBotao);
}

void pressButton2Way(int pinState, int joyButton, int lastButtonStateNumb) {
  if (pinState == 1 && lastButtonState[lastButtonStateNumb] != pinState) {
    pressButton(joyButton);
    lastButtonState[lastButtonStateNumb] = pinState;
  }else {
    lastButtonState[lastButtonStateNumb] = pinState;
  }
}

void pressButton3Way(int porta1, int porta2, int lastButtonStateNumb) {
  int currentButtonStateA0 = !digitalRead(porta1);
  int currentButtonStateA1 = !digitalRead(porta2);

  for (int i = 0; i < lastButtonStateSize; i++) {
    if (currentButtonStateA0 == 1 && lastButtonState[0] == 0) {
      pressButton(0);
      lastButtonState[0] = currentButtonStateA0;
      lastButtonState[1] = 0;
      lastButtonState[2] = 0;
    }else if (currentButtonStateA0 != 1 && currentButtonStateA1 != 1 && lastButtonState[1] == 0) {
      pressButton(1);
      lastButtonState[0] = 0;
      lastButtonState[1] = 1;
      lastButtonState[2] = 0;
    }else if (currentButtonStateA1 == 1 && lastButtonState[2] == 0) {
      pressButton(2);
      lastButtonState[0] = 0;
      lastButtonState[1] = 0;
      lastButtonState[2] = currentButtonStateA1;
    }
  }
}

void loop() {

  

}
