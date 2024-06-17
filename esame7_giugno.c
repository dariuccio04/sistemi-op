/*#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXN 1024

int main(int argc, char * argv[]) {
  char *buf[MAXN];
  int f1 = open(argv[1], O_RDONLY,0);
  int f2 = open(argv[2], O_WRONLY | O_CREAT | O_APPEND,0);

  while(read(f1, buf, 1) > 0){
    write(f2, buf, 1);
    lseek(f2, 0, SEEK_END);
  }

  close(f1);
  close(f2);
  
  return 0;
}*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXN 1024

int main(int argc, char * argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char buf[MAXN];
  int f1 = open(argv[1], O_RDONLY);
  if (f1 == -1) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }

  // Ottieni la lunghezza del file f1
  off_t file_length = lseek(f1, 0, SEEK_END);
  if (file_length == -1) {
    perror("Error seeking input file");
    close(f1);
    exit(EXIT_FAILURE);
  }

  // Scrivi dal fondo del file originale al file di output
  int f2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  if (f2 == -1) {
    perror("Error opening output file");
    close(f1);
    exit(EXIT_FAILURE);
  }

  // Leggi il file originale dall'ultimo carattere al primo
  for (off_t i = file_length - 1; i >= 0; i--) {
    if (lseek(f1, i, SEEK_SET) == -1) {
      perror("Error seeking input file");
      close(f1);
      close(f2);
      exit(EXIT_FAILURE);
    }

    ssize_t bytes_read = read(f1, buf, 1);
    if (bytes_read == -1) {
      perror("Error reading input file");
      close(f1);
      close(f2);
      exit(EXIT_FAILURE);
    }

    bytes_read = write(f2, buf, 1);
    if (bytes_read == -1) {
      perror("Error writing to output file");
      close(f1);
      close(f2);
      exit(EXIT_FAILURE);
    }
  }

  close(f1);
  close(f2);

  return 0;
}
