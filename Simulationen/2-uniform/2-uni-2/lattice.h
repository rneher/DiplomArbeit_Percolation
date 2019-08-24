//Gitter 2

#define L (768)    /* Linear dimension Teilbar durch 6 */
#define N (L*L*8/9)  
#define EMPTY (-N-1)
#define NN 6        //max # of neighbors


void boundaries(void);
int spanning(int root);
