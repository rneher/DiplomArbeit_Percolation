#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "rnglong.h"

#define P_C 0.697043
#define L 2048      /* Linear dimension */
#define N (L*L)
#define EMPTY (-N-1)
#define NNB 3        //# of neighbors black
#define NNW 12        //# of neighbors white
#define RUNS 50


int ptr_black[N];          /* Array of pointers */
int nn_black[N][NNB];        /* Nearest neighbors */
int order[N];        /* Occupation order */

int ptr_white[N];          /* Array of pointers */
int nn_white[N][NNW];        /* Nearest neighbors */
int stat_black[N];
int stat_white[N];

int findroot_black(int i);
int findroot_white(int i);

void lattice(void);
void cluster(int root);
int percolate(void);
void permutation(void);
double weigh_boundary(int root,int n);
double total_boundary(int n);
int spanning_black(int root);
int spanning_white(int root);
void stat(void);
void boundaries_white(void);            
void boundaries_black(void);            


using namespace std;

void main(void)
{
  int n=0,i,n0,big;
  double p,q,nb,nw,A;

  rngseed(0);
  boundaries_black();
  boundaries_white();

  for(i=0;i<N;i++) {stat_black[i]=0;stat_white[i]=0;}

  for (n=0;n<RUNS;n++){
    permutation();
    big=percolate();
    stat();
  }

  for (n0=1;n0<=L/5;n0++)
  {
    p=0;q=0;
    nb=0;nw=0;
    for(i=0;i<N;i++) 
      {
	if (i<n0)
	  {
	    //p+=i*stat_white[i];q+=i*stat_black[i];
	  }else{
	    p+=i*stat_black[i];q+=i*stat_white[i];
	    nb+=stat_black[i];nw+=stat_white[i];
	  }
      }
    cout <<n0<<"   "<<(double)(p-q)/N/RUNS<<"   "<<(double)(nb-nw)/N/RUNS<<"   "<<(double)n0*(nb-nw)/(p-q)<<"\n";
  }
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
int findroot_black(int i)
{
  if (ptr_black[i]<0) return i;
  return ptr_black[i] = findroot_black(ptr_black[i]);         //beware, recursive function
}

//return vertex number of the vertex, that serves as label of cluster containing i
int findroot_white(int i)
{
  if (ptr_white[i]<0) return i;
  return ptr_white[i] = findroot_white(ptr_white[i]);         //beware, recursive function
}


//print out lattice
void lattice(void)
{
  int n,m;
  cout << "------------------------------------------------------------------------------------------------------------\n";
  for (n=0; n<L; n++)    
  {
    for(m=0; m<L; m++)
    {
      if (ptr_black[n*L+m]==EMPTY) {cout <<" ";}
      else {cout << "X";}
    }
    cout << "\n";
  }
  cout << "------------------------------------------------------------------------------------------------------------\n";

  cout << "\n \n \n";

}


//print out cluster root
void cluster(int root)
{
  int n,m;
  cout << "------------------------------------------------------------------------------------------------------------\n";
  for (n=0; n<L; n++)    
  {
    //    cout << n << "  ";
    for(m=0; m<L; m++)
    {
      if (findroot_black(n*L+m)==root) {cout <<"X";}
      else {cout << " ";}
    }
    cout << "\n";
  }
  cout << "------------------------------------------------------------------------------------------------------------\n";

  cout << "\n \n \n";
}


//calculate the mass of cluster boundary
double weigh_boundary(int root,int n)
{
  int i,j,q;
  double mass=0;
  for(i=0;i<N;i++)
      if ((ptr_black[i]==EMPTY)&&(-ptr_white[findroot_white(i)]>n))
      {
	q=0;
	j=0;
	 do
	   {
	     if (findroot_black(nn_black[i][j])==root) q++;
	     j++;
	   }
	 while((!q)&&(j<NNB));  //loop until neighborhood of cluster is confirmed or all neighbors checked 
	 if (q) mass++;        //increment mass
      }

  return mass;
}


//calculate the mass of total boundary
double total_boundary(int n)
{
  int i,j,q;
  double mass=0,length=0;
  for(i=0;i<N;i++)
      if ((ptr_black[i]==EMPTY)&&(-ptr_white[findroot_white(i)]>n))
      {
	q=0;
	j=0;
	 do
	   {
	     if ((ptr_white[nn_black[i][j]]==EMPTY)&&(-ptr_black[findroot_black(nn_black[i][j])]>n)) length++;q++;
	     j++;
	   }
	 while(j<NNB);  //loop until neighborhood of cluster is confirmed or all neighbors checked 
	 if (q) mass++;        //increment mass
      }

  return mass;
}

int spanning_black(int root)
{
  int i,temp=0;
  for(i=0;i<L;i++) if (findroot_black(i)==root) temp++;
  if (temp) {temp=0;}
  else {return 0;}
  for(i=L*(L/2);i<L*(L/2)+L;i++) if (findroot_black(i)==root) temp++;
  if (temp) {return 1;}
  else {return 0;}
}


//generate percolation pattern, by ZiffNewman
int percolate(void)
{
  int i,j;
  int s1,s2;
  int r1,r2;
  int big_size=0,big_root=order[0];

  for (i=0; i<N; i++) ptr_black[i] = EMPTY;  //set every lattice site to state EMPTY

  for (i=0; i<(double)N*P_C; i++) {
    r1 = s1 = order[i];                //new site
    ptr_black[s1] = -1;                      //set state to cluster of size 1
    for (j=0; j<NNB; j++) {             //check whether s1 neighbors an occupied site s2
      s2 = nn_black[s1][j];
      if (ptr_black[s2]!=EMPTY) {
        r2 = findroot_black(s2);
        if (r2!=r1) {
          if (ptr_black[r1]>ptr_black[r2]) {       //merge clusters in unique way
            ptr_black[r2] += ptr_black[r1]; 
            ptr_black[r1] = r2;
            r1 = r2;
          } else {
            ptr_black[r1] += ptr_black[r2];
            ptr_black[r2] = r1;
          }
	  if (-ptr_black[r1]>big_size) {big_size = -ptr_black[r1]; big_root=r1; }
        }
      }
    
    }
  }
  
  for (i=0; i<N; i++) ptr_white[i] = EMPTY;  //set every lattice site to state EMPTY

  for (i=N-1; i>(double)N*P_C; i--) {
    r1 = s1 = order[i];                //new site
    ptr_white[s1] = -1;                      //set state to cluster of size 1
    for (j=0; j<NNW; j++) {             //check whether s1 neighbors an occupied site s2
      s2 = nn_white[s1][j];
      if (ptr_white[s2]!=EMPTY) {
        r2 = findroot_white(s2);
        if (r2!=r1) {
          if (ptr_white[r1]>ptr_white[r2]) {       //merge clusters in unique way
            ptr_white[r2] += ptr_white[r1]; 
            ptr_white[r1] = r2;
            r1 = r2;
          } else {
            ptr_white[r1] += ptr_white[r2];
            ptr_white[r2] = r1;
          }
        }
      }
    
    }

  }
  return big_root;
}
  

//set adjacencies and boundary conditions
void boundaries_white(void)            
{
  int i,face;

  for (i=0; i<N; i++) 
    {         //hex lattice, 12 neighbors
    if ((i/L)%2) { // odd column index
      if (i%2){    //odd row
        nn_white[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_white[i][4] = (i+L)%(N);
        nn_white[i][8] = (i-1+N)%(N);
      	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn_white[i][0] = (i-L+1+N)%(N);}
      }else{
        nn_white[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_white[i][4] = (i-1+N)%(N);
        nn_white[i][8] = (i-L+N)%(N);
        if (i%L==0) {nn_white[i][4] = (i+L-1)%(N);}        //correct boundary at start and end of each row
      }
    }
    else{
        if (i%2){    //odd row
        nn_white[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_white[i][4] = (i-1+N)%(N);
        nn_white[i][8] = (i+N-L)%(N);
	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn_white[i][0] = (i-L+1+N)%(N);}
      }else{
        nn_white[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_white[i][4] = (i+L)%(N);
        nn_white[i][8] = (i-1+N)%(N);
        if (i%L==0) {nn_white[i][8] = (i+L-1)%(N);}        //correct boundary at start and end of each row
      }
    }
    }
    
  for (i=0; i<N/2; i++)          //square lattice, 8 neighbors
      {
	  face=2*i+(2*i/L)%2;
	  nn_white[face][1] = nn_white[nn_white[face][0]][0];nn_white[nn_white[nn_white[face][0]][0]][7] = face;
	  nn_white[face][2] = nn_white[nn_white[face][1]][4];nn_white[nn_white[nn_white[face][1]][4]][6] = face;
	  nn_white[face][3] = nn_white[nn_white[face][4]][0];nn_white[nn_white[face][3]][9] = face;
	  nn_white[nn_white[face][0]][1] = nn_white[face][2];nn_white[nn_white[face][2]][7]=nn_white[face][0];
	  nn_white[nn_white[face][0]][2] = nn_white[face][3];nn_white[nn_white[face][3]][10]=nn_white[face][0];
	  nn_white[nn_white[face][0]][3]= nn_white[face][4];nn_white[nn_white[face][4]][9]=nn_white[face][0];
	  nn_white[nn_white[face][1]][5] = nn_white[face][3];nn_white[nn_white[face][3]][11] = nn_white[face][1];
	  nn_white[nn_white[face][1]][6] = nn_white[face][4];nn_white[nn_white[face][4]][10] = nn_white[face][1];
	  nn_white[nn_white[face][4]][11] = nn_white[face][2];nn_white[nn_white[face][2]][5] = nn_white[face][4];
      
    }
}

//set adjacencies and boundary conditions
void boundaries_black(void)            
{
  int i;

  for (i=0; i<N; i++) 
    {         //hex lattice, 3 neighbors
    if ((i/L)%2) { // odd column index
      if (i%2){    //odd row
        nn_black[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_black[i][1] = (i+L)%(N);
        nn_black[i][2] = (i-1+N)%(N);
       	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn_black[i][0] = (i-L+1+N)%(N);}
      }else{
        nn_black[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_black[i][1] = (i-1+N)%(N);
        nn_black[i][2] = (i-L+N)%(N);
        if (i%L==0) {nn_black[i][1] = (i+L-1)%(N);}        //correct boundary at start and end of each row
      }
    }
    else{
        if (i%2){    //odd row
        nn_black[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_black[i][1] = (i-1+N)%(N);
        nn_black[i][2] = (i+N-L)%(N);
	//correct boundary at start and end of each row
        if ((i+1)%L==0) {nn_black[i][0] = (i-L+1+N)%(N);}
      }else{
        nn_black[i][0] = (i+1)%(N);         //periodic boundary conditions
        nn_black[i][1] = (i+L)%(N);
        nn_black[i][2] = (i-1+N)%(N);
	if (i%L==0) {nn_black[i][2] = (i+L-1)%(N);}        //correct boundary at start and end of each ro
      }
    }
    }
}

void stat(void)
{
  int i;
  

  for(i=0;i<N;i++) 
    {
      if ((ptr_black[i]<0)&&(ptr_black[i]!=EMPTY))
	{
	  stat_black[-ptr_black[i]]++;
	}  
      if ((ptr_white[i]<0)&&(ptr_white[i]!=EMPTY))
	{
	  stat_white[-ptr_white[i]]++;
	}  
    }
}
