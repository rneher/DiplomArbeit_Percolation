//Gitter 10

#define L (1024)    /* Linear dimension Teilbar durch 4 */
#define N (L*L)  
#define EMPTY (-N-1)
#define NN 5        //max # of neighbors


void boundaries(void);
int spanning(int root);
