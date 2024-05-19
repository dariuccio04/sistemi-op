//Write a C implements the Producer Consumer architecture with limited buffer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define N 10

int contatore = 0;
char * buffer [N];
//creazione del mutex
pthread_mutex_t mutex;
sem_t empty, full;
// creazione del semaforo vuoto-pieno




void * producer(void *arg){
  int in = 0;
  while(1){
    //con wait sto togliendo un punto a empty
    sem_wait(&empty);
    //blocco 
    pthread_mutex_lock(&mutex);


    //alloco memoria per il buffer
    buffer[in] = malloc(50*sizeof(char));
    //metto dentro il messaggio
    sprintf(buffer[in], "posizione del messaggio: %d", in);
    //con sprintf, aggiungo la posizione in buffer[in]
    contatore++;
    //conto quanti ne sono aggiunti

    //libero il mutex
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
  }
}


void * consumer(void *arg){
  int out = 0;
  while(1){
    //aspetto che ci siano dati e ne tolgo uno
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    char * next_consumed = buffer[out];
    printf("ricevuto %s \n", next_consumed);
    //la memoria che ho allocato prima non serve piu
    free(next_consumed);
    //CONVENZIONE BUFFER CICLICO
    out = (out +1) %N;
    contatore--;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
  }
}


int main(int argc, char *argv[]) {
 //creazione del thread
  pthread_t t;
  //inizializzazione del mutex
  //passiamo mutex con & perchè pthread_mutex_init accetta un puntatore
  //def di prima sbagliata ma va be io ho capito
  pthread_mutex_init(&mutex, NULL);

  //inizializzazione semafori
  sem_init(&empty, 0, N);
  sem_init(&full, 0, 0);

  //creazione del thread con lancio della fun
  pthread_create(&t, NULL, producer, NULL);
  consumer(NULL);

  return 0;
}

/*
il codice già implementa un comportamento in cui il produttore produce un dato alla volta e il consumatore consuma un dato alla volta. Ogni ciclo del produttore inserisce un singolo messaggio nel buffer, mentre ogni ciclo del consumatore rimuove un singolo messaggio dal buffer.
*/