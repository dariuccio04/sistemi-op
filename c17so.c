#include <stdio.h>


//studio funzione fgetc, fgets, fscanf, feof

int main(void) {
  FILE *f = fopen("file.txt", "r");
  if(f==NULL){
    perror("errore di apertura");
    return 1;
  }

  //con la fgetc (fget-c -> carattere) vogliamo leggere ogni carattere
  //il suo ritorno standard è EOF
  int c;
  while( (c=fgetc(f)) != EOF ){
    putchar(c);
  }
  printf("\n");
  //con questo while, stiamo memorizzando ogni volta il valore di fgetc, ad ogni iterazione il cursore del file si sposta di una iterazione e questo ci permette di andare avanti
  //puthcar stampa il singolo carattere memorizzato in c
  //con rewind ci assicuriamo di spostare il puntatore all'inizio del file
  rewind(f);

  
  char buffer[100];
  while(fgets(buffer, sizeof(buffer), f) != NULL){
    //con fgets (fget -s -> stringa) invece prendiamo la stringa presente in f, e la memorizziamo in buffer
    //con sizeof intendiamo la memoria massima di buffer
    printf("%s", buffer);
  }
  printf("\n");
  rewind(f);

  int num;
  while(fscanf(f,"%d", &num) != EOF) {
    printf("%d\n",num);
    //con la fscanf andiamo a prendere dei dati dal file (f) e andiamo inserire tali dati nelle variabili dichiarate (num)
  }
  /*
  fgetc -> prende caratteri tramite cursore
  fgets -> prende stringe /////////////////
  fscanf -> prende valore che memorizza in variabili del codice
    */
  if (feof(f)){
    printf("fine del file");
  }
  // eof -> END OF FILE

  fclose(f);
  return 0;
}