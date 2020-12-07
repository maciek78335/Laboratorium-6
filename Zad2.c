#include<stdio.h>
#include "mpi.h"

float f(float x)
{
return x*x;
}

int main(int argc, char **argv)
{
int r, s;
MPI_Init(&argc, &argv);
MPI_Comm_size(MPI_COMM_WORLD, &s);
MPI_Comm_rank(MPI_COMM_WORLD, &r);
MPI_Status st;
  
float res = 0;
float b = 10;
float a = 0;
float dx = (b-a)/s;
if(r != s-1)
{
  MPI_Recv(&res, 1, MPI_FLOAT, r+1, 25, MPI_COMM_WORLD, &st);
}
if(r+1 == s)
{
  res = res + f(b)/2;
}
else if(r == 0)
{
  res = res + f(a)/2;
}
else
{
  res = res + f(a+r*dx);
}
  
if(r!=0)
{
  MPI_Send(&res, 1, MPI_FLOAT, r-1, 25, MPI_COMM_WORLD);
}
else
{
  printf("%f\n", res*dx);
}
MPI_Finalize();
return 0;
}
