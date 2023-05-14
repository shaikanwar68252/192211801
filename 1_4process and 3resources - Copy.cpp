#include<stdio.h>
int main()
{
	int n,m,i,j,max[4][3],allocation[4][3],need[4][3];
	int status[4];
	printf("\nEnter the no.of process:");
	scanf("%d",&n);
	printf("\nEnter the no.of resources:");
	scanf("%d",&m);
	
	//set the status of process
	for(i=0;i<n;i++)
		status[i]=0;
	//get the max matrix
	for(i=0;i<n;i++)
	{
		printf("\nEnter the resources of the %d process",i);
		for(j=0;j<m;j++)	
		{
			printf("\nEnter the %d resources for the %d process",j,i);
			scanf("%d",&max[i][j]);
			
		}
	}
	//get the allocation matrix
	for(i=0;i<n;i++)
	{
		printf("\nEnter the resources for the %d process",i);
		for(j=0;j<m;j++)
		{
			printf("\nEnter the %d the resources for the process",j,i);
				scanf("%d",&allocation[i][j]);
	}				
	}
	
	//comput the need matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	//display the matrix
	printf("\n The max matrix:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("\t %d",max[i][j]);
		}
	}
	printf("\n The resource allocation matrix:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("\t %d",allocation[i][j]);
		}
	}
	printf("\n The need matrix:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("\t%d",need[i][j]);
		}
	}
}
	
