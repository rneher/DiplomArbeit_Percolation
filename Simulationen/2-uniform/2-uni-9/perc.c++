#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "rnglong.h"
#include "lattice.h"

#define RUNS (50*50*1024*64/L/L) //# of simulations

int ptr[N];          /* Array of pointers */
int nn[N][NN];        /* Nearest neighbors */
int order[N];        /* Occupation order */
double pc=0,sigmapc=0;

int findroot(int i);
void percolate(void);
void permutation(void);

using namespace std;

void main(void)
{
  int i;
  rngseed(0);
  boundaries();
  for(i=1;i<=RUNS;i++){
    permutation();
    percolate();
    cout << i<<"   "<< L <<"   "<<pow(L,-0.75)<< "   " <<pc/i<<"  "<< sqrt((sigmapc/i-pc*pc/i/i)/i)<< "\n";
  }    
  cout << RUNS<<"   "<< L <<"   "<<pow(L,-0.75)<< "   " <<pc/RUNS<<"  "<< sqrt((sigmapc/RUNS-pc*pc/RUNS/RUNS)/RUNS)<< "\n";

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




//return vertex number of the vertex, that serves as label of cluster containing i
int findroot(int i)
{
  if (ptr[i]<0) return i;
  return ptr[i] = findroot(ptr[i]);         //beware, recursive function
}




//generate percolation pattern, by ZiffNewman
void percolate(void)
{
  int i,j;
  int s1,s2;
  int r1,r2;
  int big_size=0,big_root=order[0];
  double p;
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
    p= (double)i/N;
    if (p>0){
      perc=spanning(big_root);
      if (perc)  {pc+=p;sigmapc+=p*p; break;}
    }
  }
}

#include "lattice.c++"    //include lattice dependent code

