//Gitter 6

#define L (5*4*64)    /* Linear dimension Teilbar durch 5 und 4  */
#define N (L*L*14/4/5)  
#define EMPTY (-N-1)
#define NN 6        //max # of neighbors


void boundaries(void);
int spanning(int root);
