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
  /*union student luca;
  luca.matricola = 1234;
// 00000000 00000000 00000100 11010010
  printf("Matricola: %d\n"
  , luca.matricola);
  luca.tessera_sanitaria = 2897189786;
  // 10101100110111100011101101101010
  // Usare il formato %ld essendo in intero lungo 
  printf("Tessera Sanitaria: %ld\n"
  , luca.tessera_sanitaria);
  */
  union student luca;
  luca.matricola = 1234;
  // Sovrascrivo luca.matricola
  luca.tessera_sanitaria = 2897189786;
  // Leggo correttamente tessera_sanitaria
  printf("Tessera Sanitaria: ld\n"
  , luca.tessera_sanitaria);
  // Leggo matricola, che è stata sovrascritta!
  printf("Matricola di Luca: %d\n"
  , luca.matricola);
  /*

  In C, una union è un tipo di dato che consente di memorizzare diversi tipi di dati nello stesso spazio di memoria. A differenza di una struct, dove ogni campo ha il proprio spazio di memoria, i campi di una union condividono la stessa area di memoria. Questo significa che l'assegnazione di un valore a un campo della union sovrascrive il contenuto degli altri campi, poiché tutti i campi utilizzano lo stesso spazio di memoria.


la union non può memorizzare contemporaneamente tutti e due
    */
  return 0;
  }