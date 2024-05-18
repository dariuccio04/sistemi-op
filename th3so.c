//MUTEX
/*
Realizzazione del programma incremento di una variabile da parte di due
thread in parallelo usando in mutex

*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int glob = 0; 
//variabile globale su cui iteriamo
static pthread_mutex_t mtx;
//creazione del mutex


//funzione che eseguiranno insieme i due thread
static void * threadFunc(void *arg){
   int loops = *((int *)arg);
   int loc, j;
   for(j = 0; j<loops; j++){
     pthread_mutex_lock(&mtx);
     /*
Acquisisce il lock
Se il lock è già preso da qualcun'altro fallisce con errore
(valore di ritorno) EBUSY
     

     */

     //il primo che arriva blocca la prenotazione
     loc = glob;
     loc++;
     glob = loc;
     pthread_mutex_unlock(&mtx);
     //sblocca la prenotazioe
   }
  return NULL;
  
}


int main(void) {
  pthread_t t1, t2;
  //creazione di due thread
  int loops = 10000000;
  //iterazione
  pthread_mutex_init(&mtx, NULL);
  //inizializzazione mutex come thread
  //si passa il val di mutex, il NULL è per gli attributi
  pthread_create(&t1, NULL, threadFunc, &loops);
  //fun per creare un thread
  //1: val del thread che abbiamo definito prima
  //2: attributi in NULL
  //3: funzione che eseguirà
  //4: argomento passato alla funzione che deve eseguire

  pthread_create(&t2, NULL, threadFunc, &loops);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  //dobbiamo distruggere pthread sennò diventa uno zoombie

  pthread_mutex_destroy(&mtx);
  /*
   Rilascia la memoria occupata dal lock mutex
   Tale lock non sarà più utilizzabile

    */

  //print del risultato finale
  printf("glob = %d\n", glob);
  return 0;
}