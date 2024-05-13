#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
//cmd è il comando da terminale che riceve
int system(const char *cmd){
    int stat;
    pid_t pid;
    if ( cmd == NULL) return 1;
    if ((pid = fork()) == 0)
    //qua stiamo chiamando la fork, entra se è figlio
    {
      execl("/bin/sh", "sh", "-c", cmd, (char *)0);
      /*
 la riga di codice execl("/bin/sh", "sh", "-c", cmd, (char *)0); avvia un nuovo processo in cui viene eseguito il programma "sh" (la shell Unix). L'opzione -c indica alla shell di interpretare il comando successivo come un comando da eseguire. Il comando da eseguire è preso dalla variabile cmd. Infine, (char *)0 indica la fine della lista degli argomenti passati alla shell.
      */
      _exit(127);
    }
  if (pid == -1)
  //errore nella fork
  {
    //segnaliamo l'errore
    stat = -1;
  }
  else
  //if per il padre
  {
    while(waitpid(pid,&stat, 0)==-1)
    /*  waitpid(pid, &stat, 0) sta aspettando che il processo identificato da pid termini e memorizza il suo stato di uscita in stat*/
    {
      if(errno != EINTR){
        /* 
        l'istruzione if (errno != EINTR) controlla se errno non è uguale a EINTR, il che significa che l'errore non è stato causato da un segnale di interruzione. Se questo è vero, il codice all'interno del blocco if verrà eseguito per gestire l'errore in modo diverso da come si gestisce normalmente un errore.
        */
        stat = -1;
        break;
      }
    }
  }
  return (stat);
}


int main(int argv, char * argc[]) {
  //system(argc[1])
  return 0;
}