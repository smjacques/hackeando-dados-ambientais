#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN A1 // pino do dht
#define DHTTYPE DHT11 // Temperatura e umidade
DHT dht(DHTPIN, DHTTYPE); //definir dht com o que foi criado acima

//Temperatura H2O
#define ONE_WIRE_BUS 3
OneWire oneWire(ONE_WIRE_BUS);

float tempMin = 999; // Armazena temperaturas minima e maxima
float tempMax = 0;
 
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;

int val_umid = A2; // sensor de umidade

byte electrode_1 = 7; //Pino eletrodo
byte electrode_2 = 8; //Pino eletrodo
int  reading_pin = 0; //Pino analógico para leitura
int  reading;         //Variável que armazena leituras

void setup()
{
  Serial.begin(9600);
  pinMode(electrode_1, OUTPUT); 
  pinMode(electrode_2, OUTPUT);
    
  // Localiza e mostra enderecos dos sensores
  Serial.println("Testando DHT11");
  Serial.println("Localizando sensores DS18B20...");
  Serial.print("Foram encontrados ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" sensores.");
  Serial.println();

  dht.begin();
  sensors.begin();
}


void loop() {
  float h = dht.readHumidity(); // O atraso do sensor DHT11 pode chegar a 2 segundos.
  float t = dht.readTemperature();
  
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(sensor1);
  // Atualizar temperaturas minima e maxima
  if (tempC < tempMin)
  {
    tempMin = tempC;
  }
  if (tempC > tempMax)
  {
    tempMax = tempC;
  }


  int umidade_volt = analogRead(val_umid);
  int umidade = umidade_volt;
  umidade = constrain(umidade_volt,400,1023);
  umidade = map(umidade,400,1023,100,0);
 

  digitalWrite(electrode_2, HIGH ); //Colocar eletrodo 2 como polo positivo (5V)
  digitalWrite(electrode_1, LOW);   //Colocar eletrodo 1 como polo negativo (0V)
  delay(100);                         //Aguardar estabilização
  reading = analogRead(reading_pin);  //Medir tensão entre o divisor de voltagem
  digitalWrite(electrode_2, LOW);     //Desligar eletrodo 1

    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
    Serial.print("Temp C: ");
    Serial.print(tempC);
    Serial.print(" Min : ");
    Serial.print(tempMin);
    Serial.print(" Max : ");
    Serial.println(tempMax);
    Serial.println("Umidade (valor bruto)");
    Serial.println(umidade_volt);
    Serial.println("Umidade (%)");
    Serial.println(umidade);
    Serial.println("Condutividade (V)");
    Serial.println(reading);
  delay(500);

}
