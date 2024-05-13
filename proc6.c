#include <stdio.h>
#include <unistd.h>


int main(void) {
  printf("A ");
  fork();
  printf("B ");
  fork();
  printf("C ");
  return 0;
}

// A B C A B C A B C A B C


/*
  la libreria standard gestisce l'output in maniera bufferizzata:
  il printf viene salvato sul buffer di una libreria standard e non viene subito stampato, andrà a stampare tutto quello che ha in coda nel momento che noi stampiamo un ritorno a capo e quando il programma termina, quindi la printf per ora rimane ferma e vomita tutto dopo


*/