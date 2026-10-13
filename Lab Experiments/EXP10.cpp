
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void encryptPair(char a, char b) {
    int r1=0,c1=0,r2=0,c2=0,r,c;

    for(r=0;r<5;r++)
        for(c=0;c<5;c++) {
            if(mat[r][c]==a) r1=r,c1=c;
            if(mat[r][c]==b) r2=r,c2=c;
        }

    if(r1==r2) {
        putchar(mat[r1][(c1+1)%5]);
        putchar(mat[r2][(c2+1)%5]);
    } else if(c1==c2) {
        putchar(mat[(r1+1)%5][c1]);
        putchar(mat[(r2+1)%5][c2]);
    } else {
        putchar(mat[r1][c2]);
        putchar(mat[r2][c1]);
    }
}

int main() {
    char text[] = "Must see you over Cadogan West. Coming at once.";
    char clean[500], a, b;
    int i, n=0, j=0;

    for(i=0;text[i];i++) {
        if(isalpha((unsigned char)text[i])) {
            a=toupper((unsigned char)text[i]);
            if(a=='J') a='I';
            clean[n++]=a;
        }
    }

    clean[n]='\0';

    printf("Prepared plaintext: ");
    for(i=0;i<n;) {
        a=clean[i++];

        if(i==n) {
            b='X';
        } else if(clean[i]==a) {
            b='X';
        } else {
            b=clean[i++];
        }

        clean[j++]=a;
        clean[j++]=b;
    }

    clean[j]='\0';
    printf("%s\n",clean);

    printf("Encrypted ciphertext: ");
    for(i=0;i<j;i+=2)
        encryptPair(clean[i],clean[i+1]);

    printf("\n");
    return 0;
}

