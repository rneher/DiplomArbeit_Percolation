#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "rnglong.h"
#include <cmath>
#include "lattice.h"
#define RUNS (60*60*2048*2/L/L)

int ptr[N];          /* Array of pointers */
int nn[N][NN];        /* Nearest neighbors */
int order[N];        /* Occupation order */
int order_faces[N/6];
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
  int decorated=0,step=N/6/200,face, row,i;
  double fraction=0;
  rngseed(0);
  permutation_faces();
  boundaries();

  // kleine Gitter   
  for(fraction=0;fraction<=1;fraction+=0.01)
    {
      boundaries();
      for(decorated=0;decorated<N/6*fraction;decorated++)
	{
	  row=(order_faces[decorated]*4-(order_faces[decorated]*4)%L)/L;
	  face=3*L/2*row+(4*order_faces[decorated]-L*row)+1+2*(row%2);
	  decorate(face);
	}
      pc=0;sigmasq=0;
      for(i=0;i<RUNS;i++)
	{
	  permutation();
	  percolate();
	}
      cout <<RUNS<<"  "<<L<<"  "<<pow(L,-0.75)<<"   "<<fraction<<"   "<<pc/RUNS<<"   "<<sqrt((sigmasq/(RUNS-1)-pc*pc/RUNS/RUNS)/(RUNS))<<"\n";
    }

  //grosse Gitter
  /*  for(decorated=0;decorated<N/6;decorated++)
    {
      if (!(decorated%(N/600)))
	{
	  pc=0;sigmasq=0;
	  for(i=0;i<RUNS;i++)\
	    {
	      permutation();
	      percolate();
	    }
	
      cout <<RUNS<<"  "<<L<<"  "<<pow(L,-0.75)<<"   "<<(double)(decorated)/((N/6))<<"   "<<pc/RUNS<<"   "<<sqrt((sigmasq/(RUNS-1)-pc*pc/RUNS/RUNS)/(RUNS))<<"\n";
	}
      row=(order_faces[decorated]*4-(order_faces[decorated]*4)%L)/L;
      face=3*L/2*row+(4*order_faces[decorated]-L*row)+1+2*(row%2);
      decorate(face);
    }
  pc=0;sigmasq=0;
  for(i=0;i<RUNS;i++)
    {
      permutation();
      percolate();
    }
	
  cout <<RUNS<<"  "<<L<<"  "<<pow(L,-0.75)<<"   "<<(double)(decorated)/((N/6))<<"   "<<pc/RUNS<<"   "<<sqrt((sigmasq/(RUNS-1)-pc*pc/RUNS/RUNS)/(RUNS))<<"\n";
  */
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

  for (i=0; i<N/6; i++) order_faces[i] = i;
  for (i=0; i<N/6; i++) {
    j = i + (N/6-i)*RNGLONG;
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
  for(i=0;i<L;i++) 
    {
      if (findroot(i)==root) temp++; 
    }
  if (temp) 
    {
      temp=0;
      for(i=N-3*L/2;i<N-L/2;i++) if (findroot(i)==root) temp++;
      if (temp) {return 1;}
    }
  for(i=0;i<N;i+=3*L/2) if (findroot(i)==root) temp++;
    {
      if (findroot(i)==root) temp++; 
      if (findroot(i+L)==root) temp++; 
      if (findroot(i+5*L/4)==root) temp++;
    }
  if (temp) 
    {
      temp=0;
      for(i=0;i<N;i+=3*L/2) 
	{
	  if (findroot(i+L-1)==root) temp++; 
	  if (findroot(i+5*L/4-1)==root) temp++; 
	  if (findroot(i+3*L/2-1)==root) temp++;
	}
      if (temp) {return 1;}
    }
  return 0;

}


//generate percolation pattern, by ZiffNewman
void percolate(void)
{
  int i,j;
  int s1,s2;
  int r1,r2;
  int big_size=0,big_root=order[0];
  double p,P;
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

