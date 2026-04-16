#include <stdio.h>
#include <string.h>
#include "login.h"
#include "admin.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Pakai: ./app username password\n");
        return 1;
    }

    char role[10];

    if (!loginUser(argv[1], argv[2], role)) {
        printf("Login gagal!\n");
        return 1;
    }

    printf("Login berhasil sebagai %s\n", role);

    if (strcmp(role, "admin") == 0) {
        menuAdmin();
    } else {
        menuUser(argv[1]);
    }

    return 0;
}