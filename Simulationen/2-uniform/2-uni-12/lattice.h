//Gitter 12

#define L (6*128)    /* Linear dimension Teilbar durch 6  */
#define N (L*L)  
#define EMPTY (-N-1)
#define NN 5        //max # of neighbors


void boundaries(void);
int spanning(int root);
