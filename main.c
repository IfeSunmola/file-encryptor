#include <stdio.h>
#include <stdbool.h>

void display_message(bool done, char type[]) {
    if (done) {
        printf("The file was %s successfully", type);
    }
    else {
        printf("The file could not be read");
    }
}

bool encrypt(char to_encrypt[]) {
    FILE* to_read = fopen(to_encrypt, "r");
    FILE* to_write = fopen("encrypted_file.txt", "w");
    bool done = false;
    char letter = ' ';
    if (to_read != NULL) {
        while ((letter = fgetc(to_read)) != EOF) {
            char temp = letter + 69; // hehe
            putc(temp, to_write);
        }
        done = true;// a bit redundant but that's okay
    }
    fclose(to_read);
    fclose(to_write);
    return done;//returns false if the file could not be opened
}

bool decrypt(char to_decrypt[]) {
    FILE* to_read = fopen(to_decrypt, "r");
    FILE* to_write = fopen("decrypted_file.txt", "w");
    bool done = false;
    char letter = ' ';
    if (to_read != NULL) {
        while ((letter = fgetc(to_read)) != EOF) {
            char temp = letter - 69; // hehe
            putc(temp, to_write);
        }
        done = true;// a bit redundant but that's okay
    }
    fclose(to_read);
    fclose(to_write);

    return done;//returns false if the file could not be opened
}

void show_start_menu() {
    printf("Welcome to the encrypting/decrypting program.\n");
    printf("Menu:\n");
    printf("1. Encrypt my file\n2. Decrypt my file\n");
    printf("What would you like to do (1 or 2): ");
}


int main() {
    show_start_menu();
    int user_input = ' ';
    scanf("%d", &user_input);
    char user_file_path[100];
    printf("Enter the file path: ");
    scanf("%s", user_file_path);
    bool status = false;
    if (user_input == 1) {// encrypt
        status = encrypt(user_file_path);
        if (status) {
            printf("The file was ENCRYPTED successfully; and is stored as encrypted_file.txt");
        }
        else {
            printf("The file could not be read");
        }
    }
    else if (user_input == 2) {
        status = decrypt(user_file_path);
        if (status) {
            printf("The file was DECRYPTED successfully; and is stored as decrypted_file.txt");
        }
        else {
            printf("The file could not be read");
        }
    }
    return 0;
}






