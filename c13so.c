#include <stdio.h>

/*
Esempio: si crei e si usi una funzione che applica a ogni elemento di un vettore di interi una
funzione fornita dal chiamante.
  */


void apply(int *v, int n, int (*f)(int)){
  //accettiamo un puntatore cioè l'array di 5 num
  //accettiamo la dim dell'array
  //accettiamo una funzione quindi la fun viene trattata come un punt
  for (int i=0; i<n; i++) // Dichiaro i nel loop
   v[i] = (*f)(v[i]);
  //con (*f) in effetti sto chiamando la funzione square e sto passando v[i]
  }


int square(int a) {return a*a;}


int main(void) {
  int vec [] = { 1,2,3,4,5};
  int n = 5;
  apply(vec, n,square);
  for (int j=0; j<5; j++)
   printf("vec[%d]=%d\n", j, vec[j]);
   return 0;
  }
