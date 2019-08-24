//lattice dependent code
//3-12 lattice with nearest and next nearest neighbors

#include "lattice.h"

void boundaries(void)
{
  int i,face,row,column; 

  for (i=0; i<N; i++) {
    row=(i-i%(3*L/2))/(L/2);
  
    if ((i-row*L/2)>L-1) {row++; if ((i-(row-1)*L/2-L)>L/4-1) row++;}

    if (!(row%6)) {     // long row, starting with down triangle
      column=i-row*L/2;
      if (column%4==0) 
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(row*L/2+L+column/4)%N;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=i;
	  nn[i][11]=(i-1+N)%N;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;
	  if (!column) nn[i][11]=i;
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=(row*L/2+L+(column-1)/4)%N;
	  nn[i][11]=(i-1+N)%N;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;
	  if (!column) nn[i][11]=i;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=(i-1+N)%N;
	  nn[i][11]=i;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=((row-3)*L/2+L+L/4+(column-2)/4+N)%N;
	  if (!column) nn[i][10]=i;
	  if (row==0) nn[i][20]=i; 
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=(i-1+N)%N;
	  nn[i][11]=((row-3)*L/2+L+L/4+(column-3)/4+N)%N;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i; 
	  if (!column) nn[i][10]=i;
	  if (row==0) nn[i][11]=i; 
	}
      if (!(column-L+1)) nn[i][0]=i;
      
    }

    if (!((row+5)%6)) { // short row, triangles above
      
      column=i-(row-1)*L/2-L;
	  nn[i][0]=i;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=(i+L/4)%N;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=i;
	  nn[i][11]=i;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=(i-column-L+column*4+N)%N;
	  nn[i][17]=(i-column-L+column*4+1+N)%N;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;

    }
    if (!((row+4)%6)) { // short row, triangles above
      
      column=i-(row-2)*L/2-L-L/4;
	  nn[i][0]=i;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=(i-column+L/4+column*4+1)%N;
	  nn[i][5]=(i-column+L/4+column*4)%N;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=i;
	  nn[i][11]=i;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i-L/4;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;

    }

  

    if (!((row+3)%6)) {     // long row, starting with down triangle
      column=i-row*L/2;
      if ((column+2)%4==0) 
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(row*L/2+L+(column-2)/4)%N;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=i;
	  nn[i][11]=(i-1+N)%N;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;
	  if (!column) nn[i][11]=i;
	}
      if ((column+2)%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=(row*L/2+L+(column-3)/4)%N;
	  nn[i][11]=(i-1+N)%N;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;
	  if (!column) nn[i][11]=i;
	}
      if ((column+2)%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=(i-1+N)%N;
	  nn[i][11]=i;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=((row-3)*L/2+L+L/4+(column)/4+N)%N;
	  if (!column) nn[i][10]=i;
	}
      if ((column+2)%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=(i-1+N)%N;
	  nn[i][11]=((row-3)*L/2+L+L/4+(column-1)/4+N)%N;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;
	  if (!column) nn[i][10]=i;
	}
      if (!(column-L+1)) nn[i][0]=i;

    }

    if (!((row+2)%6)) { // short row, triangles above
      
      column=i-(row-1)*L/2-L;
	  nn[i][0]=i;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  nn[i][6]=(i+L/4)%N;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=i;
	  nn[i][11]=i;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i;
	  nn[i][16]=(i-column-L+column*4+N+2)%N;
	  nn[i][17]=(i-column-L+column*4+1+N+2)%N;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;

    }
    if (!((row+1)%6)) { // short row, triangles above
      
      column=i-(row-2)*L/2-L-L/4;
	  nn[i][0]=i;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=(i-column+L/4+column*4+1+2)%N;
	  nn[i][5]=(i-column+L/4+column*4+2)%N;
	  nn[i][6]=i;
	  nn[i][7]=i;
	  nn[i][8]=i;
	  nn[i][9]=i;
	  nn[i][10]=i;
	  nn[i][11]=i;
	  nn[i][12]=i;
	  nn[i][13]=i;
	  nn[i][14]=i;
	  nn[i][15]=i-L/4;
	  nn[i][16]=i;
	  nn[i][17]=i;
	  nn[i][18]=i;
	  nn[i][19]=i;
	  nn[i][20]=i;
	  if (row==L-1) {nn[i][4]=i;nn[i][5]=i;}
    }

  }
}


void decorate(int face)
{
      int t[11];

      t[0]=nn[face][0];
      nn[face][1] = nn[t[0]][0]; t[1]=nn[face][1]; nn[t[1]][9] = face;
      nn[face][2] = nn[t[1]][0]; t[2]=nn[face][2]; nn[t[2]][9] = face;
      nn[face][3] = nn[t[2]][1]; t[3]=nn[face][3]; nn[t[3]][13] = face;
      nn[face][4] = nn[t[3]][6]; t[4]=nn[face][4]; nn[t[4]][11] = face;
      nn[face][5] = nn[t[4]][5]; t[5]=nn[face][5]; nn[t[5]][15] = face;
      nn[face][6] = nn[t[5]][10]; t[6]=nn[face][6]; nn[t[6]][15] = face;
      nn[face][7] = nn[t[6]][11];t[7]=nn[face][7]; nn[t[7]][15] = face;
      nn[face][8] = nn[t[7]][11]; t[8]=nn[face][8]; nn[t[8]][15] = face;
      nn[face][9] = nn[t[8]][11];t[9]=nn[face][9];nn[t[9]][16] = face;
      t[10]=nn[face][10];

      nn[t[0]][1]=t[2]; nn[t[2]][10]=t[0];
      nn[t[0]][2]=t[3]; nn[t[3]][14]=t[0];
      nn[t[0]][3]=t[4]; nn[t[4]][12]=t[0];
      nn[t[0]][4]=t[5]; nn[t[5]][16]=t[0];
      nn[t[0]][5]=t[6]; nn[t[6]][16]=t[0];
      nn[t[0]][6]=t[7]; nn[t[7]][15]=t[0];
      nn[t[0]][7]=t[8]; nn[t[8]][14]=t[0];
      nn[t[0]][8]=t[9]; nn[t[9]][17]=t[0];
      nn[t[0]][9]=t[10]; nn[t[10]][18]=t[0];
     
      nn[t[1]][1]=t[3]; nn[t[3]][15]=t[1];
      nn[t[1]][2]=t[4]; nn[t[4]][13]=t[1];
      nn[t[1]][3]=t[5]; nn[t[5]][17]=t[1];
      nn[t[1]][4]=t[6]; nn[t[6]][17]=t[1];
      nn[t[1]][5]=t[7]; nn[t[7]][16]=t[1];
      nn[t[1]][6]=t[8]; nn[t[8]][17]=t[1];
      nn[t[1]][7]=t[9]; nn[t[9]][18]=t[1];
      nn[t[1]][8]=t[10]; nn[t[10]][19]=t[1];
 
      nn[t[2]][2]=t[4];nn[t[4]][14]=t[2];
      nn[t[2]][3]=t[5];nn[t[5]][18]=t[2];
      nn[t[2]][4]=t[6];nn[t[6]][18]=t[2];
      nn[t[2]][5]=t[7];nn[t[7]][17]=t[2];
      nn[t[2]][6]=t[8];nn[t[8]][16]=t[2];
      nn[t[2]][7]=t[9];nn[t[9]][19]=t[2];
      nn[t[2]][8]=t[10];nn[t[10]][20]=t[2];

      nn[t[3]][7]=t[5];nn[t[5]][19]=t[3];
      nn[t[3]][8]=t[6];nn[t[6]][19]=t[3];
      nn[t[3]][9]=t[7];nn[t[7]][18]=t[3];
      nn[t[3]][10]=t[8];nn[t[8]][17]=t[3];
      nn[t[3]][11]=t[9];nn[t[9]][20]=t[3];
      nn[t[3]][12]=t[10];nn[t[10]][0]=t[3];

      nn[t[4]][6]=t[6];nn[t[6]][20]=t[4];
      nn[t[4]][7]=t[7];nn[t[7]][19]=t[4];
      nn[t[4]][8]=t[8];nn[t[8]][18]=t[4];
      nn[t[4]][9]=t[9];nn[t[9]][0]=t[4];
      nn[t[4]][10]=t[10];nn[t[10]][1]=t[4];

      nn[t[5]][11]=t[7];nn[t[7]][20]=t[5];
      nn[t[5]][12]=t[8];nn[t[8]][19]=t[5];
      nn[t[5]][13]=t[9];nn[t[9]][1]=t[5];
      nn[t[5]][14]=t[10];nn[t[10]][2]=t[5];

      nn[t[6]][12]=t[8];nn[t[8]][20]=t[6];
      nn[t[6]][13]=t[9];nn[t[9]][2]=t[6];
      nn[t[6]][14]=t[10];nn[t[10]][3]=t[6];

      nn[t[7]][12]=t[9];nn[t[9]][3]=t[7];
      nn[t[7]][13]=t[10];nn[t[10]][4]=t[7];
    
      nn[t[8]][12]=t[10];nn[t[10]][5]=t[7];

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
