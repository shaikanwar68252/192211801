#include <stdio.h>
#include <stdbool.h>

#define NUM_BLOCKS 16
#define INODE_BLOCKS 8
#define DATA_BLOCKS (NUM_BLOCKS - INODE_BLOCKS)
#define BLOCK_SIZE 1024
#define MIN_FILE_SIZE 1024

// Function to check if the blocks starting from a given block index are free
bool areBlocksFree(bool blocks[], int startBlockIndex, int numBlocks) {
    for (int i = startBlockIndex; i < startBlockIndex + numBlocks; i++) {
        if (blocks[i]) {
            return false;
        }
    }
    return true;
}

// Function to allocate blocks starting from a given block index
void allocateBlocks(bool blocks[], int startBlockIndex, int numBlocks) {
    for (int i = startBlockIndex; i < startBlockIndex + numBlocks; i++) {
        blocks[i] = true;
    }
}

// Function to find the next available contiguous blocks for allocation
int findNextContiguousBlocks(bool blocks[], int numBlocks) {
    int startBlockIndex = -1;

    for (int i = 0; i < DATA_BLOCKS; i++) {
        if (areBlocksFree(blocks, i, numBlocks)) {
            startBlockIndex = i;
            break;
        }
    }

    return startBlockIndex;
}

int main() {
    bool blocks[NUM_BLOCKS] = {0};
    int fileSize;
    int startBlockIndex;

    // Set the initial blocks for iNodes as allocated
    for (int i = 0; i < INODE_BLOCKS; i++) {
        blocks[i] = true;
    }

    printf("Enter the file size (in KB): ");
    scanf("%d", &fileSize);

    if (fileSize < MIN_FILE_SIZE) {
        printf("File size is too small. Minimum file size is 1 KB.\n");
        return 0;
    }

    int numBlocks = (fileSize + BLOCK_SIZE - 1) / BLOCK_SIZE;

    startBlockIndex = findNextContiguousBlocks(blocks, numBlocks);
    if (startBlockIndex == -1) {
        printf("Not enough contiguous blocks available for allocation.\n");
        return 0;
    }

    allocateBlocks(blocks, startBlockIndex, numBlocks);

    printf("Allocated blocks: %d to %d\n", startBlockIndex, startBlockIndex + numBlocks - 1);

    return 0;
}
