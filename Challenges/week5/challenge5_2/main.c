#include <stdio.h>
#include <stdlib.h>
#include "boxer.h"
#include "mather.h"

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("add: %d\n", add(a, b));
    printf("sub: %d\n", sub(a, b));
    
    draw_box(argc, argv);
    return 0;
}
