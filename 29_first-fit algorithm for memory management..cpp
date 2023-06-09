#include <stdio.h>

#define MAX_BLOCKS 100

typedef struct {
    int size;
    int allocated;
} Block;

void firstFit(Block blocks[], int numBlocks, int processSize) {
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            blocks[i].allocated = 1;
            printf("Process of size %d allocated to block %d.\n", processSize, i + 1);
            return;
        }
    }
    printf("No suitable block found for process of size %d.\n", processSize);
}

int main() {
    int numBlocks, i;
    Block blocks[MAX_BLOCKS];
    int processSize;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    printf("Enter the size of each block:\n");
    for (i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0;
    }

    printf("Enter the size of the process: ");
    scanf("%d", &processSize);

    firstFit(blocks, numBlocks, processSize);

    return 0;
}
