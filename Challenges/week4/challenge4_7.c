/* Challenge 4.7 Seeking in a file */

#include <stdio.h>

/**
 * Display a file on stdout.
 */
void cat(char *filename)
{
    char buf[4096];
    int count;

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("cat");
        return;
    }

    do {
        count = fread(buf, 1, sizeof buf, fp);
        fwrite(buf, 1, count, stdout);
    } while (count > 0);

    putchar('\n');

    fclose(fp);
}

/**
 * Main.
 */
int main(void)
{
    // TODO: Open the file `seeker.txt` for writing
    FILE *file = fopen("seeker.txt", "w");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    // Turn off buffering for this demo
    // (Replace `fp` with whatever your `FILE*` variable is)
    setbuf(file, NULL);

    // TODO: Write 60 `-` characters to the file
    for (int i = 0; i < 60; i++){ 
        fputc('-', file); 
    }

    // TODO: Seek to position 0
    fseek(file, 0, SEEK_SET); 
    
    // TODO: Write "interrupting"
    fputs("interrupting", file); 

    // TODO: cat("seeker.txt");
    cat("seeker.txt");

    // TODO: Seek to position 40
    fseek(file, 40, SEEK_SET);
    // TODO: Write "cow"
    fputs("cow", file);

    // TODO: cat("seeker.txt");
    cat("seeker.txt");

    // TODO: Seek to position 20
    fseek(file, 20, SEEK_SET);

    // TODO: Write "MOOOOOOO!"
    fputs("MOOOOOOO!", file); 

    // TODO: cat("seeker.txt");
    cat("seeker.txt");

    // TODO: Close the file
    fclose(file);
}