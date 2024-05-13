#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("Sono il figlio!\n");
    }
    else
    {
        printf("Sono il Padre!\n");
    }
    return 0;
}
