#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h> 
#define MAXLINE 128

int main() {
  char buf[MAXLINE];
  pid_t pid;
  int status;
  printf("%% ");
  while(fgets(buf, MAXLINE, stdin)!= NULL)
  /* 
  La funzione fgets() in C viene utilizzata per leggere una riga di testo da un file o da un'origine di input standard (come la tastiera) e memorizzarla in una stringa.

  All'interno del ciclo, la funzione fgets() viene chiamata per leggere una riga da stdin e memorizzarla nel buffer buf

  L'uso del valore MAXLINE come dimensione del buffer buf assicura che non vengano letti più di 128 caratteri in una singola riga da stdin, prevenendo potenziali problemi di overflow del buffer.
  */
  {
   if(buf[strlen(buf) -1] == '\n')
      buf[strlen(buf) -1] = 0;
    /*
     Questa operazione è comunemente utilizzata quando si leggono righe di testo tramite fgets(). Il carattere di nuova riga ('\n') viene solitamente incluso nella stringa letta da fgets(), ma può essere indesiderato, specialmente quando si manipolano stringhe. 
     */
    if((pid = fork()) <0){ printf("errore di fork"); exit(1);}
    else if (pid == 0)
      // se siamo il figlio
    {
      execlp(buf,buf,NULL);
      /*
       I primi due argomenti di execlp() specificano il nome del programma da eseguire. Poiché buf è utilizzato sia come nome del programma che come primo argomento da passare al programma stesso, questo significa che il programma esterno verrà eseguito con il suo stesso nome e con gli eventuali argomenti aggiuntivi specificati in buf. Il terzo argomento NULL indica la fine della lista di argomenti.

      Ad esempio, se buf contiene "ls -l", allora execlp("ls -l", "ls -l", NULL); verrà eseguito, il che equivale a eseguire il comando "ls -l" da shell Unix.

      È importante notare che dopo che execlp() viene eseguito con successo, il programma in esecuzione verrà sovrascritto dal programma specificato.
      */
      printf("non posso eseguire: %s\n", buf);
      //se non viene eseguita la execlp allora non si può eseguire il programma
      exit(127);
    } else
    if ((pid = waitpid(pid, &status, 0))<0)
     /* waitpid(pid, &status, 0): Questa chiamata blocca il processo padre fino a quando il processo figlio specificato da pid non termina. L'argomento &status indica dove memorizzare lo stato di uscita del processo figlio. L'argomento 0 specifica che la funzione deve essere bloccata finché uno dei processi figli non termina.
      */
    {printf("errore di waitpid"); exit(1);};
    printf("%% ");
  }
  exit(0);
}