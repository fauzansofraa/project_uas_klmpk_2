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
void lihatPinjam(char *user) {
    FILE *f = fopen("data/pinjam.txt", "r");

    char u[50], alat[50];
    int found = 0;

    printf("\n=== PINJAMAN ANDA ===\n");

    while (fscanf(f, "%[^|]|%[^\n]\n", u, alat) != EOF) {
        if (strcmp(u, user) == 0) {
            printf("- %s\n", alat);
            found = 1;
        }
    }

    if (!found) printf("Belum ada pinjaman\n");

    fclose(f);
}
void menuUser(char *user) {
    int pilih;

    do {
        printf("\n=== USER ===\n");
        printf("1. Lihat Alat\n");
        printf("2. Pinjam\n");
        printf("3. Lihat Pinjaman\n");
        printf("4. Kembalikan\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        if (pilih == 1) lihatAlat();
        if (pilih == 2) pinjam(user);
        if (pilih == 3) lihatPinjam(user);
        if (pilih == 4) kembalikan(user);

    } while (pilih != 5);
}