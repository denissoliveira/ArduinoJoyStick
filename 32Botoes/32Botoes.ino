#include <Joystick.h>

// Define o tamanho da matriz de botões
const int numLinhas = 6;
const int numColunas = 6;

// Define os pinos digitais para as linhas e colunas dos botões
const int linhas[numLinhas] = {2, 3, 4, 5, 6, 7};
const int colunas[numColunas] = {8, 9, 10, 14, 15, 16};

Joystick_ joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   numLinhas*numColunas, 0,                  // Button Count, Hat Switch Count
                   false, false, false,   // X and Y, but no Z Axis
                   false, false, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering


// Cria uma matriz para representar a matriz de botões
int botoes[numLinhas][numColunas] = { 
                                      {0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0} 
                                    };

void setup() {
  // Configura os pinos digitais das linhas e colunas como entrada
  for (int i = 0; i < numLinhas; i++) {
    pinMode(linhas[i], INPUT_PULLUP);
  }
  for (int i = 0; i < numColunas; i++) {
    pinMode(colunas[i], INPUT_PULLUP);
  }

  // Inicializa a matriz de botões com os valores LOW
  for (int i = 0; i < numLinhas; i++) {
    for (int j = 0; j < numColunas; j++) {
      botoes[i][j] = LOW;
    }
  }
  Serial.begin(9600);
  // Inicializa o objeto Joystick
  joystick.begin();
}

void loop() {
  // Lê o estado dos botões e atualiza a matriz de botões
  for (int i = 0; i < numLinhas; i++) {
    // Configura a linha como saída em nível alto
    pinMode(linhas[i], OUTPUT);
    digitalWrite(linhas[i], HIGH);
    Serial.print(" i : ");Serial.println(i);
    // Lê o estado das colunas e atualiza a matriz de botões
    for (int j = 0; j < numColunas; j++) {
      Serial.print(" j : ");Serial.println(j);
      int estado = digitalRead(colunas[j]);
      Serial.print(" Estado : ");Serial.println(estado);
      if (estado != botoes[i][j]) {
        botoes[i][j] = estado;
        Serial.print(" Botao : ");Serial.println(i*numColunas+j);
        joystick.setButton(i*numColunas+j, estado);
      }
    }
    
    // Configura a linha como entrada
    pinMode(linhas[i], INPUT_PULLUP);
  }

  // Envia os valores da matriz de botões para o computador usando a biblioteca Joystick
  //joystick.sendState(botoes[0], numLinhas*numColunas*sizeof(int));
  
  // Aguarda um curto período de tempo para evitar o envio excessivo de dados
  delay(1000);

}
