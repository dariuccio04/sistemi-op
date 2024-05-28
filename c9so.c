#include <stdio.h>
#include <string.h>
/*
dobbiamo verificare che una stringa sia effettivamente palindroma
come: madam, level ecc
queste stringhe hanno la caratteristiche di essere dispari e gli elementi estremi (che sempre di piu si restringono) sono uguali
allora è più facile dimostrare che una stinga non sia palindroma

*/
int main(void) {
  char str[30];
  printf("inserisci la stringa da verificare: \n");
  fgets(str, 30, stdin);
  //scanf("%s",str);
  int n = strlen(str);
  printf("n = %d e n/2: %d\n", n, n/2);
  for(int i = 0; i<n/2; i++){
    if(str[i] != str[n-1-i]){
      printf("non palindroma");
      return 0;
    }
  }
 
  return 0;
}

/*

ho notato che quando si richiede una stringa, se utilizzo fgets allora strlen mi da un valore in piu, ma con scanf invece no


*/