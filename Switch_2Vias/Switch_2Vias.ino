#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   3, 0,                  // Button Count, Hat Switch Count
                   false, false, false,   // X and Y, but no Z Axis
                   false, false, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering

int lastButtonState[3] = { 0, 0, 0 };
int lastButtonStateSize = sizeof(lastButtonState) / sizeof(int);

//Somente para ficar mais legivel qual botão é do joystick
int button[3] = { 0, 0, 1 };

const int tempoApertoBotao = 250;

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

void setup() {
  pinMode(0, INPUT_PULLUP);
  Serial.begin(9600);
  Joystick.begin();
}

void loop() {

  int pin0 = !digitalRead(0);

  Serial.println(pin0);
  pressButton2Way(pin0, button[1], 0);

  //for (int i = 0; i < lastButtonStateSize; i++) {
  //}
  
}
