//lattice dependent code
//square lattice with nearest and next nearest neighbors

#include "lattice.h"



//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i;

  for (i=0; i<N; i++) {         //square lattice, 8 neighbors
    nn[i][0] = (i+1)%(N);         //periodic boundary conditions
    nn[i][2] = (i+N-1)%(N);
    nn[i][1] = (i+L)%(N);
    nn[i][3] = (i+N-L)%(N);

    if (i%L==0) {nn[i][2] = (i+L-1)%(N); }        //correct boundary at start and end of each row
    if ((i+1)%L==0) {nn[i][0] = (i-L+1+N)%(N);}
  }
}


//mean euler charactersitic
inline double chi(double p)
{return p*(1-p)*(1-p-p*p);}


//calculate the Euler poincare Characteristic of cluster root
double examine_cluster(int root)
{
  int i,j,q;
  double bonds=0,squares=0,boundary=0;
  for(i=0;i<N;i++)
      if (findroot(i)==root)
      {
	 for(j=0;j<NN;j++)
	   {
	     if (ptr[nn[i][j]]==EMPTY) boundary++;                        //count bonds, cut bonds, triangles and squares around every site 
	     else bonds++;
	     if ((ptr[nn[i][j]]!=EMPTY)&&(ptr[nn[i][(j+1)%NN]]!=EMPTY)&&(ptr[nn[i][(j+2)%NN]]!=EMPTY)) squares++;
	   }
      }
  bonds=bonds/2;               //bounds are double counted
  squares=squares/4;           //every vertex of a square has been counted 

  return (-ptr[root]-bonds+squares);
}

//calculate the Euler poincare Characteristic of all clusters
double examine_total(void)
{
  int i,j,q;
  double bonds=0,squares=0,boundary=0,size=0;
  for(i=0;i<N;i++)
      if (ptr[i]!=EMPTY)
      {
	 size++;
	 for(j=0;j<NN;j++)
	   {
	     if (ptr[nn[i][j]]==EMPTY) boundary++;                        //count bonds, cut bonds, triangles and squares around every site 
	     else bonds++;
	     if ((ptr[nn[i][j]]!=EMPTY)&&(ptr[nn[i][(j+1)%NN]]!=EMPTY)&&(ptr[nn[i][(j+2)%NN]]!=EMPTY)) squares++;
	   }
      }
  bonds=bonds/2;               //bounds are double counted
  squares=squares/4;           //every vertex of a square has been counted 

  return (size-bonds+squares);
}
