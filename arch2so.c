#include <stdio.h>


int calcolo_potenza(int i){
  int calcolo =2;
  for(int j = 0; j<i; j++){
    calcolo *= 2;
  }
  return calcolo;
}


int main(void) {
  int a[] = {1,1,1,1,0,0,0,1};
  int dim = 8;
  int sommatoria = 0;
  int ultimo = dim-1;
  int potenza;
  for(int i = 0; i<dim; i++){
    if ( i == dim-1) {
        if (a[ultimo - i] == 1){
            potenza = calcolo_potenza(i-1);
            potenza = potenza *-1;
            printf("%d pot\n", potenza);
            sommatoria += potenza;
        }
    }
    if (a[ultimo - i] == 0) sommatoria += 0;
    if (a[ultimo - i] == 1 && i == 0) {
        potenza = 1;
        sommatoria += potenza;

      }
    if (a[ultimo - i] == 1 && i != dim-1 && i != 0) {
      potenza = calcolo_potenza(i-1);
      sommatoria += potenza;
        
    }
    printf("%d \n", sommatoria);
  }
  printf("%d", sommatoria);
  return 0;
}