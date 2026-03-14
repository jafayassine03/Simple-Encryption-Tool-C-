#include <stdio.h>
#include <string.h>

int main() {
    char message[200];
    int key;
    int choice;
    int i;

    printf("=== Simple Encryption Tool ===\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");

    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar(); 

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (number): ");
    scanf("%d", &key);

    if(choice == 1) {
        for(i = 0; i < strlen(message); i++) {
            message[i] = message[i] + key;
        }
        printf("\nEncrypted message: %s", message);
    }
    else if(choice == 2) {
        for(i = 0; i < strlen(message); i++) {
            message[i] = message[i] - key;
        }
        printf("\nDecrypted message: %s", message);
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}
