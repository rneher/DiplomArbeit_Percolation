//Gitter 5

#define L (960)    /* Linear dimension Teilbar durch 5 und 3 */
#define N (L*L*14/15)  
#define EMPTY (-N-1)
#define NN 6        //max # of neighbors


void boundaries(void);
int spanning(int root);
