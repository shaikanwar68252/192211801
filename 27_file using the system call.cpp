#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[100];
    char filename[50];

    printf("Enter the file name: ");
    scanf("%s", filename);

    // Creating the file
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error creating the file.\n");
        exit(1);
    }

    printf("Enter data to write to the file (maximum 100 characters):\n");
    scanf(" %[^\n]", data);

    // Writing data to the file
    fprintf(file, "%s", data);

    // Closing the file
    fclose(file);

    printf("Data written to the file successfully!\n");

    // Reading data from the file
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("\nContents of the file:\n");

    char c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Closing the file
    fclose(file);

    return 0;
}
