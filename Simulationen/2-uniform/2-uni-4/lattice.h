//Gitter 4

#define L (3*64)    /* Linear dimension Teilbar durch 3  */
#define N (L*L)  
#define EMPTY (-N-1)
#define NN 6        //max # of neighbors


void boundaries(void);
int spanning(int root);
