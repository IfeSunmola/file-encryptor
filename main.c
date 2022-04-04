#include <stdio.h>
# include <stdlib.h>


int main() {
    char file_name[55] = "C:\\Users\\sunmo\\Documents\\cLion\\encryptor\\file.txt";
    FILE* file_to_read = fopen(file_name, "r"); // r for reading
    FILE* file_to_write = fopen("encrypted.txt", "w");
    if (file_to_read == NULL) {
        printf("Error!! File could not be opened!");
        return -1;
    }
    char letter = ' ';

    while ((letter = fgetc(file_to_read)) != EOF) {
        char int_letter = letter + 69;
        printf("%c", int_letter);
        putc(int_letter, file_to_write);
    }

    fclose(file_to_read);
    fclose(file_to_write);

    char file_name2[100] = "C:\\Users\\sunmo\\Documents\\cLion\\encryptor\\encrypted.txt";
    FILE* to_read = fopen(file_name2, "r"); // r for reading
    letter = ' ';
    while ((letter = fgetc(to_read)) != EOF) {
        char int_letter = letter - 69;
        printf("%c", int_letter);

    }
    fclose(to_read);
    return 0;
}






