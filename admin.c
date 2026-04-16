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
void hapusAlat() {
    FILE *f = fopen("data/alat.txt", "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (!f || !temp) {
        printf("Gagal buka file!\n");
        return;
    }

    char line[200];
    unsigned int target;
    int found = 0;

    printf("Masukkan ID alat yang dihapus: ");
    scanf("%u", &target);

    while (fgets(line, sizeof(line), f)) {
        unsigned int id, tahun, jumlah;
        char nama[50], merek[50], model[50];

        int hasil = sscanf(line, "%u|%[^|]|%[^|]|%[^|]|%u|%u",
            &id, nama, merek, model, &tahun, &jumlah);

        if (hasil != 6) continue;

        if (id != target) {
            fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
                id,nama,merek,model,tahun,jumlah);
        } else {
            found = 1;
        }
    }

    fclose(f);
    fclose(temp);

    remove("data/alat.txt");
    rename("data/temp.txt", "data/alat.txt");

    if (found)
        printf("Alat berhasil dihapus!\n");
    else
        printf("ID tidak ditemukan!\n");
}
