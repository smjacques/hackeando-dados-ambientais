/* firmware simplificado para o sensor de condutividade
Para c'odigo refinado visitar: http://www.c2o.pro.br/hackaguas/ar01s14.html
*/

byte electrode_1 = 7; //Pino eletrodo
byte electrode_2 = 8; //Pino eletrodo
int  reading_pin = 0; //Pino analógico para leitura
int  reading;         //Variável que armazena leituras
                                                        
void setup() 
{ 
  
  Serial.begin(9600);     
  pinMode(electrode_1, OUTPUT); 
  pinMode(electrode_2, OUTPUT);
}      

void loop()                    
{ 
   
  digitalWrite(electrode_2, HIGH ); //Colocar eletrodo 2 como polo positivo (5V)
  digitalWrite(electrode_1, LOW);   //Colocar eletrodo 1 como polo negativo (0V)
  delay(100);                         //Aguardar estabilização
  reading = analogRead(reading_pin);  //Medir tensão entre o divisor de voltagem
  digitalWrite(electrode_2, LOW);     //Desligar eletrodo 1
  Serial.println(reading);
  delay(500);
} 
