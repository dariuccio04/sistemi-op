/*
Si crei un programma che avvia thread che attendono un tempo casuale tra e secondo prima di terminare
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXSLEEP 5 
//max 5 secondi 
#define THREADNB 10
//10 thread

static void * sleepFunc(void *arg){
 char thread_number = *((char*)arg);
  /*
estrae il valore del carattere dal puntatore void arg e lo memorizza nella variabile thread_number. Poiché arg è di tipo void *, è necessario eseguire un cast a char * per poter accedere al valore del carattere.


  */
 int n=rand() % MAXSLEEP;
 sleep(n);
  /*
sleep() dalla libreria unistd.h viene utilizzata per far dormire il thread per n secondi. Questo significa che il thread sarà inattivo per un periodo di tempo casuale compreso tra 0 e MAXSLEEP - 1 secondi.
  */
 printf("Thread %c terminated after %d seconds\n", thread_number, n);
 return NULL;
}






int main(int argc, char * argv[]) {
  int i; //sicuro il valore di ritorno della thread create e thread join
  // e invece no, serviva solo per l'iterazione del for
  pthread_t t [THREADNB]; 
  //puntatore al valore, dobbiamo usare &t
  //vogliamo crearne 10
  char names [THREADNB];
  //array lungo quanto i thread??


  // 10 iterazioni
  for(i = 0; i<THREADNB; i++){
    names[i] =  'A' + i;
    /*
      'A' + i: In C, i caratteri sono rappresentati come valori ASCII. Il carattere 'A' ha un valore ASCII di 65. Quindi, quando aggiungi i a 'A', ottieni un nuovo carattere che corrisponde a 'A' più l'indice i.
      */

    //creazione pthread
    pthread_create(&t[i], NULL, sleepFunc, &names[i]);
    // primo valore è l'id thread
    //il secondo sono gli argomenti e sono NULL (utilizziamo quelli di default)
    // il terzo argomento riguarda la funzione che deve eseguire
    // il quarto l'argomento che deve passare alla funzione del secondo argomento
  }
   for (i=0;i<THREADNB;i++)
   pthread_join(t[i], NULL);
  //aspettiamo la morte del thread sennò diventa uno zoombie
  
  return 0;
}