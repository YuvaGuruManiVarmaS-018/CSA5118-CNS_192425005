
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[500];
    char key[27];
    int i;

    printf("Enter 26-letter substitution key: ");
    scanf("%26s", key);

    if (strlen(key) != 26) {
        printf("Key must contain 26 letters.\n");
        return 1;
    }

    int used[26] = {0};

    for (i = 0; i < 26; i++) {
        key[i] = toupper((unsigned char)key[i]);
        if (key[i] < 'A' || key[i] > 'Z' ||
            used[key[i] - 'A']) {
            printf("Invalid key: letters must be unique.\n");
            return 1;
        }
        used[key[i] - 'A'] = 1;
    }

    getchar();
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            int index = toupper((unsigned char)text[i]) - 'A';
            char result = key[index];
            text[i] = islower((unsigned char)text[i])
                    ? tolower((unsigned char)result) : result;
        }
    }

    printf("Ciphertext: %s", text);
    return 0;
}

