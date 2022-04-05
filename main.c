#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<conio.h>
#include <process.h>

//TODO: VALIDATE USER INPUT
const char DECRYPT_MARKER[] = "~~~~~~~~~\n";
const char INDENTATION[] = "            ";
const char LINE_BREAKER[] = "            |---------------------------------------------|\n";


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
    // When this function gets back to decrypt(), the pointer of to_read will be at the next line. i.e, the line
    // where the file actual starts from
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

int show_start_menu() {
    int user_input;
    printf("%s______________________________________________\n", INDENTATION);
    printf("%s|                                             |\n", INDENTATION);
    printf("%s|Welcome to the encrypting/decrypting program.|\n", INDENTATION);
    printf("%s|Menu:                                        |\n", INDENTATION);
    printf("%s|1. Encrypt a file                            |\n", INDENTATION);
    printf("%s|2. Decrypt an encrypted file                 |\n", INDENTATION);
    printf("%s|3. Quit                                      |\n", INDENTATION);
    printf("%s|What would you like to do (1 or 2)? ", INDENTATION);

    scanf("%d", &user_input);
    getchar();
    printf("%s", LINE_BREAKER);
    return user_input;
}


int main() {
    int user_input = show_start_menu();
    while (!(user_input > 0 && user_input <= 3)) {
        system("cls");
        printf("%sInvalid choice, try again\n", INDENTATION);
        user_input = show_start_menu();
    }
    if (user_input == 1 || user_input == 2) {
        printf("%s|Enter the file path:\n", INDENTATION);
        printf("%s|", INDENTATION);
        char user_file_path[100];
        scanf("%s", user_file_path);
        getchar();
        printf("%s", LINE_BREAKER);

        bool status = false;
        if (user_input == 1) {// encrypt
            status = encrypt(user_file_path);
            if (status) {
                printf("%s|The file was ENCRYPTED successfully and saved|\n", INDENTATION);
                printf("%s|as encrypted_file.txt                        |\n", INDENTATION);
            }
            else {
                printf("%s|The file could not be read                   |\n", INDENTATION);
            }
            printf("%s", LINE_BREAKER);
        }
        else if (user_input == 2) {
            status = decrypt(user_file_path);
            if (status) {
                printf("%s|The file was DECRYPTED successfully and saved|\n", INDENTATION);
                printf("%s|as decrypted_file.txt                        |\n", INDENTATION);
            }
            else {
                printf("%s|An error occurred. Is the file path correct? |\n", INDENTATION);
                printf("%s|Has the file been encrypted with us before?  |\n", INDENTATION);
                printf("%s", LINE_BREAKER);
            }
        }
    }
    else {
        printf("%s|Thanks for stopping by                       |\n", INDENTATION);
        printf("%s", LINE_BREAKER);
    }


    return 0;
}






