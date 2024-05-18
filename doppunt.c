#include <stdio.h>

int main() {
  int x = 69;
  int *p1 = &x;
  int **p2 = &p1;
  int ***p3 = &p2;

  printf("valore di x: [%d], indirizzo di x: [%p]\n", x, &x);
  printf("valore di p1: [%p], indirizzo di p1: [%p]\n", p1, &p1);
  printf("valore di p2: [%p], indirizzo di p2: [%p]\n", p2, &p2);
  printf("valore di p3: [%p], indirizzo di p3: [%p]\n", p3, &p3);
  /*
  valore di x: [69], indirizzo di x: [0x7ffedaa0e8cc]
                                            -
  valore di p1: [0x7ffedaa0e8cc], indirizzo di p1: [0x7ffedaa0e8d0]
                      -                                   --
  valore di p2: [0x7ffedaa0e8d0], indirizzo di p2: [0x7ffedaa0e8d8]
                      --                                 ---
  valore di p3: [0x7ffedaa0e8d8], indirizzo di p3: [0x7ffedaa0e8e0]
                     ---

  */

  printf("valore di x da p1: %d\n", *p1); // dereferenziazione (non si scrive cosi) -> da p1 punt a *p1
  printf("valore di x da p2: %d\n", **p2);
  printf("valore di x da p3: %d\n", ***p3);
  /*
   valore di x da p1: 69
   valore di x da p2: 69
   valore di x da p3: 69

    */

  int z[3] = {69, 333, 420};
  //voglio puntare all'array ma l'array è un puntatore 
  int *z1 = z;
  int **z2 = &z1;
  int ***z3 = &z2;

  printf("indirizzo di z(69): [%p]", z);
  //il resto mi secca scriverlo
  return 0;
}

