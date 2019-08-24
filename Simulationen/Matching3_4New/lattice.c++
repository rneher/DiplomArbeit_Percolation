//lattice dependent code
//square lattice with nearest and next nearest neighbors

#include "lattice.h"



//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i;
  
  for (i=0; i<N; i++) {         //3_4 lattice, 7 neighbors

    if (!((i/L)%4)) {
      nn[i][0] = (i+1)%(N);         //no periodic boundary conditions
      nn[i][2] = (i+L)%(N);
      nn[i][4] = (i-1+N)%(N);
      nn[i][5] = (i+N-L)%(N);
      nn[i][6] = (i+N-L+1)%N;
      nn[i][1] = i;
      nn[i][3] = i;
    if (i%L==0) {nn[i][4] = i;}        //correct boundary at start and end of each row
    if ((i+1)%L==0) {nn[i][0] = i;nn[i][6] =i;}
    }else if (!((i/L+3)%4))  {
      nn[i][0] = (i+1)%(N);         //no  periodic boundary conditions
      nn[i][1] = (i+L+1)%(N);
      nn[i][2] = (i+L)%(N);
      nn[i][3] = (i-1+N)%(N);
      nn[i][4] = i;
      nn[i][5] = (i-L+N)%N;
      nn[i][6] = i;
      if (i%L==0) {nn[i][3] = i;}        //correct boundary at start and end of each row
      if ((i+1)%L==0) {nn[i][0] = i; nn[i][1] = i;}
   }else if (!((i/L+2)%4))  {
      nn[i][0] = (i+1)%(N);         //periodic boundary conditions
      nn[i][2] = (i+L)%(N);
      nn[i][4] = (i-1+N)%(N);
      nn[i][5] = (i+N-L-1)%(N);
      nn[i][6] = (i-L+N)%N;
      nn[i][1] = i;
      nn[i][3] = i;
      if (i%L==0) {nn[i][4] = i; nn[i][5] = i;}        //correct boundary at start and end of each row
      if ((i+1)%L==0) {nn[i][0] = i;}
   }else if (!((i/L+1)%4))  {
      nn[i][0] = (i+1)%(N);         //periodic boundary conditions
      nn[i][1] = (i+L)%(N);
      nn[i][2] = (i-1+L+N)%(N);
      nn[i][3] = (i+N-1)%(N);
      nn[i][4] = i;
      nn[i][5] = (i-L+N)%N;
      nn[i][6] = i;
      if (i%L==0) {nn[i][3] = i; nn[i][2]=i; }        //correct boundary at start and end of each row
      if ((i+1)%L==0) {nn[i][0] = i;}
   }
    if (i<L) {nn[i][5]=i;nn[i][6]=i;}
    if (i>N-L) {nn[i][1]=i;nn[i][2]=i;}
  }
}

void decorate(int face)
{
      nn[face][1] = nn[nn[face][0]][2];nn[nn[face][1]][4]=face;
      nn[nn[face][0]][3]=nn[face][2];nn[nn[face][2]][6]=nn[face][0];
}

//mean euler charactersitic
inline double chi(double p)
{return p*(1-p)*(1-3*p+p*p);}


//calculate the Euler poincare Characteristic of cluster root
double examine_cluster(int root)
{
  int i,j,q;
  double bonds=0,squares=0,triangles=0,boundary=0;
  for(i=0;i<N;i++)
      if (findroot(i)==root)
      {
	 for(j=0;j<NN;j++)
	   {
	     if (ptr[nn[i][j]]==EMPTY) boundary++;                        //count bonds, cut bonds, triangles and squares around every site 
	     else bonds++;
	     if ((ptr[nn[i][j]]!=EMPTY)&&(ptr[nn[i][(j+1)%NN]]!=EMPTY)) triangles++;
	     if (!(j%2)) if ((ptr[nn[i][j]]!=EMPTY)&&(ptr[nn[i][(j+1)%NN]]!=EMPTY)&&(ptr[nn[i][(j+2)%NN]]!=EMPTY)) squares++;
	   }
      }
  bonds=bonds/2;               //bounds are double counted
  triangles=triangles/2;       //triangles are double counted (every sharp edge)
  squares=squares/4;           //every vertex of a square has been counted 

  return (-ptr[root]-bonds+triangles-squares);
}

//calculate the Euler poincare Characteristic of all clusters
double examine_total(void)
{
  int i,j,q;
  double bonds=0,squares=0,triangles=0,boundary=0,size=0;
  for(i=0;i<N;i++)
      if (ptr[i]!=EMPTY)
      {
	 size++;
	 for(j=0;j<NN;j++)
	   {
	     if (ptr[nn[i][j]]==EMPTY) boundary++;                        //count bonds, cut bonds, triangles and squares around every site 
	     else bonds++;
	     if ((ptr[nn[i][j]]!=EMPTY)&&(ptr[nn[i][(j+1)%NN]]!=EMPTY)) triangles++;
	     if (!(j%2)) if ((ptr[nn[i][j]]!=EMPTY)&&(ptr[nn[i][(j+1)%NN]]!=EMPTY)&&(ptr[nn[i][(j+2)%NN]]!=EMPTY)) squares++;
	   }
      }
  bonds=bonds/2;               //bonds are double counted
  triangles=triangles/2;       //triangles are double counted (every sharp edge)
  squares=squares/4;           //every vertex of a square has been counted 

  return (size-bonds+triangles-squares);
}
