#include <stdio.h>

// Esempio: si legga un numero N da tastiera e si stampi sul file numeri.txt i numeri da 1 a n

int main(void) {
  int n;
  //numero da iterare
  FILE *f;
  printf("inserisci un numero: ");
  scanf("%d", &n);

  f = fopen("numeri.txt", "w");
  //apriamo il file in modalità scrittura
  if (f==NULL){
    printf("file non si apre strunz");
    return 1;
    //abbiamo bisogno di terminare prima, non si chiude il file se ritorna NULL
  }
  for(int i = 0; i<=n;i++){
    fprintf(f, "%d\n", i);
  }
  fclose(f);
  return 0;
}