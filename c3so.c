#include <stdio.h>


typedef struct {
   float x;
   float y;
} punto;

//stiamo assegnando più caratteristiche a punto
//grazie Caravagna
int main(void) {
  punto p1,p2,p3;
  //stiamo definendo una struct punto quindi punto è come se fosse una variabile che comprende float x e y
   printf ("P1 -> x: ");
   scanf("%f", &p1.x);
   printf ("P1 -> y: ");
   scanf("%f", &p1.y);
   printf ("P2 -> x: ");
   scanf("%f", &p2.x);
   printf ("P2 -> y: ");
   scanf("%f", &p2.y);

   // Somma
   p3.x = p1.x + p2.x;
   p3.y = p1.y + p2.y;

   printf("La somma vettoriale è il punto: (%f, %f)\n", p3.x, p3.y);

  return 0;
}

/*

possiamo creare oggetti fighi


*/