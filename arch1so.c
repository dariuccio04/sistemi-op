#include <stdio.h>


int calcolo_potenza(int i){
  int calcolo =2;
  for(int j = 0; j<i; j++){
    calcolo *= 2;
  }
  return calcolo;
}


int main(void) {
  int a[] = {1,0,1,0,0};
  int dim = 5;
  int sommatoria = 0;
  int ultimo = dim-1;
  int potenza;
  for(int i = 0; i<dim; i++){
    if (a[ultimo - i] == 0) sommatoria += 0;
    if (a[ultimo - i] == 1) {
      printf("%d - %d\n", potenza, i );
      sommatoria += potenza;
    }
  }
  printf("%d", sommatoria);
  return 0;
}