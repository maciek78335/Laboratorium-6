#include<stdio.h>
#include "mpi.h"
#include<sys/types.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>


float power(float x, float y)
{
float res = 1;
for(int i=1; i<=y; i++)
{
  res *=x;
  }
  return res;
}

int main(int argc, char **argv)
{
   int rank, size, p, n;
   float pi, sum;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   printf("Podaj p: ");
   scanf("%d", &p);
   srand(time(NULL));
   
for(int i = 0; i<=p; i++){
n = rand()%5000+100;
for(int j=1; j<=n; j++)
{
  sum += power(-1,j-1)/(2*j-1);
}
pi = 4*sum;
printf("%f", pi);
}
printf("process %d of %d", rank, size);
MPI_Finalize();
return 0;
}
