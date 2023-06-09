#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRS 100 // maximum number of directories
#define MAX_FILES 100 // maximum number of files in each directory
#define MAX_FILENAME_LEN 20 // maximum length of file name

// Define a structure to represent a file
typedef struct {
    char name[MAX_FILENAME_LEN]; // name of the file
    int size; // size of the file in bytes
} file_t;

// Define a structure to represent a directory
typedef struct {
    char name[MAX_FILENAME_LEN]; // name of the directory
    int num_files; // number of files in the directory
    file_t files[MAX_FILES]; // array of files in the directory
} dir_t;

// Define a structure to represent the file system
typedef struct {
    int num_dirs; // number of directories in the file system
    dir_t dirs[MAX_DIRS]; // array of directories in the file system
} file_system_t;

// Define a function to create a new directory in the file system
void create_dir(file_system_t *fs, char *dir_name) {
    if (fs->num_dirs == MAX_DIRS) {
        printf("Error: maximum number of directories exceeded.\n");
        return;
    }
    for (int i = 0; i < fs->num_dirs; i++) {
        if (strcmp(fs->dirs[i].name, dir_name) == 0) {
            printf("Error: directory already exists.\n");
            return;
        }
    }
    strcpy(fs->dirs[fs->num_dirs].name, dir_name);
    fs->dirs[fs->num_dirs].num_files = 0;
    fs->num_dirs++;
    printf("Directory \"%s\" created.\n", dir_name);
}

// Define a function to create a new file in a directory
void create_file(file_system_t *fs, char *dir_name, char *file_name, int file_size) {
    dir_t *dir = NULL;
    for (int i = 0; i < fs->num_dirs; i++) {
        if (strcmp(fs->dirs[i].name, dir_name) == 0) {
            dir = &fs->dirs[i];
            break;
        }
    }
    if (dir == NULL) {
        printf("Error: directory \"%s\" does not exist.\n", dir_name);
        return;
    }
    if (dir->num_files == MAX_FILES) {
        printf("Error: maximum number of files exceeded in directory \"%s\".\n", dir_name);
        return;
    }
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, file_name) == 0) {
            printf("Error: file \"%s\" already exists in directory \"%s\".\n", file_name, dir_name);
            return;
        }
    }
    strcpy(dir->files[dir->num_files].name, file_name);
    dir->files[dir->num_files].size = file_size;
    dir->num_files++;
    printf("File \"%s\" created in directory \"%s\" with size %d bytes.\n", file_name, dir_name, file_size);
}

// Define a function to list the contents of a directory
void list_dir(file_system_t *fs, char *dir_name) {
    dir_t *dir = NULL;
    for (int i = 0; i < fs->num_dirs; i++) {
        if (strcmp(fs->dirs[i].name, dir_name) == 0;
    }
}
}
