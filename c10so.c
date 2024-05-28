#include <stdio.h>

// esercizi sscanf e sprintf



int main(void) {
  char s[] = "314";
  int i;
  sscanf(s,"%d", &i);
  /*
  s: La stringa da cui leggere i dati.
  %d: La stringa di formato che specifica come leggere i dati.
  i: Gli indirizzi delle variabili dove memorizzare i dati letti.
    */
  printf("%d", i);
  /*
  se la sscanf prende i valori dalla stringa e mette tutto dentro alla variabile i, la sprintf prende il valore di i e lo mette nella stringa



    */
  char s1[100];
  int i1 = 100;
  sprintf(s1, "%d", i1);
  /*
  s1 è il contenitore
  "%d" èil tipo che stiamo convertendo
  i1 è da dove prendiamo i dati


   non puoi solo passare valori, ma puoi utilizzarlo come printf che invece di stampare su un terminale stampa su un buffer
    */
  return 0;
}