#include <stdio.h>
#include <stdint.h>

/*
le union sono delle struct tirchie

  */
union student{
  uint64_t tessera_sanitaria;
  /*
Questo tipo di dato è utilizzato per garantire che le variabili abbiano una dimensione specifica, indipendentemente dall'implementazione del compilatore o dalla piattaforma.
(intero senza segno a 64 bit)
  
*/
uint32_t matricola;
};


int main(int argc, char *argv[]) {
  union student luca;
  luca.matricola = 1234;
// 00000000 00000000 00000100 11010010
  printf("Matricola: %d\n"
  , luca.matricola);
  luca.tessera_sanitaria = 2897189786;
  // 10101100110111100011101101101010
  /* Usare il formato %ld essendo in intero lungo */
  printf("Tessera Sanitaria: %ld\n"
  , luca.tessera_sanitaria);
  return 0;
  }