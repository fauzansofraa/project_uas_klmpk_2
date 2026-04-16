#include <stdio.h>
#include <string.h>
#include "user.h"

void lihatAlat() {
    FILE *f = fopen("data/alat.txt", "r");
    char line[200];

    printf("\n=== LIST ALAT ===\n");

    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }

    fclose(f);
}