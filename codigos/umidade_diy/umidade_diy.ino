int val_umid = 0; // sensor de umidade

void setup() {
Serial.begin(9600);
}

void loop() {
int umidade_volt = analogRead(val_umid);
int umidade = umidade_volt;
umidade = constrain(umidade_volt,400,1023);
umidade = map(umidade,677,1023,100,0);

Serial.println("Umidade (valor bruto)");
Serial.println(umidade_volt);
Serial.println("Umidade (%)");
Serial.println(umidade);
delay(6000);
}
