//Gitter 17

#define L (640)    /* Linear dimension Teilbar durch 5 und 4  */
#define N (L*L)  
#define EMPTY (-N-1)
#define NN 4        //max # of neighbors


void boundaries(void);
int spanning(int root);
