#include <math.h>

#define QUANT_BITS 8 //inserir quantidade de bits do contador
int pin_bit[QUANT_BITS] = {5, 6, 7, 8, 9, 10, 11, 12}; //inserir a porta de saida de cada bit no arduino do menos significante para o mais significante
int bit_value[QUANT_BITS];
int num_dec = 1;
int ct, dv;

void setup() {
  for(int i = 0; i < QUANT_BITS; i++) {
    pinMode(pin_bit[i], OUTPUT);
  }     
}

void loop() {  
  if(num_dec == 1 || num_dec == pow(2, QUANT_BITS)) {
    num_dec = 1;
    for(int i = 0; i < QUANT_BITS; i++) {
      if(i == 0) {
        bit_value[i] = 1;
      }
      else {
        bit_value[i] = 0;
      }
    }
  }
   
  ct = 0;
  dv = num_dec;
  while(dv > 1) {
    if((dv / 2) == 1) {
      bit_value[ct] = dv % 2;
      bit_value[ct + 1] = round(dv / 2);
    }
    else {
      bit_value[ct] = dv % 2;
    }  
      dv /= 2;
      ct++;
  }
    
  for(int i = 0; i < QUANT_BITS; i++) {
    if(bit_value[i] == 1) {
      digitalWrite(pin_bit[i], HIGH);
    }
    else {
      digitalWrite(pin_bit[i], LOW);
    }
  }
  
  delay(500); //inserir tempo de troca de um numero para outro em milisegundos
  num_dec++;
}
