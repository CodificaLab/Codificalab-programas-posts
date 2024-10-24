/*********
  Este código permite medir distância com o sensor ultrassônico HC-SR04,
  enviando os dados de medição para o display OLED SSD1306.
*********/

// carrega bibliotecas

#include <Wire.h>  // Biblioteca para usar I2C
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // Largura do display OLED, em pixels
#define SCREEN_HEIGHT 64 // Altura do display OLED, em pixels
// Para conectar o SSD1306 display ao I2C (pinos SDA e SCL) 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int trigPin = 18;
const int echoPin = 5;

//define a velocidade do som em cm/uS
#define SOUND_SPEED 0.034


long duration;
float distanceCm;
float distanceInch;

void setup() {
  /// setup do display
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C é o endereço no barramento I2C
    Serial.println(("SSD1306 falha"));
    for(;;);
  }
  delay(2000);
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  /// fim setup do display
  
  Serial.begin(115200); // Inicia a comunicação serial
  pinMode(trigPin, OUTPUT); // Ajusta trigPin como saída
  pinMode(echoPin, INPUT); // Ajusta echoPin como entrada
}

void loop() {
  // limpa trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Mantem trigPin em estado HIGH por 10 microssegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lê o echoPin, retorna o tempo de viagem da onda sonora em microssegundos
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância
  distanceCm = duration * SOUND_SPEED/2;
  
  // Imprime a distância no monitor serial
  Serial.print("Distancia (cm): ");
  Serial.println(distanceCm);

  // Escrita no display
  
  display.clearDisplay();
  display.setCursor(0, 10); // posição da próxima escrita (coluna, linha)
  display.print("Dist: ");
  display.print(distanceCm);
  display.print(" cm");
  display.display(); 
  
  delay(1000);
}
