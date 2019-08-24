//Gitter 11

#define L (6*32)    /* Linear dimension Teilbar durch 6 und 4  */
#define N (L*L)  
#define EMPTY (-N-1)
#define NN 5        //max # of neighbors


void boundaries(void);
int spanning(int root);
