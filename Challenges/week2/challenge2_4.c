/* Challenge 2.4 Character Arrays */
/* Tyler Silva */

#include <stdio.h>

int alpha_index(char str[]) { 
    
    printf("Letter indexes of WOMBAT:\n");
    for (int i = 0; str[i] != '\0'; i++) { 
        int char_eval = str[i] - 'A';
        printf("%d\n", char_eval);
    }


}

int length_str(char str[]) { 
    int length = 0; 
    printf("Length of alph:\n");
    for (int i = 0; str[i] != '\0'; i++) { 
        length++;
    }
    printf("%d\n", length);
    return length;
}


int print_str(char str[]) { 

    printf("Character number values in alph: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%d\n", (int)str[i]);
    }
    return 0;
}

int main(void) {

    char alph[] = "ABCD\n";

    printf("Characters in alph:\n");
    printf("%c\n", alph[0]);
    printf("%c\n", alph[1]);
    printf("%c\n", alph[2]);

    print_str(alph);

    length_str(alph);

    alpha_index("WOMBAT");

}