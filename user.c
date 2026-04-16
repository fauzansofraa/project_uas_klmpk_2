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
void pinjam(char *user) {
    FILE *f = fopen("data/pinjam.txt", "a");

    char namaAlat[50];

    printf("Masukkan nama alat: ");
    scanf(" %[^\n]", namaAlat);

    fprintf(f, "%s|%s\n", user, namaAlat);

    fclose(f);

    printf("Berhasil pinjam %s\n", namaAlat);
}
