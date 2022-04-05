#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char DECRYPT_MARKER[] = "~~~~~~~~~\n";

bool encrypt(char to_encrypt[]) {
    FILE* to_read = fopen(to_encrypt, "r");
    FILE* to_write = fopen("encrypted_file.txt", "w");
    fprintf(to_write, DECRYPT_MARKER);
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

bool decrypt_pre_check(FILE* to_read) {
    char line[255]; // holds one line, one line at a time
    fgets(line, 255, to_read);
    if (strcmp(line, DECRYPT_MARKER) == 0) {
        return true;
    }
    return false;
}

bool decrypt(char to_decrypt[]) {
    bool status = false;
    char letter = ' ';
    FILE* to_read = fopen(to_decrypt, "r");
    if (to_read != NULL) {
        if (decrypt_pre_check(to_read)) {
            FILE* to_write = fopen("decrypted_file.txt", "w");
            while ((letter = fgetc(to_read)) != EOF) {
                char temp = letter - 69; // hehe
                putc(temp, to_write);
            }
            status = true;// a bit redundant but that's okay
            fclose(to_write);
        }
    }
    fclose(to_read);
    //returns false if the file could not be opened, or if the file has not been encrypted before
    return status;
}

void show_start_menu() {
    printf("Welcome to the encrypting/decrypting program.\n");
    printf("Menu:\n");
    printf("1. Encrypt my file\n2. Decrypt my file\n");
    printf("What would you like to do (1 or 2): ");
}


int main() {
    int user_input = ' ';
    show_start_menu();
    scanf("%d", &user_input);

    printf("Enter the file path: ");
    char user_file_path[100];
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
            printf("An error occurred. Is the file path correct? Has the file been encrypted with us before?");
        }
    }
    return 0;
}






