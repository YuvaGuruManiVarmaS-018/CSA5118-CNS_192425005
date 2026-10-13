
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];
int used[26];

void createMatrix(char key[]) {
    int i, r = 0, c = 0;
    char ch;
    memset(used, 0, sizeof(used));
    used['J' - 'A'] = 1;

    for (i = 0; i < (int)strlen(key) + 26; i++) {
        if (i < (int)strlen(key))
            ch = toupper((unsigned char)key[i]);
        else
            ch = 'A' + i - (int)strlen(key);

        if (ch < 'A' || ch > 'Z') continue;
        if (ch == 'J') ch = 'I';

        if (!used[ch - 'A']) {
            used[ch - 'A'] = 1;
            mat[r][c++] = ch;
            if (c == 5) { c = 0; r++; }
        }
        if (r == 5) break;
    }
}

void encryptPair(char a, char b) {
    int r1, c1, r2, c2, r, c;

    for (r = 0; r < 5; r++)
        for (c = 0; c < 5; c++) {
            if (mat[r][c] == a) r1 = r, c1 = c;
            if (mat[r][c] == b) r2 = r, c2 = c;
        }

    if (r1 == r2) {
        putchar(mat[r1][(c1 + 1) % 5]);
        putchar(mat[r2][(c2 + 1) % 5]);
    } else if (c1 == c2) {
        putchar(mat[(r1 + 1) % 5][c1]);
        putchar(mat[(r2 + 1) % 5][c2]);
    } else {
        putchar(mat[r1][c2]);
        putchar(mat[r2][c1]);
    }
}

int main() {
    char key[100], text[500], clean[500], a, b;
    int i, n = 0;

    printf("Enter keyword: ");
    scanf("%99s", key);
    getchar();

    createMatrix(key);

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i]; i++)
        if (isalpha((unsigned char)text[i])) {
            a = toupper((unsigned char)text[i]);
            clean[n++] = (a == 'J') ? 'I' : a;
        }

    clean[n] = '\0';

    printf("Ciphertext: ");
    for (i = 0; i < n;) {
        a = clean[i++];
        if (i == n) {
            b = 'X';
        } else if (clean[i] == a) {
            b = 'X';
        } else {
            b = clean[i++];
        }
        encryptPair(a, b);
    }

    printf("\n");
    return 0;
}

