
#include <stdio.h>
#include <string.h>

int main() {
    char cipher[3000];
    int i = 0;

    const char *symbols[] = {
        "5", "3", "‡", "†", "0", ")", "6", "*",
        ";", "4", "8", "2", ".", "¶", "]", ":",
        "(", "9", "1", "?", "—"
    };

    const char letters[] = {
        'a','g','o','d','l','e','n','t','h','i',
        's','b','r','v','f','y','u','m','w','c','p'
    };

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    printf("Decrypted message:\n");

    while (cipher[i] != '\0') {
        int found = 0, j;

        for (j = 0; j < 21; j++) {
            int len = strlen(symbols[j]);

            if (strncmp(&cipher[i], symbols[j], len) == 0) {
                putchar(letters[j]);
                i += len;
                found = 1;
                break;
            }
        }

        if (!found)
            putchar(cipher[i++]);
    }

    return 0;
}

