#include <stdio.h>
#include <string.h>




int main(void) {
  /*char c;
  printf("aggiungi carattere:");
  c = getchar();
  printf("carattere inserito: %c\n", c);
  putchar(c);*/
  /*char s;
  for( s = 'A'; s <= 'Z'; s++){
    putchar(s);
    
  }
  for( s = 'a'; s <= 'z'; s++){
    putchar(s);
  }*/
  char s[70];
  printf("inserisci il tuo nome: ");
  fgets(s,20, stdin);
  printf("il tuo nome: %s", s);
  int l = strlen(s);
  printf("la stringa è lunga: %d\n", l);
  char s2[70];
  strcpy (s2,s);
  printf("s2: %s ", s2);
  char c[50];
  printf("inserisci il tuo cognome: ");
  fgets(c,50, stdin);
  strcat(s,c);
  printf("s1: %s", s);
  return 0;
}