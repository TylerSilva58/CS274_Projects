#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>

/**
 * Frequencies of English letters.
 */
float freqs_english[26] = {
    0.08167f,  /* A */
    0.01492f,  /* B */
    0.02782f,  /* C */
    0.04253f,  /* D */
    0.12702f,  /* E */
    0.02228f,  /* F */
    0.02015f,  /* G */
    0.06094f,  /* H */
    0.06966f,  /* I */
    0.00153f,  /* J */
    0.00772f,  /* K */
    0.04025f,  /* L */
    0.02406f,  /* M */
    0.06749f,  /* N */
    0.07507f,  /* O */
    0.01929f,  /* P */
    0.00095f,  /* Q */
    0.05987f,  /* R */
    0.06327f,  /* S */
    0.09056f,  /* T */
    0.02758f,  /* U */
    0.00978f,  /* V */
    0.02360f,  /* W */
    0.00150f,  /* X */
    0.01974f,  /* Y */
    0.00074f,  /* Z */
};

/**
 * Read a file into memory.
 *
 * Returns a pointer to the file data. This data should be freed with
 * `free()`. `size` is an out parameter that will hold the file size.
 */
char *read_file(char *filename, int *size)
{
    struct stat sb;
    int total_size = 0;

    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("fopen");
        return NULL;
    }

    // Get the file size
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    // Allocate that many bytes of space
    char *data = malloc(sb.st_size);

    // Read the file into that
    int byte_count;

    while ((byte_count = read(fd, data + total_size, 4096)) > 0)
        total_size += byte_count;

    *size = total_size;

    close(fd);

    return data;
}

/**
 * Get the letter frequencies for file data.
 */
void get_freqs(char data[], int data_size, float freqs[]) {

    int letterCounter = 0; 

    for (int i = 0; i < 26; i++) { 
        freqs[i] = 0.0f;
    }

    for (int i = 0; i < data_size; i++ ) { 

        if (isalpha(data[i])) { 
            int character = toupper(data[i]); 
            int slot = character - 'A';
            freqs[slot] += 1; 
            letterCounter += 1;
        } 
    }
    if (letterCounter >=1) {

        for (int i = 0; i < 26; i++) {
            freqs[i] /= letterCounter;
        }
    }
}

/**
 * Compare freqs to English freqs and figure out which shift gives us
 * the least error.
 */
int find_rotation(float freqs[]) {

    float bestScore = 100;
    int bestChipher = 0;

    for (int rotfinder = 0; rotfinder < 26; rotfinder++) {
        float freqScore = 0.0;

        for (int i = 0; i < 26; i++) {

            int slotChipher = (i + rotfinder) % 26;
            float freqDifference = freqs_english[i] - freqs[slotChipher];
            freqDifference = freqDifference * freqDifference;
            freqScore += freqDifference; 
        }

        if (freqScore < bestScore) { 

                bestScore = freqScore;
                bestChipher = rotfinder;
            }
    }
    return bestChipher;
}

/**
 * Decrypt the ciphertext and print to the screen.
 */
void decrypt(char data[], int data_size, int rot) {

    for (int i = 0; i < data_size; i++) {
        
        if (isalpha(data[i])) {
            
            int character = toupper(data[i]);
            int charEval = character - 'A'; 
            charEval = (charEval - rot + 26) % 26;
            data[i] = charEval + 'A';
            putchar(data[i]);

        } else { putchar(data[i]); }
    }
}

/**
 * Main.
 */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: caesar filename\n");
        return 1;
    }

    char *filename = argv[1];

    int data_size, rot;
    char *data = read_file(filename, &data_size);

    if (data == NULL) {
        return 2;
    }

    float freqs[26];

    get_freqs(data, data_size, freqs);
    rot = find_rotation(freqs);
    decrypt(data, data_size, rot);

    free(data);
}
