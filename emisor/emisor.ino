#include <IRremote.h>
#include "DHT.h"

#define DTHPIN 2
#define DHTTYPE DHT11

decode_results IR;
IRsend Emisor_IR;

unsigned long OffValue = 143392849;
unsigned long OnValueFC18 = 142607107;

float temp;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  Serial.begin(9600);
  dht.begin();
  IR.bits = 28;
}

void loop() {

  delay(10000);
  
  //IR.value = 142607107; //enciende frio calor a 18 grados
  
  temp = dht.readTemperature();

  if(temp >= 19)
  {
    IR.value = OnValueFC18;
    Emisor_IR.sendLG(IR.value, IR.bits);
    exit(0);
  }
  if(temp <=11)
  {
    IR.value = OnValueFC18;
    Emisor_IR.sendLG(IR.value, IR.bits);
    delay(600000);
    IR.value = OffValue;
    Emisor_IR.sendLG(IR.value, IR.bits);
  }
  
  //Serial.println("Lectura - Tipo: " + String(IR.decode_type) + " Bits: " + String(IR.bits) + " Value: " + String(IR.value));
 
} 
