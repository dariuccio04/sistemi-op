/*
Exercise 1
Write a C program that forks a child, which forks a child. Every second, the
grand-child sends a SIGUSR1 to the the child (which is the father of the grandchild). When the child receives a SIGUSR1, it sends a SIGUSR2 to the father.


*/
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler_child(int signum){
  printf("ricevuto SIGUSR1 e manda SIGUSR2");
  kill(getppid(), SIGUSR2);
  //KILL MANDA PROCESSI, è UNA SYSTEM CALL
  //SIGUSR2 è il segnale da mandare
  /*
  se > 0 : spedito al processo identificato da pid
  se 0 : spedito a tutti i processi appartenenti allo stesso gruppo del processo che
  invoca kill()
  se <0 : spedito al gruppo di processi identificati da –pid
  se -1 : a tutti i processi (attenzione!)
  */
};



void handler_father(int signum){
  printf("RICEVUTO");
}




int main() {
  pid_t pid; //tracciare i processi
  struct sigaction action; // gestire i processi
  pid = fork(); //si andrà a creare un padre e un figlio
  if (pid!=0)
    //il padre
  {
    action.sa_handler = handler_father; 
    /*
    sa_handler specifica il comportamento
    Se funzione, specifica un handler
      */
    sigemptyset(&action.sa_mask);
    // Questa funzione inizializza il set di segnali impostato per escludere tutti i segnali definiti. Ritorna sempre 0.
    // sa_mask : segnali da bloccare mentre l'handler è in
   // esecuzione
    action.sa_flags = 0; //a 0 per convenzione
    sigaction(SIGUSR2, &action, NULL);
    /*
imposta la gestione del segnale SIGUSR2 utilizzando le configurazioni specificate nella struttura action
      */

    /*
 il processo padre rimarrà in attesa di ricevere il segnale SIGUSR2, ma non eseguirà alcuna altra azione oltre a questo.
      */
  } else
//qua per il figlio
  {
   pid = fork();
   if(pid!= 0){
     //padre-> figlio di prima
     action.sa_handler = handler_child;
     sigemptyset(&action.sa_mask);
     action.sa_flags = 0;
     sigaction(SIGUSR1, &action, NULL);
     while(1);}
   else
     //il nipote
   {
     while(1){
       sleep(1);
       kill(getppid(), SIGUSR1);
     }
   }

    
  }
  
  
}

/*

prima viene creata la gestione del segnale, tramite le varie convenzioni di handler, gestione segnali, sigaction, e poi si riceve il segnale tramite kill



*/