#include <stdio.h>

/*

Esempio: si crei e si usi una funzione che combini due interi usando una funzione fornita dal
chiamante e stampi il risultato.


*/

void combineAndPrint(int a, int b, int (*comb)(int, int)){
  //accettiamo due interi e la funzione
 int p = (*comb)(a, b); // Dereferenziazione di comb
 printf("Combinazione: %d\n", p);
}
int add(int a, int b) {return a+b;}
int mult(int a, int b){return a*b;}
int main(){
 combineAndPrint(3, 4, mult); // Stampa 12
 combineAndPrint(3, 4, add); // Stampa 7
 return 0; 
}
/*
mult: Il nome della funzione viene trattato come un puntatore alla funzione.
&mult: Il nome della funzione preceduto dal simbolo & è esplicitamente il puntatore alla funzione.
Entrambe le forme sono quindi equivalenti e possono essere usate intercambiabilmente. In altre parole, quando si passa una funzione come argomento, non è necessario utilizzare l'operatore & perché il nome della funzione è già un puntatore alla funzione.


*/
