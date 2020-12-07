#include <stdio.h>
#include "mpi.h"
#include <math.h>
 
int main(int argc, char **argv)
{
double pi;
int pn, n, p;
int t = 10;
double var = pow(-1, p-1);
 
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &pn);
MPI_Comm_size(MPI_COMM_WORLD, &n);
MPI_Status st;
 
if(pn == 0)
{
p = pn + 1;
pi = var / ((2*p)-1)*4;
MPI_Send(&pi, 1, MPI_DOUBLE, pn+1, t, MPI_COMM_WORLD);
}
if((pn > 0) && (pn<n))
{
MPI_Recv(&pi, 1, MPI_DOUBLE, pn-1, t, MPI_COMM_WORLD, &st);
p = pn+1;
pi = pi/4;
pi = pi+var/((2*p)-1);
pi = pi*4;
printf("Process: %d, approximation: %f\n", pn, pi);
if(pn != n-1)
{
MPI_Send(&pi, 1, MPI_DOUBLE, pn+1, t, MPI_COMM_WORLD);
}
}
MPI_Finalize();
return 0;
}
