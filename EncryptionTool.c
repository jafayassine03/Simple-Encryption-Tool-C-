#include <stdio.h>
#include <string.h>

int main() {
    char message[200];
    int key;
    int choice;
    int i;
    char save;
    char filename[100];
    FILE *file;
    char again;

    do {
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
            continue;
        }

        printf("\nDo you want to save the result to a file? (y/n): ");
        scanf(" %c", &save);

        if(save == 'y' || save == 'Y') {
            printf("Enter the filename to save (with .txt): ");
            scanf("%s", filename);

            file = fopen(filename, "w");

            if(file == NULL) {
                printf("Error opening file.\n");
                return 1;
            }

            fprintf(file, "%s", message);
            fclose(file);

            printf("Message saved to %s\n", filename);
        }

        printf("\nDo you want to process another message? (y/n): ");
        scanf(" %c", &again);
        getchar(); // consume newline
        printf("\n");

    } while(again == 'y' || again == 'Y');

    printf("Goodbye!\n");
    return 0;
}
