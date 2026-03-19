#include <stdio.h>
#include <string.h>
#include <ctype.h>


void encrypt(char message[], int key) {
    int i;
    int len = strlen(message);
    for(i = 0; i < len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

void decrypt(char message[], int key) {
    int i;
    int len = strlen(message);
    for(i = 0; i < len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}

int main() {
    char password[20];
    char correctPassword[] = "1234";
    char message[200];
    int key;
    int choice;
    char save;
    char filename[100];
    FILE *file;
    char again;
    int i;

    printf("Enter password to access the tool: ");
    scanf("%s", password);
    getchar(); 

    if(strcmp(password, correctPassword) != 0) {
        printf("Access denied!\n");
        return 0;
    }

    printf("Access granted!\n\n");

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
            getchar();

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
            printf("Enter your message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; 
            printf("Enter the key (number): ");
            scanf("%d", &key);
            getchar(); 

            if(choice == 1) {
                encrypt(message, key);
                printf("\nEncrypted message: %s\n", message);
            } else {
                decrypt(message, key);
                printf("\nDecrypted message: %s\n", message);
            }

            printf("\nDo you want to save the result to a file? (y/n): ");
            scanf(" %c", &save);
            getchar();

            if(save == 'y' || save == 'Y') {
                printf("Enter filename to save (with .txt): ");
                scanf("%s", filename);
                getchar();

                file = fopen(filename, "w");
                if(file == NULL) {
                    printf("Error opening file.\n");
                    continue;
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
