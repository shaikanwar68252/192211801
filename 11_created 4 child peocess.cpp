#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid1, pid2, pid3, pid4,fork;

    pid1 = fork;
    if (pid1 == 0)
    {
        printf("First child process with PID: %d\n", getpid());
        for (int i = 1; i <= 10; i += 2)
            printf("%d ", i);
        printf("\n");
        exit(0);
    }
    else if (pid1 < 0)
    {
        printf("Failed to create first child process.\n");
        exit(1);
    }

    pid2 = fork;
    if (pid2 == 0)
    {
        printf("Second child process with PID: %d\n", getpid());
        for (int i = 2; i <= 10; i += 2)
            printf("%d ", i);
        printf("\n");
        exit(0);
    }
    else if (pid2 < 0)
    {
        printf("Failed to create second child process.\n");
        exit(1);
    }

    pid3 = fork;
    if (pid3 == 0)
    {
        printf("Third child process with PID: %d\n", getpid());
        for (int i = 3; i <= 30; i += 3)
            printf("%d ", i);
        printf("\n");
        exit(0);
    }
    else if (pid3 < 0)
    {
        printf("Failed to create third child process.\n");
        exit(1);
    }

    pid4 = fork;
    if (pid4 == 0)
    {
        printf("Fourth child process with PID: %d\n", getpid());
        for (int i = 5; i <= 50; i += 5)
            printf("%d ", i);
        printf("\n");
        exit(0);
    }
    else if (pid4 < 0)
    {
        printf("Failed to create fourth child process.\n");
        exit(1);
    }

    return 0;
}
