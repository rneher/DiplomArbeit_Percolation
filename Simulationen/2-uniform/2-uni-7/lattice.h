#define L (6*128)    /* Linear dimension Teilbar durch 6  */
#define N (L*L/9*7)  //correction due to nonuniform row length
#define EMPTY (-N-1)
#define NN 6        //max # of neighbors


void boundaries(void);
