//kagome lattice

#define L 480      /* Linear dimension */
#define N (L*L*3/4)
#define EMPTY (-N-1)
#define NN 10        //# of neighbors


inline double chi(double p);
double examine_cluster(int root);
void boundaries(void);
double examine_total(void);
void decorate(int face);

