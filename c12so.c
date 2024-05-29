#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 200

/*
Esercizio: si acquisisca una riga da tastiera e si trasformi in title case.
Una stringa in title case ha le iniziali (e solo le iniziali) di ogni parola maiuscole.
Esempio: Nel Mezzo Del Cammin Di Nostra Vita
  */



int main(void) {
  int len;
  char fr[MAXN];
  printf("inserisci la frase: \n");
  fgets(fr, MAXN, stdin);
  len = strlen(fr) -1;
  for(int i = 0; i<len; i++){
    if(i == 0 || !isalpha(fr[i-1])){
      fr[i]= toupper(fr[i]);
    }
  }
  printf("%s",fr);
  return 0;
}


/*
molto semplicemente noto che devo utilizzare toppuer (da minuscolo a maiuscolo, peccato che non funziona con il membro maschile) solo alla prima lettera in assoluto, e a quelle lettere che iniziano la parola dopo, quindi prima di esse ci sono spazi bianchi


*/