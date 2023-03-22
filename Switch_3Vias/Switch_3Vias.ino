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

void pressButton(int numBotao) {
  Joystick.pressButton(numBotao);
  delay(tempoApertoBotao);
  Joystick.releaseButton(numBotao);
}

void loop() {

  int currentButtonStateA0 = !digitalRead(A0);
  int currentButtonStateA1 = !digitalRead(A1);

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
