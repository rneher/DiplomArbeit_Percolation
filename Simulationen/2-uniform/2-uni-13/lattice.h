//Gitter 13

#define L (8*128)    /* Linear dimension Teilbar durch 8  */
#define N (L*L)  
#define EMPTY (-N-1)
#define NN 5        //max # of neighbors


void boundaries(void);
int spanning(int root);
