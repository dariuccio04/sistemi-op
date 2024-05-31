#include <stdio.h>
#include <stdlib.h>

/*Si scriva un programma che riceve base e altezza di un triangolo da riga di comando e stampa la sua area. Base e
altezza sono numeri con virgola
*/

typedef struct triangolo{
  float base;
  float altezza;
  float area;
} triangolo;

//inculata: gli argomenti passati tramite argv, sono stringhe quindi devi convertire tutto

//non ho fatto i controlli di input, volevo solo ripassare la struct

int main(int argc, char *argv[]) {
  triangolo shell;
  shell.base = atof(argv[1]);
  shell.altezza = atof(argv[2]);
  shell.area = (shell.base * shell.altezza) /2;
  printf("%f", shell.area);
  return 0;
}