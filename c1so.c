#include <stdio.h>
// questa libreria gestisce I/O

int main (void) {
 int a;
 //sarà dove mettiamo i minuti di input
 int b,c;
 //sarà dove salviamo le ore e i minuti
 //in int perchè vogliamo un dato intero
 printf("calcolo ore\n\n");
 printf("immetti il numero di minuti: ");
 scanf("%d", &a);
 b = a/60;
 //vogliamo un numero intero e con a/60 noi stiamo togliendo il resto e prendendo solo la parte intera
 c = a%60
 //cosi stiamo salvando la parte mancante
 printf("una quantità di %d minuti equivale a $d ore e %d minuti\n",a,b,c);
 return 0;
}




 return 0;
}
