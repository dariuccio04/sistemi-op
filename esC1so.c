#include <stdio.h>

// Si scriva un programma che riceve il nome di un file da riga di comando e ne stampa il contenuto



int main(void) {
  FILE *f;
  f = fopen("media.txt", "r");
  if (f == NULL){
    return 1;
  }
  char buffer[100];
  while(fgets(buffer, sizeof(buffer),f) != NULL){
    /*
    stiamo andando su file, abbiamo il cursore che andrà avanti e ci salverà ogni stringa su buffer,
    buffer ad ogni iterazione verrà riscalato
    fino a NULL cioè quando arriviamo alla fine
    //ripassa il return EOF e NULL -> in base ai permessi e funzioni

    */
    printf("%s", buffer);
  }
  fclose(f);
  return 0;
}