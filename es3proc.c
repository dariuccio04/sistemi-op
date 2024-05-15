/*
Write a C program that has two processes and shared memory containing
N
floating point numbers. The child process fills the shared memory
float
vector,
where each element
v[i]=10 * i
, then it terminates. The father process waits
for the child to terminate, then it prints the vector.
    */


#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#define N 10


int main(void) {
  int i ;
  float* shared_memory;
  shared_memory=mmap(0, N*sizeof(float), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
  /*
  1: nullo
  2: dimensione
  3: PROT_READ | PROT_WRITE -> la pagina può essere scritta e letta
  4: cambiamenti visibili o meno -> convenzione di MAP-ANONYMOUS | MAP_SHAREF
  5/6: -1 e 0 per mappare la memoria

    */
  if (fork()){
    //padre
    wait(NULL);
    //vogliamo che il padre sospenda la propria esecuzione fino a quando uno qualsiasi dei suoi processi figli non termina l'esecuzione
    for(i=0; i<N; i++)
      printf("shared_memory[%d]==%f\n", i, shared_memory[i]);
  
  }
  else
    //figlio
  {
    for(i=0;i<N; i++){
      shared_memory[i] = i*10;
    }
  }
  return 0;
}

/*
Senza l'uso di memoria condivisa tramite mmap(), il processo padre e il processo figlio non condividerebbero la stessa area di memoria e quindi non sarebbero in grado di comunicare direttamente tramite una variabile condivisa come nel codice fornito.


La funzione mmap() restituisce un puntatore alla memoria condivisa

*/