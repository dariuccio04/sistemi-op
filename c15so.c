#include <stdio.h>

/*
Esempio: si legga un path da tastiera e se ne stampi il contenuto come file di testo

*/




int main(void) {
  char s[100];
  //andremo a memorizzare il nostro path
  char buffer[100];
  //andremo a memorizzare in buffer ogni stringa del file

  FILE * f;
  printf("inserisci un path: ");
  scanf("%s", s);
  /*
Al posto di scanf("%s", s);, che può essere rischioso se l'input dell'utente eccede la dimensione dell'array s, possiamo usare fgets per una lettura più sicura. fgets permette di specificare un limite massimo di caratteri da leggere, evitando così buffer overflow.
    */
  f = fopen(s, "r");
  if ( f==NULL) // APERTO IN LETTURA E IL FILE NON ESISTE
  {
    printf("non si apre strunz");
    return 1;
    //blocchiamo il codice, non si chiude un file che ha ritornato NULL
  }
  while( fgets(buffer, 100, f)){
    //prendiamo il contenuto di f e lo mettiamo su buffer
    //una riga alla volta, il contenuto di buffer viene sovrascritto
    fputs(buffer, stdout);
    //la stringa di buffer viene sputata sul terminale
  }
  //fgets per leggere da un file e fputs per scrivere su stdout, il processo funziona riga per riga
  fclose(f);
  //mai chiamare la close in un file che ha ritornato NULL
  return 0;
}