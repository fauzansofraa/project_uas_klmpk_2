#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "admin.h"
#include "user.h"

// pakai function dari user biar sama
// lihatAlat() dipakai bersama

void tambahAlat() {
    FILE *f = fopen("data/alat.txt", "a");

    unsigned int id, tahun, jumlah;
    char nama[50], merek[50], model[50];

    printf("ID: "); scanf("%u", &id);
    printf("Nama: "); scanf(" %[^\n]", nama);
    printf("Merek: "); scanf(" %[^\n]", merek);
    printf("Model: "); scanf(" %[^\n]", model);
    printf("Tahun: "); scanf("%u", &tahun);
    printf("Jumlah: "); scanf("%u", &jumlah);

    fprintf(f, "%u|%s|%s|%s|%u|%u\n",
        id,nama,merek,model,tahun,jumlah);

    fclose(f);
}
