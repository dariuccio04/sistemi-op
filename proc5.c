#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
  printf("A\n");
  fork();
  printf("B\n");
  fork();
  printf("C\n");
  return 0;
}

/* il primo print ha un processo
la fork crea padre1 e figlio1
padre1 e figlio1 printano b
la fork crea padre_padre1 e padre_figlio1 e figlio_padre1 e figlio_figlio1
tutti e 4 printano c


*/