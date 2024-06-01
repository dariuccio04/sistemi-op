/*#include <stdio.h>

int main(void) {
  int dim = 10;
  float v[] = {5,5,5,5,5,5,5,5,5,5};
  float media;
  int n = 0;
  for(int i = 0; i<dim ; i++){
    media += v[i];
    n++;
  }
  printf("media: %f", media/n);
  return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int dim;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &dim);

    // Allocazione dinamica dell'array
    float *v = (float *)malloc(dim * sizeof(float));
    if (v == NULL) {
        printf("Errore di allocazione della memoria.\n");
        return 1;
    }

    // Popolamento dell'array con valori inseriti dall'utente
    for (int i = 0; i < dim; i++) {
        printf("Inserisci il valore per v[%d]: ", i);
        scanf("%f", &v[i]);
    }

    float media = 0.0;
    for (int i = 0; i < dim; i++) {
        media += v[i];
    }

    printf("media: %f\n", media / dim);

    // Deallocazione della memoria
    free(v);

    return 0;
}
