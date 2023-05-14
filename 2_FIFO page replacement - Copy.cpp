#include <stdio.h>
#define MAX 100

int main() {
    int pages[MAX], frames[MAX], faults = 0;
    int n, m, i, j, k, flag, pos = 0;

    printf("Enter the number of page frames: ");
    scanf("%d", &m);

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for (i = 0; i < m; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            frames[pos] = pages[i];
            faults++;
            pos = (pos + 1) % m;
        }
        printf("\n%d:\t", pages[i]);
        for (k = 0; k < m; k++) {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }
    }
    printf("\nTotal number of page faults: %d\n", faults);
    return 0;
}