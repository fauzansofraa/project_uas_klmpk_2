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
void editAlat() {
    FILE *f = fopen("data/alat.txt", "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (!f || !temp) {
        printf("Gagal buka file!\n");
        return;
    }

    char line[200];
    unsigned int target;
    int found = 0;

    printf("Masukkan ID alat yang diedit: ");
    scanf("%u", &target);

    while (fgets(line, sizeof(line), f)) {
        unsigned int id, tahun, jumlah;
        char nama[50], merek[50], model[50];

        int hasil = sscanf(line, "%u|%[^|]|%[^|]|%[^|]|%u|%u",
            &id, nama, merek, model, &tahun, &jumlah);

        if (hasil != 6) continue;

        if (id == target) {
            found = 1;

            printf("=== Edit Data ===\n");
            printf("Nama baru: "); scanf(" %[^\n]", nama);
            printf("Merek baru: "); scanf(" %[^\n]", merek);
            printf("Model baru: "); scanf(" %[^\n]", model);
            printf("Tahun baru: "); scanf("%u", &tahun);
            printf("Jumlah baru: "); scanf("%u", &jumlah);
        }

        fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
            id,nama,merek,model,tahun,jumlah);
    }

    fclose(f);
    fclose(temp);

    remove("data/alat.txt");
    rename("data/temp.txt", "data/alat.txt");

    if (found)
        printf("Alat berhasil diedit!\n");
    else
        printf("ID tidak ditemukan!\n");
}

void tambahAkun() {
    FILE *f = fopen("data/akun.txt", "a");

    char u[50], p[50];

    printf("Username: "); scanf("%s", u);
    printf("Password: "); scanf("%s", p);

    fprintf(f, "%s %s user\n", u, p);
    fclose(f);

    printf("Akun berhasil ditambahkan!\n");
}

void menuAdmin() {
    int pilih;

    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Lihat Alat\n");
        printf("2. Tambah Alat\n");
        printf("3. Edit Alat\n");
        printf("4. Hapus Alat\n");
        printf("5. Tambah User\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        if (pilih == 1) lihatAlat(); 
        if (pilih == 2) tambahAlat();
        if (pilih == 3) editAlat();
        if (pilih == 4) hapusAlat();
        if (pilih == 5) tambahAkun();

    } while (pilih != 6);
}