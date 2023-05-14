#include <stdio.h>

#define MAX_PAGES 100
#define MAX_REFERENCES 100

int find_optimal_page(int pages[], int n, int reference[], int start_index)
{
    int index = -1;
    int farthest = start_index;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = start_index; j < MAX_REFERENCES; j++) {
            if (pages[i] == reference[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == MAX_REFERENCES) {
            return i;
        }
    }

    return (index == -1) ? 0 : index;
}

int main()
{
    int pages[MAX_PAGES];
    int n;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page references: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int reference[MAX_REFERENCES];
    int num_references = 0;

    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < num_references; j++) {
            if (pages[i] == reference[j]) {
                break;
            }
        }
        if (j == num_references) {
            if (num_references < MAX_REFERENCES) {
                reference[num_references++] = pages[i];
            } else {
                int index = find_optimal_page(reference, num_references, pages, i + 1);
                reference[index] = pages[i];
            }
            page_faults++;
        }
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
