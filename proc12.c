#include <stdio.h>
#include <unistd.h>

int main(void) {
  if (fork())
  //se diverso da 0 viene considerata vera
  {
      printf("A\n");
  } else{
      fork();
      printf("B\n");
  }
  return 0;
}

/*

la prima fork invoca padre1 e figli


*/