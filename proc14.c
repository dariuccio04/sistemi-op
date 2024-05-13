#include <stdio.h>
#include <unistd.h>
#include <signal.h>



void handler(int signum);

int main(void) {
  pid_t pid;
  struct sigaction action;
  pid = fork();
  if (pid !=0)
  //nell'if entra il padre
  {
    while(1){
      sleep(1);
      kill(pid, SIGUSR1);
      //pid è a chi vogliamo inviare il processo, SIGUSR1 è il segnale che vogliamo inviare
      // SIGUSR1 è un segnale definito dall'utente, che può essere utilizzato per comunicazioni personalizzate tra i processi.

      /*

    pid > 0: Il segnale viene inviato al processo con il PID specificato.
    pid == 0: Il segnale viene inviato a tutti i processi nello stesso gruppo di processo del chiamante.
    pid < -1: Il segnale viene inviato a tutti i processi in un gruppo di processo specificato.
    pid == -1: Il segnale viene inviato a tutti i processi per i quali il chiamante ha il permesso di inviare segnali, eccetto il processo iniziale (PID 1).

      */
    }
  }
  else 
    //per il figlio
{
  action.sa_handler = handler;
  // Qui si assegna la funzione handler alla variabile sa_handler della struttura action.
  //bisogna collegare la funzione all'handler
  sigemptyset(&action.sa_mask);
  // inizializza il set dei segnali da bloccare durante l'esecuzione della funzione di gestione del segnale.
  //La funzione sigemptyset svuota il set dei segnali passato come argomento.&action.sa_mask è l'indirizzo del set dei segnali all'interno della struttura action
  action.sa_flags= 0;
  //Impostare action.sa_flags a 0 indica che nessun flag specifico è impostato
  sigaction(SIGUSR1, &action, NULL);
  while(1);
}
  return 0;
}