#include <stdio.h>
#include <string.h>
#include "login.h"

int loginUser(char *user, char *pass, char *role) {
    FILE *f = fopen("data/akun.txt", "r");
    if (!f) return 0;

    char u[50], p[50], r[10];

    