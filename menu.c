#include <stdio.h>
#include "menu.h"
#include "admin.h"
#include "user.h"
#include "auth.h"


void menuAdmin() {
    int p;

    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1.Tambah 2.Edit 3.Hapus 4.TambahAkun 0.Logout\n");
        printf("Pilih: ");
        scanf("%d", &p); getchar();

        if (p == 1) tambahAlat();
        else if (p == 2) editAlat();
        else if (p == 3) hapusAlat();
        else if (p == 4) tambahAkun();

    } while (p != 0);
}

void menuUser(char username[]) {
    int p;

    do {
        printf("\n== MENU USER (%s) ==\n", username);
        printf("1.Lihat 2.Pinjam 3.LihatPinjam 4.Kembali 0.Logout\n");
        printf("Pilih: ");
        scanf("%d", &p); getchar();

        if (p == 1) lihatAlat();
        else if (p == 2) pinjamAlat(username);
        else if (p == 3) lihatPeminjaman(username);
        else if (p == 4) kembalikanAlat(username);

    } while (p != 0);
}