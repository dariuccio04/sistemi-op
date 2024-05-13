#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  pid_t pid;
 
  printf("T1 - start\n");
  pid = fork();
  // viene creato un padre1 e figlio1
  if(pid ==0)
  //in questo if entrerà figlio1
  {
    
    printf("T3 - DNS b.com\n");
    pid_t pid2;
    pid2 = fork();
    //figlio1 crea padre2 e figlio2
    if(pid2==0)
    //in questo if ci entrerà figlio2
    {
      printf("T6 - HTTP http://b.com/1\n");
      return 0;
      //il figlio due muore 
    }
    else 
    //in questo else ci entrerà padre2 
    {
      printf("T5 - HTTP http://b.com/2\n");
      wait((int *)0);
      //padre2 aspetta che figlio2 muoia
    }
  } else
  //in questo else ci entra padre1
  {
    printf("T2 - DNS a.com\n");
    printf("T4 - HTTP http://a.com/\n");
    wait((int *)0);
    //aspetta che muoia figlio1
  }
  printf("T7 - utilizzo i risultati\n");
  return 0;
}

/*
1 : T1
2-3 : T2 E T4, perchè viene invocata una fork, padre1 non entra dentro l'if e printa T2-T4 e aspetta figlio1
4: T3, figlio1 entra dentro l'if
5: T5 perchè viene invocata un altra fork con lo stesso meccanismo e quindi padre2 printa T5 e aspetta figlio2
6: T6, figlio2 printa T6 e muore
7: T7, figlio1 muore e padre1 va avanti


*/