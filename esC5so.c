#include <stdio.h>


void sommaVett(float punto1x, float punto2x, float punto1y, float punto2y, float * ris_sx, float * ris_sy){
  *ris_sx = punto1x + punto2x;
  *ris_sy = punto1y + punto2y;
}



int main(void) {
  float punto1x = 1.1;
  float punto2x = 3.6;
  float punto1y = 2.0;
  float punto2y = 2.7;

  float ris_sx;
  float ris_sy;
  /*
  questo perchè vogliamo che il valore si ris_sx e ris_sy rimanga nel main anche chiamando una funzione esterna quindi dobbiamo per forza creare dei puntatore nella funzione esterna che andranno a prendere l'indirizzo di memoria di ris_sx e ris_sy

  anche se potevamo benissimo salvare il valore della somma in una variabile a parte ma ovviamente dovevamo chiamare due volte la funzione
    */

  sommaVett(punto1x,punto2x,punto1y,punto2y,&ris_sx, &ris_sy);
  printf("la somma vettoriale è: ( %f, %f)\n", ris_sx, ris_sy);
  return 0;
}