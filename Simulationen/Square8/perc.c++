#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "rnglong.h"
#include "lattice.h"

int ptr[N];          /* Array of pointers */
int nn[N][NN];        /* Nearest neighbors */
int order[N];        /* Occupation order */


int findroot(int i);
void lattice(void);
void cluster(int root);
void percolate(void);
void permutation(void);
double weigh_boundary(int root);
double total_boundary(void);
int spanning(int root);

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


//print out lattice
void lattice(void)
{
  int n,m;
  cout << "------------------------------------------------------------------------------------------------------------\n";
  for (n=0; n<L; n++)    
  {
    for(m=0; m<L; m++)
    {
      if (ptr[n*L+m]==EMPTY) {cout <<" ";}
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
      if (findroot(n*L+m)==root) {cout <<"X";}
      else {cout << " ";}
    }
    cout << "\n";
  }
  cout << "------------------------------------------------------------------------------------------------------------\n";

  cout << "\n \n \n";
}


//calculate the mass of cluster boundary
double weigh_boundary(int root)
{
  int i,j,q;
  double mass=0;
  for(i=0;i<N;i++)
      if (ptr[i]==EMPTY)
      {
	q=0;
	j=0;
	 do
	   {
	     if (findroot(nn[i][j])==root) q++;
	     j++;
	   }
	 while((!q)&&(j<NN));  //loop until neighborhood of cluster is confirmed or all neighbors checked 
	 if (q) mass++;        //increment mass
      }

  return mass;
}


//calculate the mass of total boundary
double total_boundary(void)
{
  int i,j,q;
  double mass=0;
  for(i=0;i<N;i++)
      if (ptr[i]==EMPTY)
      {
	q=0;
	j=0;
	 do
	   {
	     if (ptr[nn[i][j]]!=EMPTY) q++;
	     j++;
	   }
	 while((!q)&&(j<NN));  //loop until neighborhood of cluster is confirmed or all neighbors checked 
	 if (q) mass++;        //increment mass
      }

  return mass;
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
  int i,j;
  int s1,s2;
  int r1,r2;
  int big_size=0,big_root=order[0];
  double p,P_inf,boundarymass,p0,p1;
  char file[20];
  int perc=0; //perc=0 if no spanning cluster exists, perc=1 else
 
  int step,qP_inf, qChi_inf,qChi_fin, qPchi,qChi,qBound_inf, qBound,qHead,qpq;
  /*  cout <<"Start: ";
  cin >> p0; 
  cout <<"Stop: ";
  cin >> p1; 
  
  cout <<"Number of data points (1.." << N*(p1-p0) << "):";
  cin >> step; 
  step=N*(p1-p0)/step;
  */
  p0=0.38;p1=0.5;step=N*(p1-p0)/200;
  /*  cout << "Output of P_inf (0/1)? ";
  cin >>qP_inf;

  cout << "Output of Chi_inf /N (0/1)? ";
  cin >>qChi_inf;

  cout << "Output of Chi_fin /N (0/1)? ";
  cin >>qChi_fin;  

  cout << "Output of P_inf*Chi (0/1)? ";
  cin >>qPchi;

  cout << "Output of Chi (0/1)? ";
  cin >>qChi;

  cout << "Output of boundary mass of infinite cluster (0/1)? ";
  cin >>qBound_inf;

  cout << "Output of total boundary mass  (0/1)? ";
  cin >>qBound;

  cout << "Output of (1-p)/p (0/1)? ";
  cin >>qpq;

  cout << "Print headline (0/1)? "; 
  cin >> qHead;

  cout <<"Output into file: ";
  cin >> file;

  ofstream out(file);
  
  if (qHead)
  {
    //cout <<"Square lattice with nearest and next nearest neighbors, linear dimension "<<L<<", "<<N<<" sites.\n"; 
    out << "p       ";
    if (qP_inf) out << "P_inf    ";
    if (qChi_inf) out << "Chi_inf    ";
    if (qChi_fin) out << "Chi_fin    ";
    if (qPchi) out << "P_inf*Chi    ";
    if (qChi) out << "Chi    ";
    if (qBound_inf) out << "Boundary of inf. Cluster/size_inf_cluster    ";
    if (qBound) out << "total boundary/occupied sites   ";
    if (qpq) out << "(1-p)/p";
    out << "\n";
  }
  */

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

    if ((i+1)%step) {}                   //perform cluster analysis every step new sites
    else if ((i>p0*N)&&(i<p1*N))   //in range p=p0..p1
    { 
      if (!perc) perc=spanning(big_root);
      if (perc){
	p= (double)i/N;
	cout <<p<<"  ";
	examine_cluster(big_root,p);
      }
      /*            out << p<< "   ";
            if (qP_inf) {P_inf=perc*(double)big_size/i; out <<P_inf<< "    ";}    //P_inf= size of infinite cluster/ no of occupied sites
            if (qChi_inf) out << perc*examine_cluster(big_root)/N <<"    ";       //Euler charactersitic of biggest cluster
            if (qChi_fin) out << (examine_total()-perc*examine_cluster(big_root))/N <<"    ";        //Euler characteristic of finite clusters
            if (qPchi) out << P_inf*chi(p)<<"    ";                          //mean euler characteristic, multiplied by P_inf
            if (qChi) out << examine_total()/N<<"    ";                                 //euler characteristic
            if (qBound_inf)  if (big_size) out << weigh_boundary(big_root)/big_size <<"    ";//ratio boundary/mass of biggest cluster
                      else out << 0<<"    ";
            if (qBound) out << total_boundary()/i<<"  ";                     //ratio boundary sites/occupied sites
            if (qpq) out << (1-p)/p<<"   ";
            out << "\n";
      */
    }
  }
}

#include "lattice.c++"    //include lattice dependent code

