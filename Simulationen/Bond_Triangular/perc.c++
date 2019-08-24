//Bond-Perkolation

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "rnglong.h"


#define L 1024       /* Linear dimension */
#define N (L*L)
#define NN 6        //# of neighbors
#define NB (N/2*NN)



int ptr[N];          /* Array of pointers */
int nn[N][NN];        /* Nearest neighbors */
int order[NB];        /* Bond occupation order */


int findroot(int i);
void lattice(void);
void cluster(int root);
void percolate(void);
void permutation(void);
double weigh_boundary(int root);
double total_boundary(void);
int spanning(int root);
void boundaries(void);

using namespace std;

void main(void)
{
  rngseed(0);
  boundaries();
  permutation();
  percolate();
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
int findroot(int i)
{
  if (ptr[i]<0) return i;
  return ptr[i] = findroot(ptr[i]);         //beware, recursive function
}




int spanning(int root)
{
  int i,temp=0;
  for(i=0;i<L;i++) if (findroot(i)==root) temp++;
  if (temp) {temp=0;}
  else {return 0;}
  for(i=L*(L/2);i<L*(L/2)+L;i++) if (findroot(i)==root) temp++;
  if (temp) {return 1;}
  else {return 0;}
}


//generate percolation pattern, by ZiffNewman
void percolate(void)
{
  int i,j,bond,step=NB/100,perc=0;
  int s1,s2;
  int r1,r2;
  int big_size=1,big_root=0;
  double p;

  for (i=0; i<N; i++) ptr[i] = -1;  //set every lattice site to Cluster of size 1

  for (i=0; i<NB; i++) {
    bond=order[i];
    s1=(2*bond-(2*bond)%NN)/NN;
    s2=nn[s1][(2*bond)%NN/2];
    r1 = findroot(s1); r2=findroot(s2);                //find clusters labels
    if (r2!=r1) {
      if (ptr[r1]>ptr[r2]) {       //merge clusters in unique way
        ptr[r2] += ptr[r1]; 
        ptr[r1] = r2;
        r1 = r2;
      } else {
        ptr[r1] += ptr[r2];
        ptr[r2] = r1;
      }
      if (-ptr[r1]>big_size) {big_size = -ptr[r1]; big_root=r1; }  //memorize biggest cluster
    }
       
  

    if ((i+1)%step) {}                   //perform cluster analysis every step new sites
    else 
    { 
      if (!perc) perc=spanning(big_root);
      p= (double)i/NB;
      cout << p<< "   "<<big_size<< "   " <<perc<<"\n";
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
