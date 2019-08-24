#define L 1024       /* Linear dimension */
#define N (L*L)
#define EMPTY (-N-1)
#define NN 8        //# of neighbors


inline double chi(double p);
double examine_cluster(int root,double p);
void boundaries(void);
double examine_total(void);
