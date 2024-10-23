#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>

// Definir a largura e altura do display OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Criar uma instância do display OLED (endereço I2C padrão 0x3C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Criar uma instância do sensor BMP180
Adafruit_BMP085 bmp;

void setup() {
  // Inicializar a comunicação serial
  Serial.begin(115200);

  // Inicializar o display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Falha ao inicializar o display SSD1306"));
    for (;;);
  }
  
  // Limpar o display
  display.clearDisplay();
  display.display();

  // Inicializar o sensor BMP180
  if (!bmp.begin()) {
    Serial.println(F("Falha ao inicializar o sensor BMP180"));
    for (;;);
  }

  // Exibir mensagem de inicialização
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Iniciando..."));
  display.display();
  delay(2000); // Aguardar 2 segundos antes de prosseguir
}

void loop() {
  // Limpar o display para atualizar as informações
  display.clearDisplay();

  // Ler dados do BMP180
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure();

  // Exibir temperatura e pressão no display OLED
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println(F("Temperatura:"));
  display.print(temperature);
  display.println(" C");

  display.println(F("Pressao:"));
  display.print(pressure / 100.0);
  display.println(" hPa");

  // Enviar os dados também para o monitor serial
  Serial.print(F("Temperatura: "));
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print(F("Pressao: "));
  Serial.print(pressure / 100.0);
  Serial.println(" hPa");

  // Atualizar o display com as novas informações
  display.display();
  
  // Aguardar 2 segundos antes de atualizar novamente
  delay(2000);
}