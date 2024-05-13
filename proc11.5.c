#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cartella passata come argomento -> listing cartella con ls -lh
int main(int argc, char * argv[1]) {
  char command[50] = "ls -lh";
  if(argc == 2)
  //controllo che non ci siano errori
  {
    strcat(command, argv[1]);
      // utilizzata per concatenare (aggiungere) una stringa alla fine di un'altra stringa.
  }
  system(command);
  return 0;
}