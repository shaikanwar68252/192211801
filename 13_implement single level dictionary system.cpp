#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20
#define MAX_DIRECTORY_NAME_LENGTH 20

typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
} File;

typedef struct directory {
    char name[MAX_DIRECTORY_NAME_LENGTH];
    File files[MAX_FILES];
    int num_files;
} Directory;

void add_file(Directory *dir, char *name, int size)
{
    if (dir->num_files >= MAX_FILES) {
        printf("Directory is full\n");
        return;
    }

    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(name, dir->files[i].name) == 0) {
            printf("File already exists\n");
            return;
        }
    }

    strcpy(dir->files[dir->num_files].name, name);
    dir->files[dir->num_files].size = size;
    dir->num_files++;

    printf("File added successfully\n");
}

int main()
{
    Directory cse;
    strcpy(cse.name, "CSE");
    cse.num_files = 0;

    add_file(&cse, "A", 1024);
    add_file(&cse, "B", 2048);
    add_file(&cse, "C", 3072);

    return 0;
}
