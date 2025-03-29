#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "POCO X3 Pro";
const char* password = "papaiteamo";
WiFiClient client;

unsigned long myChannel = 2892148;
const char* APIKey = "XT7VJINKT938SAKN";

int pinread = 33;
int pinwrite = 32;

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

void setup() {
  // Inicializa comunicação serial na USB
  Serial.begin(9600);
  // set atenuação de 11 DB no ADC
  analogSetAttenuation(ADC_11db);

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);

  pinMode(pinread, INPUT);
  pinMode(pinwrite, OUTPUT);
  digitalWrite(pinwrite, HIGH);
}

void loop() {
  if((millis() - lastTime) > timerDelay) {
    if(WiFi.status() != WL_CONNECTED) {
      Serial.print("Tentando conectar");
      while(WiFi.status() != WL_CONNECTED) {
        WiFi.begin(ssid, password);
        delay(5000);
        Serial.print(".");
      }
      Serial.println("\nConectado!");
    }
    
    // reads the input on analog pin (value between 0 and 4095)
    int analogValue = analogRead(pinread);

    int resposta = ThingSpeak.writeField(myChannel, 1, analogValue, APIKey);

    if( resposta == 200) {
      Serial.println("Canal atualizado");
    }
    else {
      Serial.println("Problema na atualização do canal. Http Error "+String(resposta));
    }
  
    Serial.print("Analog Value = ");
    Serial.println(analogValue);   // Leitura crua do sensor
    Serial.println("Aguardando "+String(timerDelay)+"ms para nova leitura...");
    //delay(5000);
    lastTime = millis();
  }
}
