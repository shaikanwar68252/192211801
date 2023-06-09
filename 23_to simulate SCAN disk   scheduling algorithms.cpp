#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,j,n,head,prev,curr,distance=0,max,queue[20],temp;
    float avg;

    printf("Enter the number of disk requests: ");
    scanf("%d",&n);

    printf("Enter the queue of disk positions to be read: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d",&head);

    queue[n]=head;
    n++;

    // Sorting the queue in ascending order
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(queue[i]>queue[j])
            {
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }

    // Finding the position of initial head in the queue
    for(i=0;i<n;i++)
    {
        if(queue[i]==head)
        {
            break;
        }
    }

    prev=i;
    max=queue[n-1];

    printf("\nSCAN Disk Scheduling Algorithm:\n");
    printf("%d ",head);

    // Moving the head towards right direction
    for(i=prev+1;i<n;i++)
    {
        curr=queue[i];
        distance+=abs(curr-prev);
        printf("%d ",curr);
        prev=curr;
    }

    printf("%d ",max);

    // Moving the head towards left direction
    for(i=n-2;i>=0;i--)
    {
        curr=queue[i];
        distance+=abs(curr-prev);
        printf("%d ",curr);
        prev=curr;
    }

    avg=(float)distance/(float)n;
    printf("\n\nTotal head movement: %d",distance);
    printf("\nAverage head movement: %f",avg);

    return 0;
}
