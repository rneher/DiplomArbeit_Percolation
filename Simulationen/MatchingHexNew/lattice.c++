//lattice dependent code
//hexagonal  lattice with nearest and some  next nearest neighbors

#include "lattice.h"

void boundaries(void)
{
  int i;

  for (i=0; i<N; i++) {
    if ((i/L)%2) { // odd column index
      if (i%2){    //odd row
        nn[i][0] = (i+1)%(N);         //nonperiodic boundary conditions
        nn[i][4] = (i+L)%(N);
        nn[i][8] = (i-1+N)%(N);
        nn[i][1] = i;
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][5] = i;
        nn[i][6] = i;
        nn[i][7] = i;
        nn[i][9] = i;
        nn[i][10] = i;
        nn[i][11] = i;

      	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn[i][0] =i;}
	if (i>N-L-1) nn[i][4]=i;
      }else{
        nn[i][0] = (i+1)%(N);         //nonperiodic boundary conditions
        nn[i][4] = (i-1+N)%(N);
        nn[i][8] = (i-L+N)%(N);
        nn[i][1] = i;
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][5] = i;
        nn[i][6] = i;
        nn[i][7] = i;
        nn[i][9] = i;
        nn[i][10] = i;
        nn[i][11] = i;

        if (i%L==0) {nn[i][4] =i;}        //correct boundary at start and end of each row	
	if (i<L) nn[i][8]=i;

      }
    }
    else
      {
        if (i%2){    //odd row
        nn[i][0] = (i+1)%(N);         //no periodic boundary conditions
        nn[i][4] = (i-1+N)%(N);
        nn[i][8] = (i+N-L)%(N);
        nn[i][1] = i;
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][5] = i;
        nn[i][6] = i;
        nn[i][7] = i;
        nn[i][9] = i;
        nn[i][10] = i;
        nn[i][11] = i;

	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn[i][0] =i;}
	if (i<L) nn[i][8]=i;
      }else{
        nn[i][0] = (i+1)%(N);         //no periodic boundary conditions
        nn[i][4] = (i+L)%(N);
        nn[i][8] = (i-1+N)%(N);
        nn[i][1] = i;
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][5] = i;
        nn[i][6] = i;
        nn[i][7] = i;
        nn[i][9] = i;
        nn[i][10] = i;
        nn[i][11] = i;

        if (i%L==0) {nn[i][8] =i;}        //correct boundary at start and end of each row  
	if (i>N-L-1) nn[i][4]=i;
      }
    }
  }
}

void decorate(int face)
{
      nn[face][1] = nn[nn[face][0]][0];nn[nn[nn[face][0]][0]][7] = face;
      nn[face][2] = nn[nn[face][1]][4];nn[nn[nn[face][1]][4]][6] = face;
      nn[face][3] = nn[nn[face][4]][0];nn[nn[face][3]][9] = face;
      nn[nn[face][0]][1] = nn[face][2];nn[nn[face][2]][7]=nn[face][0];
      nn[nn[face][0]][2] = nn[face][3];nn[nn[face][3]][10]=nn[face][0];
      nn[nn[face][0]][3]= nn[face][4];nn[nn[face][4]][9]=nn[face][0];
      nn[nn[face][1]][5] = nn[face][3];nn[nn[face][3]][11] = nn[face][1];
      nn[nn[face][1]][6] = nn[face][4];nn[nn[face][4]][10] = nn[face][1];
      nn[nn[face][4]][11] = nn[face][2];nn[nn[face][2]][5] = nn[face][4];
 
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
