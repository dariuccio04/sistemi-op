#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

// Dichiarazione dei semafori globali
sem_t s_scrittura, s_lettura;
// Buffer condiviso tra i thread
char buffer[50];

// Funzione del thread sender
void *sender(void *arg) {
    while (1) {
        // Aspetta che il buffer sia libero per scrivere
        sem_wait(&s_lettura);

        // Scrive un messaggio nel buffer
        snprintf(buffer, sizeof(buffer), "Messaggio inviato");
        printf("Sender: %s\n", buffer);

        // Segnala che il buffer contiene dati
        sem_post(&s_scrittura);

        // Simula il tempo di elaborazione
        sleep(1);
    }
    return NULL; // Non verrà mai raggiunto
}

// Funzione del receiver
void receiver() {
    while (1) {
        // Aspetta che il buffer contenga dati
        sem_wait(&s_scrittura);

        // Legge il messaggio dal buffer e lo stampa
        printf("Receiver: %s\n", buffer);

        // Segnala che il buffer è libero
        sem_post(&s_lettura);

        // Simula il tempo di elaborazione
        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    pthread_t t;

    // Inizializza il semaforo di scrittura con valore 0 (buffer inizialmente vuoto)
    sem_init(&s_scrittura, 0, 0);

    // Inizializza il semaforo di lettura con valore 1 (buffer pronto per scrivere)
    sem_init(&s_lettura, 0, 1);

    // Crea il thread sender
    pthread_create(&t, NULL, sender, NULL);

    // Il thread principale esegue la funzione receiver
    receiver();

    // Codice irraggiungibile poiché receiver ha un ciclo infinito
    pthread_join(t, NULL);

    // Distrugge i semafori (non verrà mai raggiunto)
    sem_destroy(&s_scrittura);
    sem_destroy(&s_lettura);

    return 0;
}
