#include <stdio.h>
#include <string.h>
#include "login.h"

int loginUser(char *user, char *pass, char *role) {
    FILE *f = fopen("data/akun.txt", "r");
    if (!f) return 0;

    char u[50], p[50], r[10];

    while (fscanf(f, "%s %s %s", u, p, r) != EOF) {
        if (strcmp(u, user) == 0 && strcmp(p, pass) == 0) {
            strcpy(role, r);
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}