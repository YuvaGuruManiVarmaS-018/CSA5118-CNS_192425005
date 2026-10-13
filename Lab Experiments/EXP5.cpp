
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char text[500];
    int a, b, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    a = (a % 26 + 26) % 26;
    b = (b % 26 + 26) % 26;

    if (gcd(a, 26) != 1) {
        printf("Invalid a: gcd(a,26) must be 1.\n");
        return 1;
    }

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            int p = text[i] - base;
            text[i] = (a * p + b) % 26 + base;
        }
    }

    printf("Ciphertext: %s", text);
    return 0;
}

