#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc,char ** argv) {
  char str[10];
  int n;
  n = atoi(argv[1]) -1;
  /*

La funzione atoi() in C converte una stringa che rappresenta un numero intero in un valore intero di tipo int
  */
  printf("%d\n", n);
  if(n>0){
    sprintf(str, "%d", n);
    //scrive l'output formattato in una stringa
    /*
     È simile a printf(), ma invece di stampare l'output su stdout (di solito il terminale), scrive l'output formattato in una stringa.
    */
    execl(argv[0], argv[0], str, NULL);
    /* argv[0] è utilizzato come nome del programma da eseguire, str è un altro argomento che verrà passato al programma, e NULL indica la fine della lista degli argomenti.*/
  }
  printf("END");
  return 1;
}


/*
 eseguiamo il codice passando un numero, viene riconosciuto come stringa ma con atoi viene riconosciuto come intero, se il numero è >0 allora con sprintf, l'output "n" che è riconosciuto come intero viene messo su str, con exec andremo a richiamare il programma "argv[0]" passando come argomento la str ogni volta minorata di 1



*/