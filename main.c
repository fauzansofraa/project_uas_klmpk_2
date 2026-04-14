#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "menu.h"
#include "file_handler.h"

int main(int argc, char *argv[]) {

    // Cek argumen
    if (argc != 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    
    inisialisasiSemuaFile();

    char *username = argv[1];
    char *password = argv[2];

    // 3. Login (ambil dari akun.txt)
    int role = login(username, password);

    if (role == -1) {
        printf("Login gagal!\n");
        return 1;
    }

    printf("\nLogin berhasil sebagai %s\n", username);

    
    if (role == 1) {
        
        int pilihan;
        do {
            printf("\n=== MENU ADMIN ===\n");
            printf("1. Kelola Alat\n");
            printf("2. Tambah Akun (Admin bisa nambah user)\n");
            printf("0. Logout\n");
            printf("Pilih: ");
            scanf("%d", &pilihan);

            if (pilihan == 1) {
                menuAdmin(); 
            }
            else if (pilihan == 2) {
                tambahAkun();
            }

        } while (pilihan != 0);

    } else if (role == 2) {
        
        menuUser(username);
    }

    printf("\nKeluar dari sistem.\n");
    return 0;
}