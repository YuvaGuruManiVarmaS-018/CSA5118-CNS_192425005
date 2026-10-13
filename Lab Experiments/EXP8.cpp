
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[500];
    char plain[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipher[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i, j;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            int lower = islower((unsigned char)text[i]);
            char ch = toupper((unsigned char)text[i]);

            for (j = 0; j < 26; j++) {
                if (plain[j] == ch) {
                    text[i] = lower
                        ? tolower((unsigned char)cipher[j])
                        : cipher[j];
                    break;
                }
            }
        }
    }

    printf("Ciphertext: %s", text);
    return 0;
}

