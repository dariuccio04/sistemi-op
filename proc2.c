#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void Figlio(void);
void Padre(void);

int main()
{
    pid_t pid; //pid del processo
    pid = fork(); //fork richiamata
    if (pid == 0) Figlio(); // la funzione viene eseguita dal figlio
    else Padre(); // la funzione viene eseguita dal padre
    
}

void Figlio(void){
    int i = 0;
    for(i = 0; i<10; i++) {
        usleep(200); // sospende il programma
        printf("\t sono il figlio i = %d\n", i);
    }
}

void Padre(void){
    int i = 1;
    for(i=0; i<10; i++){
        usleep(250);
        printf("sono il padre, i= %d\n", i);
    }
}

//non sappiamo chi viene eseguito prima
// l'output parla chiaro