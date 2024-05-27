#include <stdio.h>
//Esercizio: si un numero da tastiera. Si leggano poi interi e si stampi se essi includono duplicati
#define MAXN 50
//vogliamo dare un limite al nostro vettore -> prima o poi utilizzeremo le malloc

int main(void) {
  int v[MAXN];
  //definiamo il vettore
  int N;
  //con N andiamo a definire quanti numeri vogliamo mettere
  int i;
  //definire i prima del ciclo mi fa cagare :/
  int j;
  //non inizializzo tutto su una riga sennò mi confondo strunz
  printf("quanti numeri vuoi inserire?");
  scanf("%d", &N);
  //verifichiamo di non superare MAXN 50 (se lo superi sei strunz)
  if(N> MAXN) printf("sei strunz"); return 1;
  for(i=0; i<N; i++) {
    printf("inserisci l'elemento i: %d\n", i);
    scanf("%d", &v[i]);
  }

   for (i=0; i<N; i++){
   for (j=0; j<i; j++){
   if (v[i]==v[j]){
   printf("L'elemento %d è duplicato dell'elemento %d\n", i,j);
   }}};
  /*
  ci sta perchè siamo al num 10 e verifichiamo se prima di lui c'è qualcuno

    */
  return 0;
}