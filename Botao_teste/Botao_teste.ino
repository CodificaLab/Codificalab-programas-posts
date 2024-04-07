/* 
* Código por: Codificalab 
* Autores: Gustavo Wong, Marcos Santana
*
*   Primeiro programa de teste com o ESP32
* Neste programa será realizado a confecção de um pequeno
* circuito que integra o ESP32 junto a um botão. O intuito
* deste exemplo é apenas demonstrar o funcionamento básico
* da IDE Arduino e a programação no ESP32.
*/

#define btn_1 23    // Definindo no código uma variável de valor fixo, correspondente ao pino do ESP32 que será utilizado para fazer a leitura do botão.
bool pressionado;   // Esta variável guardará o status de acionamento do botão.
int vezes=0;        // Esta variável armazenará o número de vezes que o botão foi pressionado.


void setup() {

  Serial.begin(115200);   // Aqui definimos a velocidade da comunicação serial entre o ESP e o computador
  pinMode(btn_1, INPUT);  // Neste parâmetro definimos qual pino do ESP será utilizado e que tipo de função ele terá (Input ou Output).

}

void loop() {

  pressionado=digitalRead(btn_1);       // Nesse comando, estamos informando que o ESP deverá realizar uma leitura sobre a pinagem definida como uma entrada.
  if(pressionado!=0){                   // Caso o ESP realize a leitura de entrada no botão, ou seja, caso pressione o botão no circuito, entraremoss nesta condição para seguir uma sequência de instruções.
    vezes++;                            // Estamos somando +1 na variável para armazenar o número de vezes que o botão foi acionado.
    Serial.print("Vezes pressionado: ");// Vamos exibir uma mensagem para informar o evento
    Serial.println(vezes);              // Exibindo o número de vezes pressionado
    delay(350);                         // Uma pequena pausa no ESP para executar a leitura do botão
  }

}
