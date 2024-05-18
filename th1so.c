#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

/*
static, essa può essere chiamata solo all'interno dello stesso file sorgente in cui è definita, e non può essere accessibile da altri file sorgente che includono lo stesso header


*/
static void * threadFunc(void *arg){
  //ret alloca memoria per la lunghezza stringa dell'argomento e poi la ritorna
  printf("From Thread: %s", (char *)arg);
  int *ret = malloc(sizeof(int));
  *ret = strlen(arg);
  return ret;
}
/*
La funzione threadFunc restituisce ret perché l'obiettivo è comunicare un valore (in questo caso, la lunghezza della stringa passata come argomento) al thread principale che ha creato il thread.

Quando un thread restituisce un valore tramite pthread_exit o implicitamente, come in questo caso attraverso il return, il valore viene reso disponibile per essere recuperato dal thread principale attraverso la funzione pthread_join
  */




int main(int argc, char *argv[]) {
  pthread_t t1; // creazione thread -> numero intero cioè thread id
  void *res; //valore di ritorno non so di quale tipo
  int s; //qualche var di appoggio -> valore di ritorno di thread -> dalla creazione

  s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
    //primo argomento è un puntatore al thread_id
  //secondo argomento per gli attributi -> settato su null
  // threadFunc è la funzione che eseguirà il thread
  // hello world è l'argomento passato alla funzione
  //pthread create da un valore di ritorno

  //controllo di thread
  //se s = 0 allora il thread non è stato creato correttamente
  if(s !=0){
    printf("cannot create thread");
    exit(1);
  }
  printf("message from main()\n");
  s = pthread_join(t1, &res);
  //con la join aspettiamo che il pthread muori sennò diventa uno zombie tipo tu lunedi mattina a lezione
  //t1 l'id del thread e &res un void **
  //il valore di t1 viene memorizzato su res




  //controllo come sia andata la join
  if(s!=0){
    printf("Cannot join thread");
    exit(1);
    
  }
  
  printf("Thread returned %d\n", *((int *)res) ); // Utilizzo del valore di ritorno
   free (res); // Needed as that zone was allocated with malloc
   exit(0);
  }}