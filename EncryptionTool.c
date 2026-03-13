#include <stdio.h>
#include <string.h>

int main() {
    char message[200];
    int key;
    int i;

    printf(" Simple Encryption Tool\n");

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the encryption key (number): ");
    scanf("%d", &key);

    for(i = 0; i < strlen(message); i++) {
        message[i] = message[i] + key;
    }

    printf("\nEncrypted message: %s", message);

    return 0;
}
