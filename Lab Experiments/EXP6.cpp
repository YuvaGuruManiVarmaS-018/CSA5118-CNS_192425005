
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[1000];
    int i, c, p;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    for (i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            c = toupper((unsigned char)cipher[i]) - 'A';
            p = (9 * (c - 15 + 26)) % 26;
            cipher[i] = p + 'A';
        }
    }

    printf("Decrypted text: %s", cipher);
    return 0;
}

