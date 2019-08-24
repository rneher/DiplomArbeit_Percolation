#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "rnglong.h"
#include "lattice.h"

#define RUNS  (60*60*4096/L/L)

int ptr[N];          /* Array of pointers */
int nn[N][NN];        /* Nearest neighbors */
int order[N];        /* Occupation order */
int order_faces[N/3];
double pc,sigmasq;
int findroot(int i);
void lattice(void);
void cluster(int root);
void percolate(void);
void permutation_faces(void);
void permutation(void);
double weigh_boundary(int root);
double total_boundary(void);
int spanning(int root);

using namespace std;

void main(void)
{
  int decorated=0,face,row,i;
  rngseed(0);
  permutation_faces();
  boundaries();

  for(decorated=0;decorated<N/3;decorated++)
    {
      //      rngseed(0);
      if ((decorated%(N/300))==0)
	{
	      pc=0;sigmasq=0;
	  for(i=0;i<RUNS;i++)
	    {
	      permutation();
	      percolate();
	    }
	  cout <<RUNS<<"  "<<L<<"  "<<pow(L,-0.75)<<"   "<<(double)(decorated)/(N/3)<<"   "<<pc/RUNS<<"   "<<sqrt((sigmasq/(RUNS-1)-pc*pc/RUNS/RUNS)/(RUNS))<<"\n";
	}
      row=(order_faces[decorated]-(order_faces[decorated]%(L/2)))/(L/2);
      face=3*L/2*row+2*(order_faces[decorated]%(L/2-1))+row%2;
      decorate(face);
    }
  pc=0;sigmasq=0;
  for(i=0;i<RUNS;i++)
    {
      permutation();
      percolate();
    }
  cout <<RUNS<<"  "<<L<<"  "<<pow(L,-0.75)<<"   "<<(double)(decorated)/(N/3)<<"   "<<pc/RUNS<<"   "<<sqrt((sigmasq/(RUNS-1)-pc*pc/RUNS/RUNS)/(RUNS))<<"\n";

}


//generate randomly permuted string of [0,..,N-1], by ZiffNewman
void permutation(void)
{
  int i,j;
  int temp;

  for (i=0; i<N; i++) order[i] = i;
  for (i=0; i<N; i++) {
    j = i + (N-i)*RNGLONG;
    temp = order[i];
    order[i] = order[j];
    order[j] = temp;
  }
}

//generate randomly permuted string of [0,..,N-1], by ZiffNewman
void permutation_faces(void)
{
  int i,j;
  int temp;

  for (i=0; i<N/3; i++) order_faces[i] = i;
  for (i=0; i<N/3; i++) {
    j = i + (N/3-i)*RNGLONG;
    temp = order_faces[i];
    order_faces[i] = order_faces[j];
    order_faces[j] = temp;
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
  for(i=3*L*L/8;i<3*L*L/8+L;i++) if (findroot(i)==root) temp++;
  if (temp) {temp=0;}
  else {return 0;}
  for(i=0;i<N;i+=3*L/2) if (findroot(i)==root) temp++;
  if (temp) {temp=0;}
  else {return 0;}
  for(i=L/2;i<N;i+=3*L/2) if (findroot(i)==root) temp++;
  if (temp) {return 1;}
  else {return 0;}

}


//generate percolation pattern, by ZiffNewman
void percolate(void)
{
  int i,j;
  int s1,s2;
  int r1,r2;
  int big_size=0,big_root=order[0];
  double p,P;
  char file[20];
  int perc=0; //perc=0 if no spanning cluster exists, perc=1 else
 


  for (i=0; i<N; i++) ptr[i] = EMPTY;  //set every lattice site to state EMPTY

  for (i=0; i<N; i++) {
    r1 = s1 = order[i];                //new site
    ptr[s1] = -1;                      //set state to cluster of size 1
    for (j=0; j<NN; j++) {             //check whether s1 neighbors an occupied site s2
      s2 = nn[s1][j];
      if (ptr[s2]!=EMPTY) {
        r2 = findroot(s2);
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
      }
    
    }

     perc=spanning(big_root);
      if (perc)
	{
	  double p;
	  p=(double)i/N;
	  pc+=p;	  
	  sigmasq+=p*p;
	  break;
	  
	}
    
  }
}

#include "lattice.c++"    //include lattice dependent code

