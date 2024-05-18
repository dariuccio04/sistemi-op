#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>




int main(int argc, char *argv[]) {
  sem_t *s; //puntatore a semaforo

  s = sem_open("/semaforo", O_CREAT , S_IRUSR | S_IWUSR, 0);
  // apertura semaforo
  // O_CREAT  crea e apre se non esiste, apre se esiste
  /*
   S_IRUSR | S_IWUSR:

   Questi sono i permessi del semaforo.
   S_IRUSR (0400) permette al proprietario di leggere il semaforo.
   S_IWUSR (0200) permette al proprietario di scrivere sul semaforo.
   Combinandoli con |, i permessi risultanti sono 0600, che permette al proprietario di leggere e scrivere sul semaforo.

 0:  Questo è il valore iniziale del semaforo se viene creato. In questo caso, il semaforo sarà inizialmente zero.

    */


  //controllo sul semaforo
  if(s == SEM_FAILED){
    printf("error creating/opening");
    exit(1);
  }
  while(1){
    printf("premi enter per una post: ");
    getchar();
    //prende un carattere da tastiera
    sem_post(s);
    //incrementa il semaforo
  }

  sem_close(s);
  //chiudi il semaforo o sei un pollo
  return 0;
}