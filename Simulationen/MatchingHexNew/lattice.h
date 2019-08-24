#define L 512      /* Linear dimension */
#define N (L*L)
#define EMPTY (-N-1)
#define NN 12        //# of neighbors


inline double chi(double p);
double examine_cluster(int root);
void boundaries(void);
void decorate(int face);
double examine_total(void);
