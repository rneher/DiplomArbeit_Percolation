//Bond-Perkolation

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "rnglong.h"


#define L 2048         /* Linear dimension */
#define NHEX (L*L)
#define NNHEX 3        //# of neighbors
#define NB (3*N/2)
#define N (L*L/2)
#define NN 6        //# of neighbors
#define EMPTYHEX (-NHEX-1)
#define EMPTY (-N-1)
#define RUNS 50

#define PC 0.6527036446

int ptr_hex[NHEX];          /* Array of pointers */
int nn_hex[NHEX][NNHEX];        /* Nearest neighbors */
int order[NB];        /* Bond occupation order */
int ptr[N];          /* Array of pointers */
int nn[N][NN];        /* Nearest neighbors */
int stat_hex[NB];
int stat_tri[NB];


int findroot_hex(int i);
int findroot(int i);
void percolate(void);
void permutation(void);
void boundaries_hex(void);
void boundaries(void);
void stat(void);

using namespace std;

void main(void)
{
  int i,n0;
  double p,q,n,nhex;
  rngseed(0);
  boundaries_hex();
  boundaries();
  for(i=0;i<NB;i++) stat_tri[i]=0;
  for (i=0;i<NB;i++) stat_hex[i]=0;

  for (i=0;i<RUNS;i++)
    {
      permutation();
      percolate();
      stat();
    }

  for (n0=1;n0<=L/5;n0++)
  {
    p=0;q=0;
    n=0;nhex=0;
    for(i=0;i<NB;i++) 
      {
	if (i<n0)
	  {
	    //p+=i*stat_white[i];q+=i*stat_black[i];
	  }else{
	    p+=i*stat_tri[i];
	    n+=stat_tri[i];
	  }
      }
   for(i=0;i<NB;i++) 
      {
	if (i<n0)
	  {
	    //p+=i*stat_white[i];q+=i*stat_black[i];
	  }else{
	    q+=i*stat_hex[i];
	    nhex+=stat_hex[i];
	  }
      }
   
   cout <<n0<<"   "<<stat_hex[n0]<<"   "<<stat_tri[n0]<<"   "<<(double)(q-p)/NB/RUNS<<"   "<<(double)(nhex-n)/NB/RUNS<<"   "<<(double)(nhex-n)/(q-p)<<"\n";
  }
}


//generate randomly permuted string of [0,..,N-1], by ZiffNewman
void permutation(void)
{
  int i,j;
  int temp;

  for (i=0; i<NB; i++) order[i] = i;
  for (i=0; i<NB; i++) {
    j = i + (NB-i)*RNGLONG;
    temp = order[i];
    order[i] = order[j];
    order[j] = temp;
  }
}


//return vertex number of the vertex, that serves as label of cluster containing i
int findroot_hex(int i)
{
  if (ptr_hex[i]<0) return i;
  return ptr_hex[i] = findroot_hex(ptr_hex[i]);         //beware, recursive function
}
int findroot(int i)
{
  if (ptr[i]<0) return i;
  return ptr[i] = findroot(ptr[i]);         //beware, recursive function
}



//generate percolation pattern, by ZiffNewman
void percolate(void)
{
  int i,j,bond,row,step=NB/100,perc=0;
  int s1,s2;
  int r1,r2;
  int big_size=1,big_root=0;
  double p;

  for (i=0; i<NHEX; i++) ptr_hex[i] = EMPTYHEX;  //set every lattice site to EMTPY
  for (i=0; i<N; i++) ptr[i] = EMPTY;  //set every lattice site to EMTPY 

  for (i=0; i<NB*PC; i++) {
    bond=order[i];
    row=(bond-bond%(NNHEX*L/2))/(NNHEX*L/2);
    if ((bond%(NNHEX*L/2))<L) {s1=row*L+bond%(NNHEX*L/2);s2=nn_hex[s1][0];}
    else {s1=row*L+(bond%(NNHEX*L/2)-L)*2+row%2;s2=nn_hex[s1][1];}
    r1 = findroot_hex(s1); r2=findroot_hex(s2);                //find clusters labels
    if (ptr_hex[r1]==EMPTYHEX) ptr_hex[r1]=-1;//groesse s1 inkrement
    else ptr_hex[r1]--;
    if (ptr_hex[r2]==EMPTYHEX) ptr_hex[r2]=0;//groesse s1 inkrement
    if (r2!=r1) {
      if (ptr_hex[r1]>ptr_hex[r2]) {       //merge clusters in unique way
        ptr_hex[r2] += ptr_hex[r1]; 
        ptr_hex[r1] = r2;
        r1 = r2;
      } else {
        ptr_hex[r1] += ptr_hex[r2];
        ptr_hex[r2] = r1;
      }
      if (-ptr[r1]>big_size) {big_size = -ptr[r1]; big_root=r1; }  //memorize biggest cluster
    }
       
  }


  for (i=NB; i>NB*PC; i--) {
    bond=order[i];
    s1=(2*bond-(2*bond)%NN)/NN;
    s2=nn[s1][(2*bond)%NN/2];
    r1 = findroot(s1); r2=findroot(s2);                //find clusters labels
    if (ptr[r1]==EMPTY) ptr[r1]=-1;//groesse s1 inkrement
    else ptr[r1]--;
    if (ptr[r2]==EMPTY) ptr[r2]=0;//groesse s1 auf null
    if (r2!=r1) {
      if (ptr[r1]>ptr[r2]) {       //merge clusters in unique way
        ptr[r2] += ptr[r1]; 
        ptr[r1] = r2;
        r1 = r2;
      } else {
        ptr[r1] += ptr[r2];
        ptr[r2] = r1;
      }
    }
       
  }
}


//set adjacencies and boundary conditions
void boundaries_hex(void)            
{
  int i;
  for (i=0; i<NHEX; i++) {         //square lattice, 8 neighbors
    if ((i/L)%2) { // odd column index
      if (i%2){    //odd row
        nn_hex[i][0] = (i+1)%(NHEX);         //periodic boundary conditions
        nn_hex[i][1] = (i+L)%(NHEX);
        nn_hex[i][2] = (i-1+NHEX)%(NHEX);
    	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn_hex[i][0] = (i-L+1+NHEX)%(NHEX);}
      }else{
        nn_hex[i][0] = (i+1)%(NHEX);         //periodic boundary conditions
        nn_hex[i][1] = (i-1+NHEX)%(NHEX);
        nn_hex[i][2] = (i-L+NHEX)%(NHEX);
        if (i%L==0) {nn_hex[i][1] = (i+L-1)%(NHEX);}        //correct boundary at start and end of each row
      }
    }
    else{
        if (i%2){    //odd row
        nn_hex[i][0] = (i+1)%(NHEX);         //periodic boundary conditions
        nn_hex[i][1] = (i-1+NHEX)%(NHEX);
        nn_hex[i][2] = (i+NHEX-L)%(NHEX);
	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn_hex[i][0] = (i-L+1+NHEX)%(NHEX);}
      }else{
        nn_hex[i][0] = (i+1)%(NHEX);         //periodic boundary conditions
        nn_hex[i][1] = (i+L)%(NHEX);
        nn_hex[i][2] = (i-1+NHEX)%(NHEX);
        if (i%L==0) {nn_hex[i][2] = (i+L-1)%(NHEX);}        //correct boundary at start and end of each row

      }

    }
  }
}

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i;
  for (i=0; i<N; i++) {         //square lattice, 8 neighbors
    nn[i][0] = (i+1)%(N);         //periodic boundary conditions
    nn[i][4] = (i+N-L)%(N);
    nn[i][2] = (i+L-1)%(N);
    nn[i][1] = (i+L)%(N);
    nn[i][3] = (i-1)%(N);
    nn[i][5] = (i+N-L+1)%(N);
    if (i%L==0) {nn[i][2] = (i+2*L-1)%(N);nn[i][3] = (i+L-1)%(N); }        //correct boundary at start and end of each row
    if ((i+1)%L==0) {nn[i][0] = (i-L+1+N)%(N);nn[i][5] = (i-2*L+1+N)%(N);}
  }
}

void stat(void)
{
  int i;
  

  for(i=0;i<N;i++)
    {
      if ((ptr[i]<0)&&(ptr[i]!=EMPTY))
	{
	  stat_tri[-ptr[i]]++;
	}  
    }
  for(i=0;i<NHEX;i++) 
    {
      if  ((ptr_hex[i]<0)&&(ptr_hex[i]!=EMPTYHEX))
	{
	  stat_hex[-ptr_hex[i]]++;
	}  
    }
}
