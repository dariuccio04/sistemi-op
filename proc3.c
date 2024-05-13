#include <stdio.h>
#include <unistd.h>

/*Per i figli, la condizione if(!fork()) diventa vera, non falsa. Cerchiamo di chiarire questo:

Quando il processo padre esegue fork(), crea un nuovo processo figlio e riceve il PID di quel figlio.

Ora, nel processo figlio appena creato, la chiamata a fork() restituirà 0, poiché è il figlio che esegue la chiamata.

Quindi, nel processo figlio, la condizione if(!fork()) diventa vera perché fork() restituisce 0, e il processo figlio entra nel blocco if e crea un altro processo figlio.

Nel processo padre, la condizione if(!fork()) diventa falsa perché fork() restituisce il PID del processo figlio, che è diverso da zero. Quindi il processo padre entra nel blocco else.

2: padre entra nel primo if fork, negativo il secondo if(!fork()) quindi va nell'else e printa 2

4: il padre va piu sotto e printa 4

3: il figlio non entra nel primo if e quindi printa 3

4: il figlio scende giu e printa 4

1: siamo nel figlio che crea un altra fork, printa 1

4: il figlio va piu sotto e printa 4

si ripete con l'altro figlio
*/

int main() {
    if (fork()) {
        if (!fork()) {
            fork();
            printf("1 "); 
        } else {
            printf("2 ");
        }
    } else {
        printf("3 ");
    }
    printf("4 ");
    return 0;
}