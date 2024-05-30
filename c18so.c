#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define MAXN 100

int main(void) {
  FILE *f;
  f = fopen("media.txt", "r");
  if (f==NULL){
    printf("file non possibile da aprire");
    return 1;
  }
  float media = 0.0;
  int num;
  int trova = 0;
  char s[MAXN];
  char nome[MAXN];
  while( fgets(s, sizeof(s), f) != NULL ){
    if (sscanf(s, "%s %d", nome, &num)==2){
      printf("numeri: %d\n", num);
      media += num;
      trova++;
      printf("%d\n" ,trova);
    }
  }
  //il prof ha usato: while (fscanf(f, "%s %d\n", nome, &e) != EOF){
   //n++; s+=e; /* Accumula i contatori */
 //  }
  printf("la media è : %f ", media/trova);
  fclose(f);
  return 0;
}
/*
io sono un coglione perchè prima ho memorizzato la singola stringa e poi ho fatto sscanf ma fscanf è la stessa cosa ma per i file

*/