#include <stdio.h>
#include <stdbool.h>

bool encrypt(char to_encrypt[]) {
    FILE* to_read = fopen(to_encrypt, "r");
    FILE* to_write = fopen("encrypted.txt", "w");
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
    FILE* to_write = fopen("decrypted.txt", "w");
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

int main() {
    char file_name[50] = "C:\\Users\\sunmo\\Documents\\cLion\\encryptor\\file.txt";

    if (encrypt(file_name)) {
        printf("Your file was ENCRYPTED successfully.\n");
    }
    else {
        printf("Error! Your file could not be read. Check the path.");
    }

    if (decrypt("encrypted.txt")) {
        printf("Your file was DECRYPTED successfully.\n");
    }
    else {
        printf("Error! Your file could not be read. Check the path.");
    }
    return 0;
}






