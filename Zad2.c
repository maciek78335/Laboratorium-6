#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<time.h>
#include "mpi.h"

float fx(float x){
return x*x;
}

int main(int argc, char **argv)
{
int rank, size;
int a, b, n, i, j, p, r;
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
srand(time(NULL));
printf("Podaj p: ");
scanf("%d", &p);

for(i=0; i<=p; i++)
{
n = rand()%10;
a = rand()%10;
b = rand()%10+10;
float c = 0;
float h = (b-a)/n;
for(int j=1; j<= n-1; j++)
{
c += fx(a+1*h);
}
c += (fx(a) + fx(b))/2;
c *= h;
printf("%f", c);
}
printf("process %d of %d", rank, size);
MPI_Finalize();
return 0;
}
