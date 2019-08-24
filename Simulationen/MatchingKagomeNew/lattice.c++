//lattice dependent code
//kagome lattice with nearest and next nearest neighbors

#include "lattice.h"

void boundaries(void)
{
  int i,face,row,column; 

  for (i=0; i<N; i++) {
    row=2*(i-i%(3*L/2))/(3*L/2);
    column=i%(3*L/2);
    if ((i-row*3*L/4)>L-1) {row++;column-=L;}


    if (!(row%4)) { // long row, starting with hexagon
      if (column%2){    //1,5,7... column
        nn[i][0] = (i+1)%N;         //periodic boundary conditions
        nn[i][1] = (i+L-column/2)%(N);
        nn[i][5] = (i-1+N)%(N);
        nn[i][6] = (i-column-L/2+column/2+N)%(N);
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][4] = i;
        nn[i][7] = i;
        nn[i][8] = i;
        nn[i][9] = i;

	if (column==(L-1)) {nn[i][0] = i;nn[i][1] =i;}
      }else{
        nn[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn[i][4] = (i+L-column/2+N)%(N);
        nn[i][5] = (i-1+N)%(N);
        nn[i][9] = (i-column-L/2+column/2+N)%(N);
        nn[i][1] = i;
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][6] = i;
        nn[i][7] = i;
        nn[i][8] = i;

        if (column==0) {nn[i][5] = i;}        //correct boundary at start and end of each row
      }
    }
    if (!((row-1)%4)) { // short row, starting with hexagon
        nn[i][0] = i;         //periodic boundary conditions
        nn[i][1] = i;
        nn[i][2] = (i+L/2+column)%(N);
        nn[i][3] = (i+L/2+column-1)%(N);
        nn[i][4] = i;
        nn[i][5] = i;
        nn[i][6] = i;
        nn[i][7] = (i+column-L+N-1)%(N);
        nn[i][8] = (i+column-L+N)%(N);
        nn[i][9] = i;
	if (column==0) {nn[i][3]=i;nn[i][7]=i;}
	
    }

    if (!((row-2)%4)) { // long row, starting with triangle
      if (!(column%2)){    //1,5,7... column
        nn[i][0] = (i+1)%N;         //periodic boundary conditions
        nn[i][1] = (i+L-column/2)%(N);
        nn[i][5] = (i-1+N)%(N);
        nn[i][6] = (i-column-L/2+column/2+N)%(N);
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][4] = i;
        nn[i][7] = i;
        nn[i][8] = i;
        nn[i][9] = i;

      	//correct boundary at start and end of each row
        if (column==0) {nn[i][5] = i;}
      }else{
        nn[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn[i][4] = (i+L-column/2+N-1)%(N);
        nn[i][5] = (i-1+N)%(N);
        nn[i][9] = (i-column-L/2+column/2+N+1)%(N);
        nn[i][2] = i;
        nn[i][3] = i;
        nn[i][1] = i;
        nn[i][6] = i;
        nn[i][7] = i;
        nn[i][8] = i;

        if (column==L-1) {nn[i][0] = i;nn[i][9] = i;}        //correct boundary at start and end of each row
      }
    }
    if (!((row-3)%4)) { // short row, starting with hexagon
        nn[i][0] = i;         //periodic boundary conditions
        nn[i][1] = i;
        nn[i][2] = (i+L/2+column+1)%(N);
        nn[i][3] = (i+L/2+column)%(N);
        nn[i][4] = i;
        nn[i][5] = i;
        nn[i][6] = i;
        nn[i][7] = (i+column-L+N)%(N);
        nn[i][8] = (i+column-L+N+1)%(N);
        nn[i][9] = i;
    }
  }


   
}

void decorate(int face)
{
    nn[face][1] = nn[nn[face][0]][1];nn[nn[face][1]][7] = face;
    nn[face][2] = nn[nn[face][1]][3];nn[nn[face][2]][7] = face;
    nn[face][3] = nn[nn[face][2]][5];nn[nn[face][3]][7] = face;
    nn[nn[face][0]][2] = nn[face][2];nn[nn[face][2]][8]=nn[face][0];
    nn[nn[face][0]][3] = nn[face][3];nn[nn[face][3]][8]=nn[face][0];
    nn[nn[face][0]][4]= nn[face][4];nn[nn[face][4]][9]=nn[face][0];
    nn[nn[face][1]][5] = nn[face][3];nn[nn[face][3]][9] = nn[face][1];
    nn[nn[face][1]][6] = nn[face][4];nn[nn[face][4]][0] = nn[face][1];
    nn[nn[face][4]][1] = nn[face][2];nn[nn[face][2]][6] = nn[face][4];
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
