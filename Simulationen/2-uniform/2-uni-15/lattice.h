//Gitter 15

#define L (3*256)    /* Linear dimension Teilbar durch 3  */
#define N (L*L)  
#define EMPTY (-N-1)
#define NN 4        //max # of neighbors


void boundaries(void);
int spanning(int root);
