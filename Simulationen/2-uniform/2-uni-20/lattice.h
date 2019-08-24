//Gitter 20

#define L (768)    /* Linear dimension Teilbar durch 6  und 4*/
#define N (L*L*3/4)  
#define EMPTY (-N-1)
#define NN 4        //max # of neighbors


void boundaries(void);
int spanning(int root);
