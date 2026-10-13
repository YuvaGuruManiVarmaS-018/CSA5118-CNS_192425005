#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[500];
    int key, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);
    key = ((key % 26) + 26) % 26;

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i]))
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        else if (islower((unsigned char)text[i]))
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }

    printf("Ciphertext: %s", text);
    return 0;
}

