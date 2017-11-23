#include "DHT.h"

#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11  // Definimos que tipo de sensor vamos usar
/*
Definimos que tipo de sensor vamos usar (no caso de uso de DHT22 se troca DHT11 por DHT22)
*/

//Criamos um objeto de tipo DHT e recebemos os parametros que inserimos acima.
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.println("Testando DHT11");
  dht.begin();
}

void loop() 
{
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();

// testar se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Falha ao ler do DHT");
  } 
  else 
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
}
