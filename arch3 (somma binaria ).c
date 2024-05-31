#include <stdio.h>
#include <stdlib.h>

// Algoritmo di somma binaria

int main(void) {
    int n = 7;
    int s_1[n + 1];
    int s_2[n + 1];
    int somma[n + 1];

    // Inizializziamo il vettore somma
    for (int i = 0; i <= n; i++) {
        somma[i] = 0;
    }

    printf("Inserisci numeri per s_1: \n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &s_1[i]);
    }

    printf("Inserisci numeri per s_2: \n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &s_2[i]);
    }

    int i = 0;

    while (i <= n) {
        int sum = s_1[i] + s_2[i];
        switch (sum) {
            case 0:
                somma[i] = 0;
                i++;
                break;
            case 1:
                somma[i] = 1;
                i++;
                break;
            case 2:
                if (i < n) {
                    s_1[i + 1]++;
                    somma[i] = 0;
                }
                i++;
                break;
            case 3:
                if (i < n) {
                    somma[i] = 1;
                    s_1[i + 1]++;
                }
                i++;
                break;
            default:
                break;
        }
    }

    printf("Somma: ");
    for (int i = n; i>=0 ; i--) {
        printf("%d ", somma[i]);
    }

    return 0;
}
