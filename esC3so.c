#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]) {
  FILE * f1;
  FILE *f2;
  int n;
  //valore su cui iteriamo
  int min;
  if (argc < 3){
    exit(1);
  }
  f1 = fopen(argv[1], "r");
  //da questo file voglio solo leggere
  if (f1 == NULL){
    exit(1);
  }
  f2 = fopen(argv[2], "w");
  //su questo file devo scriverci
  if (f2 == NULL){
    exit(1);
  }


  /*
  nei classici esercizi di iterazione e confronto, si utilizza inizializzare l'iteratore come primo elemento della lista da iterare
    */
  fscanf(f1, "%d\n", &min);
  //con fscanf sto prendendo dal file f1, la riga?
  // devo indicare come trattarla "%d\n" e dove metterla -> min
  while(fscanf(f1, "%d\n", &n) != EOF ){
    //prendo dal file f1 la riga, devo trattarla come intero
    //la metto su n (iteratore)
    if (n<min){
      min = n;
    }
  }
  fprintf(f2, "%d\n", min);
  //con fprintf specifico il file f2, sarà il file dove scriverò 
  //come tratto la var che inserisco? -> %d
  fclose(f1);
  fclose(f2);
  return 0;
}


/*

per bash:

1 stampo il file
2 metto in ordine per numero -> ordine crescente
3 prendo l'ultimo valore -> tail -1

cat in.txt | sort | head -1 > out.txt

tutto giusto ma non ricordavo come passare un contenuto al file



*/