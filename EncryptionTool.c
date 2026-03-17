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
        printf("3. View Saved File\n"); 
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); 

        if(choice == 3) {
            printf("Enter filename to read: ");
            scanf("%s", filename);

            file = fopen(filename, "r");

            if(file == NULL) {
                printf("Error opening file.\n");
            } else {
                printf("\n--- File Content ---\n");
                while(fgets(message, sizeof(message), file)) {
                    printf("%s", message);
                }
                fclose(file);
                printf("\n---------------------\n");
            }
        }
        else if(choice == 1 || choice == 2) {
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
            else {
                for(i = 0; i < strlen(message); i++) {
                    message[i] = message[i] - key;
                }
                printf("\nDecrypted message: %s", message);
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
        }
        else {
            printf("Invalid choice.\n");
        }

        printf("\nDo you want to process another action? (y/n): ");
        scanf(" %c", &again);
        getchar(); 
        printf("\n");

    } while(again == 'y' || again == 'Y');

    printf("Goodbye!\n");
    return 0;
}
