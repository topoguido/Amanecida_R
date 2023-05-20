#include <IRremote.h>
decode_results IR;
IRsend Emisor_IR;



void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(10000);
  IR.bits = 28 ;
  IR.value = 142607107; //enciende frio calor a 18 grados
  //IR.value = 143392849; //apaga el aire
  Serial.println("Lectura - Tipo: " + String(IR.decode_type) + " Bits: " + String(IR.bits) + " Value: " + String(IR.value));
 // Emisor_IR.sendNEC(IR.value, IR.bits);
  Emisor_IR.sendLG(IR.value, IR.bits);
  delay(3000);
  exit(0);
} 
