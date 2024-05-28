#include <stdio.h>
#include <string.h>
//esempi di funzioni: strchr, strstr, strspn e strcspn

int main(void) {
  // strchr cerca la prima occorenza di carattere in una stringa, come grep o find su bash
  char *str= "hello, world!";
  /*
  In questo caso, str è un puntatore a una stringa letterale che non dovrebbe essere modificata. Questo previene errori dove il programma potrebbe tentare di modificare la stringa letterale, causando comportamenti indefiniti o crash.

  Le stringhe letterali sono memorizzate in una sezione di memoria che è tipicamente read-only
    */
  char ch = 'o';
  char *result = strchr(str, ch);
  //str (stringa) chr (character) 
  if (result) {
    printf("Il carattere '%c' trovato in posizione: %ld\n", ch, result - str);
  } else {
    printf("Il carattere '%c' non è stato trovato.\n", ch);
  }
  //la strstr cerca una (sotto)stringa su una stringa
  const char *str2 = "Hello, World!";
  const char *substr = "World";
  char *result2 = strstr(str2, substr);

  if (result2) {
      printf("La sottostringa \"%s\" trovata in posizione: %ld\n", substr, result2 - str2);
  } else {
      printf("La sottostringa \"%s\" non è stata trovata.\n", substr);
  }
  // la strspn 
  int len = strspn("gee for gee","geek"); 
   printf("Length of initial segment matching : %d\n", len ); 
  /*
  la funzione strspn(s1,s2) da come ritorno il numero di caratteri presenti di s2 in s1
  geek che è s2, quanti caratteri sono presenti: gee e gee quindi 3
  ma non a caso ma in "fila"


    */
  //sincero strspn e strcspn mi fanno cagare quindi è già tanto se ho fatto strspn, fanculo strcspn
  return 0;
}