#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <dest_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Aprire il file sorgente in modalità lettura
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        error_exit("Error opening source file");
    }

    // Aprire o creare il file di destinazione in modalità scrittura
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (dest_fd == -1) {
        close(src_fd);
        error_exit("Error opening/creating destination file");
    }

    // Ottenere la dimensione del file sorgente
    off_t file_size = lseek(src_fd, 0, SEEK_END);
    if (file_size == -1) {
        close(src_fd);
        close(dest_fd);
        error_exit("Error seeking in source file");
    }

    // Lettura e scrittura dei byte in ordine inverso
    char byte;
    for (off_t i = 1; i <= file_size; i++) {
        if (lseek(src_fd, -i, SEEK_END) == -1) {
            close(src_fd);
            close(dest_fd);
            error_exit("Error seeking in source file");
        }
        if (read(src_fd, &byte, 1) != 1) {
            close(src_fd);
            close(dest_fd);
            error_exit("Error reading from source file");
        }
        if (write(dest_fd, &byte, 1) != 1) {
            close(src_fd);
            close(dest_fd);
            error_exit("Error writing to destination file");
        }
    }

    // Chiudere i file
    close(src_fd);
    close(dest_fd);

    return 0;
}
