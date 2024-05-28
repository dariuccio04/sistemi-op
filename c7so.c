#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
    uint32_t dword;
} cpu_register;

int main() {
    cpu_register reg;
  printf("prima della modifica di dword:\n");
   printf("byte1: %02X\n", reg.bytes.byte1);
   printf("byte2: %02X\n", reg.bytes.byte2);
   printf("byte3: %02X\n", reg.bytes.byte3);
   printf("byte4: %02X\n", reg.bytes.byte4);
   printf("dword: %02X\n", reg.dword);

    // Assegna un valore alla dword
    reg.dword = 0x12345678;
    printf("Dopo modifica di dword:\n");
    // Stampa i singoli byte
    printf("byte1: %02X\n", reg.bytes.byte1);
    printf("byte2: %02X\n", reg.bytes.byte2);
    printf("byte3: %02X\n", reg.bytes.byte3);
    printf("byte4: %02X\n", reg.bytes.byte4);
    printf("dword: %02X\n", reg.dword);
    // Modifica byte3 e stampa di nuovo i singoli byte
    reg.bytes.byte3 = 4;
    printf("Dopo modifica di byte3:\n");
    printf("byte1: %02X\n", reg.bytes.byte1);
    printf("byte2: %02X\n", reg.bytes.byte2);
    printf("byte3: %02X\n", reg.bytes.byte3);
    printf("byte4: %02X\n", reg.bytes.byte4);
    printf("dword: %02X\n", reg.dword);
    return 0;
}
/*
cosa ho notato:
prima di assegnare le variabili ovviamente la memoria è su 0, grazie al cazz strunz

alla prima assegnazione, stiamo assegnando il valore 12345678,
questo valore verrà inserito su dword e la memoria verrà stampata sui byte

quindi ogni byte contiene uno spazio di memoria
è come se dico che voglio rappresentare il numero 15 allora posso fare
8
2
3
1
1
8+2+3+1+1= 15

ma se ora voglio rappresentare il numero 12
6
2
3
1

da 8 a 6 e abbiamo tolto 1 alla fine


stessa cosa succede nei byte spalmati



*/
