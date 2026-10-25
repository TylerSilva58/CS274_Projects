/* Challenge 5.6 Basic File I/O */

#include <stdio.h>
#include <stdlib.h>

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void write_file(char *filename, char *data) {
    FILE *file = fopen(filename, "w"); 
    if (file == NULL) { 
        perror("Failed to open file");
        exit(1);
    }
    fprintf(file, "------ BEGIN ------\n");
    fprintf(file, "Data: \"This is some data\" %s\n", data);
    fprintf(file, "------ END ------\n");
    fclose(file);

}

void usage(char *cmd) {
    fprintf(stderr, "usage: %s r filename | w filename \"data\"\n", cmd);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc == 1) usage(argv[0]);

    switch (argv[1][0]) {
    case 'r':
        if (argc != 3) usage(argv[0]);
        read_file(argv[2]);
        break;

    case 'w':
        if (argc != 4) usage(argv[0]);
        write_file(argv[2], argv[3]);
        break;

    default: usage(argv[0]);
    }
}

