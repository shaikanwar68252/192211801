#include<stdio.h>

int main() {
   int processes = 5;  // number of processes
   int resources = 3;  // number of resources
   int allocation[5][3] = {{1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1, 1, 2}};  // allocation matrix
   int max[5][3] = {{5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3}};  // maximum matrix
   int available[3] = {3, 2, 1};  // available resources

   int need[5][3];  // need matrix
   for(int i=0; i<processes; i++) {
      for(int j=0; j<resources; j++) {
         need[i][j] = max[i][j] - allocation[i][j];  // calculate need
      }
   }

   printf("Process\tAllocation\tMax\tNeed\n");
   for(int i=0; i<processes; i++) {
      printf("P%d\t", i);
      for(int j=0; j<resources; j++) {
         printf("%d ", allocation[i][j]);
      }
      printf("\t");
      for(int j=0; j<resources; j++) {
         printf("%d ", max[i][j]);
      }
      printf("\t");
      for(int j=0; j<resources; j++) {
         printf("%d ", need[i][j]);
      }
      printf("\n");
   }

   return 0;
}
