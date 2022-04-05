#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<conio.h>
#include <process.h>

/*
 * Author: Ife Sunmola.
 *
 * DISCLAIMER: THIS PROGRAM SHOULD NOT BE USED ON CONFIDENTIAL FILES AND SHOULD NOT BE CONSIDERED AS AN ACTUAL
 *             ENCRYPTION TOOL.
 * This program can:
 *      --encrypt a .txt file and save the encrypted file in the same working directory
 *      --decrypt a .txt file (that has been encrypted) and save the decrypted file in the same working directory
 * */
// DECRYPT_MARKER is used to mark a file as decrypted. If the user tries to decrypt a file that doesn't have this as the
// first line, an error message will be displayed
const char DECRYPT_MARKER[] = "~~~~~~~~~\n";
const char INDENTATION[] = "            "; //spacing for the menu options
const char LINE_BREAKER[] = "            |---------------------------------------------|\n"; // name descriptive
const int OFFSET = 69; //Used to encrypt and decrypt. Don't ask why that number.

/*
 * The encrypt function:
 *          - takes a file path/location of the file to be encrypted
 *          - encrypts and saves it as encrypted.txt
 *          - and returns true or false if the operation was successful
 * */
bool encrypt(char to_encrypt[]) {
    FILE* to_read = fopen(to_encrypt, "r");// open for reading
    bool was_encrypted = false; // return value
    char letter;
    if (to_read != NULL) {// the file was successfully opened for reading, time to write
        FILE* to_write = fopen("encrypted.txt", "w"); // for writing
        fprintf(to_write, DECRYPT_MARKER); //  add DECRYPT_MARKER as the first line
        while ((letter = (char) fgetc(to_read)) != EOF) {// reading char by char, till EOF
            putc(letter + OFFSET, to_write); // write to encrypted.txt
        }
        was_encrypted = true;// file was opened and no errors occurred
        fclose(to_write);// close files
    }
    fclose(to_read);
    return was_encrypted;//returns false if the file could not be opened
}

/*
 * The decrypt_pre_check function:
 *          - takes a pointer to a file to be decrypted
 *          - checks if the file has DECRYPT_MARKER
 *          - returns true if it has or false if it does not
 *
 *  If false is returned, the file will not be decrypted
 * */
bool decrypt_pre_check(FILE* to_read) {
    // When this function gets back to decrypt(), the pointer of to_read will be at the next first_line. i.e, the first_line
    // where the file actual starts from
    char first_line[255]; // to store the first first_line for checking. Enough space?
    fgets(first_line, sizeof(first_line), to_read);
    if (strcmp(first_line, DECRYPT_MARKER) == 0) {// 0 means the same
        return true;
    }
    return false;
}

/*
 * The decrypt function:
 *          - takes a file path/location of the file to be decrypted
 *          - decrypts and saves it as decrypted.txt
 *          - and returns true or false if the operation was successful
 *
 * If the user tries to decrypt a file that wasn't encrypted, the operation will fail.
 * */
bool decrypt(char to_decrypt[]) {
    bool was_decrypted = false;
    char letter;
    FILE* to_read = fopen(to_decrypt, "r");// open for reading
    if (to_read != NULL) {// file was opened successfully
        if (decrypt_pre_check(to_read)) {// if true, the file has been encrypted before, proceed to decrypt
            FILE* to_write = fopen("decrypted.txt", "w");
            while ((letter = (char) fgetc(to_read)) != EOF) {
                putc(letter - OFFSET, to_write);
            }
            was_decrypted = true;
            fclose(to_write);
        }
    }
    fclose(to_read);
    return was_decrypted;//returns false if the file could not be opened, or if the file has not been encrypted before
}

/*
 * This method:
 *      - prints the options available to the user
 *      - asks the user for their choice
 *      - and returns it
 * */
int show_menu_and_get_input() {
    int user_input;
    printf("%s______________________________________________\n", INDENTATION);
    fflush(stdout);
    printf("%s|                                             |\n", INDENTATION);
    fflush(stdout);
    printf("%s|Welcome to the encrypting/decrypting program.|\n", INDENTATION);
    fflush(stdout);
    printf("%s|Menu:                                        |\n", INDENTATION);
    fflush(stdout);
    printf("%s|1. Encrypt a file                            |\n", INDENTATION);
    fflush(stdout);
    printf("%s|2. Decrypt an encrypted file                 |\n", INDENTATION);
    fflush(stdout);
    printf("%s|3. Quit                                      |\n", INDENTATION);
    fflush(stdout);
    printf("%s|What would you like to do (1 or 2)? ", INDENTATION);
    fflush(stdout);
    scanf("%d", &user_input);
    getchar();
    printf("%s", LINE_BREAKER);
    fflush(stdout);
    return user_input;
}

// driver method
int main() {
    int user_input = show_menu_and_get_input();
    while (!(user_input > 0 && user_input <= 3)) {// keep asking till the user enters something valid
        system("cls"); //clear screen each time
        printf("%sInvalid choice, try again\n", INDENTATION);
        fflush(stdout);
        user_input = show_menu_and_get_input();
    }
    if (user_input == 3) { // quit
        printf("%s|Thanks for stopping by                       |\n", INDENTATION);
        fflush(stdout);
        printf("%s", LINE_BREAKER);
        fflush(stdout);
    }
        //TODO: SEPARATE THE ELSE TO DIFFERENT FUNCTIONS
    else {
        char user_file_path[100];
        printf("%s|Enter the file path:\n", INDENTATION);// get the file to encrypt/decrypt
        fflush(stdout);

        printf("%s|", INDENTATION);
        fflush(stdout);
        scanf("%s", user_file_path);
        getchar();

        printf("%s", LINE_BREAKER);
        fflush(stdout);

        bool success;// used to print error messages
        if (user_input == 1) {// encrypting
            success = encrypt(user_file_path);
            if (success) {// file was encrypted
                printf("%s|The file was ENCRYPTED successfully and saved|\n", INDENTATION);
                fflush(stdout);
                printf("%s|as encrypted.txt                             |\n", INDENTATION);
                fflush(stdout);
            }
            else {// not encrypted
                printf("%s|The file could not be read                   |\n", INDENTATION);
                fflush(stdout);
            }
            printf("%s", LINE_BREAKER);
        }
        else if (user_input == 2) {// decrypting
            success = decrypt(user_file_path);
            if (success) {// was decrypted
                printf("%s|The file was DECRYPTED successfully and saved|\n", INDENTATION);
                fflush(stdout);
                printf("%s|as decrypted.txt                             |\n", INDENTATION);
                fflush(stdout);
            }
            else {// problem happened
                printf("%s|An error occurred. Is the file path correct? |\n", INDENTATION);
                fflush(stdout);
                printf("%s|Has the file been encrypted with us before?  |\n", INDENTATION);
                fflush(stdout);
            }
            printf("%s", LINE_BREAKER);
            fflush(stdout);
        }
    }
    return 0;
}






