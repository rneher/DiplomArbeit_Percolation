#define L 1024       /* Linear dimension */
#define N (L*L)
#define EMPTY (-N-1)
#define NN 6        //# of neighbors


inline double chi(double p);
double examine_cluster(int root);
void boundaries(void);
double examine_total(void);
