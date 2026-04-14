#include <stdio.h>
#include <string.h>

#define MAX 100

struct Alat {
    int id, jumlah;
    char nama[50];
};
struct Pinjam {
    int id;
    char user[50];
};
int loadAlat(struct Alat a[]) {
    FILE *f = fopen("alat.txt", "r");
    int i = 0;

    if (!f) return 0;

    while (fscanf(f, "%d;%[^;];%d\n",
        &a[i].id, a[i].nama, &a[i].jumlah) != EOF) {
        i++;
    }

    fclose(f);
    return i;
}


void saveAlat(struct Alat a[], int n) {
    FILE *f = fopen("alat.txt", "w");

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d;%s;%d\n",
            a[i].id, a[i].nama, a[i].jumlah);
    }

    fclose(f);
}


int loadPinjam(struct Pinjam p[]) {
    FILE *f = fopen("pinjam.txt", "r");
    int i = 0;

    if (!f) return 0;

    while (fscanf(f, "%d;%[^\n]\n",
        &p[i].id, p[i].user) != EOF) {
        i++;
    }

    fclose(f);
    return i;
}


void savePinjam(struct Pinjam p[], int n) {
    FILE *f = fopen("pinjam.txt", "w");

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d;%s\n",
            p[i].id, p[i].user);
    }

    fclose(f);
}


void pinjam(struct Alat a[], int na,
            struct Pinjam p[], int *np,
            int id, char user[]) {

    for (int i = 0; i < na; i++) {
        if (a[i].id == id && a[i].jumlah > 0) {
            a[i].jumlah--; // stok berkurang

            p[*np].id = id;
            strcpy(p[*np].user, user);
            (*np)++;

            printf("Berhasil pinjam!\n");
            return;
        }
    }
    printf("Gagal pinjam!\n");
}


void kembali(struct Alat a[], int na,
             struct Pinjam p[], int *np,
             int id, char user[]) {

    for (int i = 0; i < *np; i++) {
        if (p[i].id == id && strcmp(p[i].user, user) == 0) {

            // tambah stok
            for (int j = 0; j < na; j++) {
                if (a[j].id == id) {
                    a[j].jumlah++;
                }
            }

            // hapus data pinjam
            for (int j = i; j < *np - 1; j++) {
                p[j] = p[j + 1];
            }

            (*np)--;

            printf("Berhasil kembali!\n");
            return;
        }
    }
    printf("Data tidak ada!\n");
}