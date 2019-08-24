//Gitter 19

#define L (1024)    /* Linear dimension Teilbar durch 4  */
#define N (L*L*5/8)  
#define EMPTY (-N-1)
#define NN 4        //max # of neighbors


void boundaries(void);
int spanning(int root);
