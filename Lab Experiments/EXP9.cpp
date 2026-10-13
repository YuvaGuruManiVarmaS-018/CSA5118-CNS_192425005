
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];

void createMatrix(char key[]) {
    int used[26] = {0}, r = 0, c = 0, i;
    char ch;

    used['J' - 'A'] = 1;

    for (i = 0; i < (int)strlen(key) + 26; i++) {
        ch = i < (int)strlen(key)
           ? toupper((unsigned char)key[i])
           : 'A' + i - (int)strlen(key);

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

void decryptPair(char a, char b) {
    int r1=0,c1=0,r2=0,c2=0,r,c;

    for (r=0;r<5;r++)
        for (c=0;c<5;c++) {
            if(mat[r][c]==a) r1=r,c1=c;
            if(mat[r][c]==b) r2=r,c2=c;
        }

    if(r1==r2) {
        putchar(mat[r1][(c1+4)%5]);
        putchar(mat[r2][(c2+4)%5]);
    } else if(c1==c2) {
        putchar(mat[(r1+4)%5][c1]);
        putchar(mat[(r2+4)%5][c2]);
    } else {
        putchar(mat[r1][c2]);
        putchar(mat[r2][c1]);
    }
}

int main() {
    char key[100], text[1000], clean[1000];
    int i, n=0;

    printf("Enter keyword: ");
    scanf("%99s", key);
    getchar();

    createMatrix(key);

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i=0;text[i];i++)
        if(isalpha((unsigned char)text[i])) {
            char ch=toupper((unsigned char)text[i]);
            clean[n++]=(ch=='J')?'I':ch;
        }

    printf("Decrypted text: ");
    for(i=0;i+1<n;i+=2)
        decryptPair(clean[i],clean[i+1]);

    printf("\n");
    return 0;
}

