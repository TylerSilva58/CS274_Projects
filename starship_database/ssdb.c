/* Fleet Command Starship Database */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Information about each Starship in the Fleet */
struct starship {
    char name[128];
    int passengers;
    float speed; // 1.0 is speed of Light
    char destination[128];
};

/**
 * Read a given record number into the struct.
 */
void record_read(FILE *fp, int record_num, struct starship *s) {
    fseek(fp, record_num * (sizeof(s -> name) + sizeof(s -> passengers) + sizeof(s -> speed) + sizeof(s -> destination)), SEEK_SET);
    fread(s -> name, sizeof(s -> name), 1, fp);
    fread(&s -> passengers, sizeof(s -> passengers), 1, fp);
    fread(&s -> speed, sizeof(s -> speed), 1, fp);
    fread(s -> destination, sizeof(s -> destination), 1, fp);
}

/**
 * Write a given struct to the record number.
 */
void record_write(FILE *fp, int record_num, struct starship *s) {
    fseek(fp, record_num * (sizeof(s -> name) + sizeof(s -> passengers) + sizeof(s -> speed) + sizeof(s -> destination)), SEEK_SET);
    fwrite(s -> name, sizeof(s -> name), 1, fp);
    fwrite(&s -> passengers, sizeof(s -> passengers), 1, fp);
    fwrite(&s -> speed, sizeof(s -> speed), 1, fp);
    fwrite(s -> destination, sizeof(s -> destination), 1, fp);
}

FILE *open_starship_file(void) { 
    FILE *starship_file = fopen("starship.txt", "r+b");
    if (!starship_file) {
        starship_file = fopen("starship.txt", "w+b");
        if (!starship_file) {
            perror("Failed to access Fleet Command Starship Database");
            exit(1);
        }
    }
    return starship_file;
}

int main(int argc, char *argv[]){ 
    if (argc < 2) { 
        printf("usage: ssdb r rec | w rec name passengers speed dest\n");
        return 1;   
    }
    if (strcmp(argv[1], "r") == 0) { 
        if (argc != 3) {
            printf("usage: ssdb r rec | w rec name passengers speed dest\n");
            return 1;
        }
        int record_num = atoi(argv[2]);

        struct starship s;
        FILE *starship_file = open_starship_file();
        record_read(starship_file, record_num, &s);
        printf("Record %d:\n", record_num);
        printf("\n");
        printf("    Name:        %s\n", s.name);
        printf("    Passengers:  %d\n", s.passengers);
        printf("    Speed:       %f\n", s.speed);
        printf("    Destination: %s\n", s.destination);
        printf("\n");

        fclose(starship_file); 
        return 0;

    } else if (strcmp(argv[1], "w") == 0) {
        if (argc != 7) {
            printf("usage: ssdb r rec | w rec name passengers speed dest\n");
            return 1;
        }
        int record_num = atoi(argv[2]);

        struct starship s; 
        strncpy(s.name, argv[3], sizeof(s.name));
        s.name[sizeof(s.name) - 1] = '\0';
        s.passengers = atoi(argv[4]);
        s.speed = atof(argv[5]);
        strncpy(s.destination, argv[6], sizeof(s.destination));
        s.destination[sizeof(s.destination) - 1] = '\0';

        FILE *starship_file = open_starship_file();
        record_write(starship_file, record_num, &s);
        fclose(starship_file);
        return 0;

    } else {
        printf("usage: ssdb r rec | w rec name passengers speed dest\n");
        return 1;
    }
}