#define L 512      /* Linear dimension */
#define N (L*L)
#define EMPTY (-N-1)
#define NN 8        //# of neighbors


inline double chi(double p);
double examine_cluster(int root);
void boundaries(void);
double examine_total(void);
void decorate(int face);
