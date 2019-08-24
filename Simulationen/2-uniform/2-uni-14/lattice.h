//Gitter 14

#define L (480)  /* Linear dimension Teilbar durch 10 und 4  */
#define N (L*L*3/5)  
#define EMPTY (-N-1)
#define NN 5        //max # of neighbors


void boundaries(void);
int spanning(int root);
