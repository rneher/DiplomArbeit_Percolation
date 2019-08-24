//3_12^2 lattice   25.4.03


#define L 60     /* Linear dimension */
#define N (L*L/2)
#define EMPTY (-N-1)
#define NN 21        //# of neighbors


inline double chi(double p);
double examine_cluster(int root);
void boundaries(void);
double examine_total(void);
void decorate(int face);
