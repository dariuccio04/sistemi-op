/*
Write a C program that has two processes. The first process sends to the second
the name of a file. The second process reads the name of the file and sends back
to the first process its content



    */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void client(int readfd, int writefd){
  char buffer[1000];
  printf("Pathname: ");
  scanf("%s", buffer);
  write(writefd, buffer, strlen(buffer));
  //buffer viene scritto su writefd
  //viene specificata inoltre la lunghezza da scrivere con strlen
  while(read(readfd, buffer, sizeof(buffer)) > 0) printf("%s", buffer);
    //vogliamo leggere dati dal file readfd, e memorizzarli su buffer, legge fino a sizeof bytes, quindi fin quando è maggiore di 0 allora legge
    
};




void server(int readfd, int writefd){
  FILE *fp;
  char buffer[1000];
  int n;
  n = read(readfd, buffer, sizeof(buffer));  
  buffer[n] = 0;
  /*
  terminatore null. Questo assicura che il buffer sia utilizzabile come una stringa C valida, poiché le stringhe C devono essere terminate da un carattere null.
  */
  fp = fopen(buffer, "r");
  while(fgets(buffer, sizeof(buffer),fp)!=NULL)
    //legge una riga dal file fp e la memorizza sul buffer, legge fino al raggiungimento di -1 caratteri, restituisce NULL quando si verifica un errore o quando si raggiunge la fine
    write(writefd,buffer,sizeof(buffer));
  //scrivo il buffer sul file writefd
};


int main() {
  int pfd1[2], pfd2[2], pid, status;
  pipe(pfd1); 
  /*
   pfd1[0] è aperto in lettura
   pfd1[1] è aperto in scrittura
    */
  pipe(pfd2); 
  /*
   pfd2[0] è aperto in lettura
   pfd2[1] è aperto in scrittura
    */
  pid = fork();
  
  if (pid>0)
    //al padre
  {
    close(pfd1[0]);
    close(pfd2[1]);
    client(pfd2[0], pfd1[1]);
    //pfd2[0] serve in lettura
    //pfd1[1] serve in scrittura
    wait(&status);
    exit(0);
  }
  else
    //figlio
  {
  close(pfd1[1]);
  close(pfd2[0]);
  server(pfd1[0], pfd2[1]);
  exit(0);
    
  }
  return 0;
}