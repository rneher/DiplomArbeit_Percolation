//Gitter 16

#define L (5*8)    /* Linear dimension Teilbar durch 3  */
#define N (L*L*8/25)  
#define EMPTY (-N-1)
#define NN 4        //max # of neighbors


void boundaries(void);
int spanning(int root);
