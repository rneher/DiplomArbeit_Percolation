//lattice dependent code
//2 uniform lattice 16 

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,j,row,column;
  
  for (i=0; i<N; i++) {         
    column=i%((L*8)/5);               //number of sites exeeding an integer multiple of 5 row layer
    row=(i-column)*25/(L*8);          //number of 5 row layers*5
    if (column>=L/5) {row++; column-=L/5;}     //calculate row and column number of site i
    if (column>=2*L/5) {row++; column-=2*L/5;
    if (column>=2*L/5) {row++; column-=2*L/5;
    if (column>=2*L/5) {row++; column-=2*L/5;}}}

    if ((row%5)==0) {
	nn[i][0]=(i+1+L/5+column)%N;
	nn[i][1]=(i+L/5+column)%N;
	nn[i][2]=(i-L/5+N)%N;
	nn[i][3]=i;
	if (row==0) nn[i][2]=i;      //boundary condition
    }
    if ((row%5)==1) {
      if (column%2){
	nn[i][0]=(i+2*L/5)%N;
	nn[i][1]=(i+4*L/5)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-column-L/5+(column-1)/2+N)%N;
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+4*L/5)%N;
	nn[i][2]=(i+2*L/5)%N;
	nn[i][3]=(i-column-L/5+column/2+N)%N;
      }
    }
    if ((row%5)==2) {
      if (column%2){
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+2*L/5)%N;
	nn[i][2]=(i-2*L/5+N)%N;
	nn[i][3]=i;
	if (column==2*L/5-1) nn[i][0]=i;   // boundary condtion row length 2/5*L
      }else{
	nn[i][0]=(i+2*L/5)%N;
	nn[i][1]=(i-1+N)%N;
	nn[i][2]=(i-2*L/5+N)%N;
	nn[i][3]=i;
	if (column==0) nn[i][1]=i;     //boundary condition
      }      
    }
    if ((row%5)==3) {
      if (column%2){
	nn[i][3]=(i-2*L/5+N)%N;
	nn[i][2]=(i-4*L/5+N)%N;
	nn[i][1]=(i-1+N)%N;
	nn[i][0]=(i-column+2*L/5+(column-1)/2)%N;
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i-column+2*L/5+column/2)%N;
	nn[i][2]=(i-2*L/5+N)%N;
	nn[i][3]=(i-4*L/5+N)%N;
      }
    }
    if ((row%5)==4) {
	nn[i][0]=(i+L/5)%N;
	nn[i][1]=(i-column-2*L/5+2*column)%N;
	nn[i][2]=(i-column-2*L/5+2*column+1)%N;
	nn[i][3]=i;
	if (row==L-1) nn[i][0]=i;  //boundary condition
    }
  }


  /*
  for(i=0; i<L/5;i++) {//cut bonds pointing upwards in first row 
    nn[i][2]=i;
  }
  for (i=0;i<L;i+=5)//cut right and left bound bonds in last and first column
    {
      nn[3*L/5+(i*L*8)/25][1]=3*L/5+(i*L*8)/25;
      nn[L+(i*L*8)/25-1][0]=L+(i*L*8)/25-1;
    }
  for(i=N-L/5; i<N;i++) {//cut bonds pointing downwards in last row 
     nn[i][0]=i; 
     
     } */
}
 
int spanning(int root)
{
  int i,temp=0;
  for(i=0;i<L/5;i++) if (findroot(i)==root) temp++;
  if (temp) {
    temp=0; 
    for(i=N-L/5;i<N;i++) if (findroot(i)==root) temp++;
    if (temp) {temp=0;return 1;}
  }
  for(i=0;i<L;i+=5) if (findroot(3*L/5+(i*L*8)/25)==root) temp++;
  if (temp) {temp=0;}
  else {return 0;}
  for(i=0;i<L;i+=5) if (findroot(L+(i*L*8)/25-1)==root) temp++;
  if (temp) {return 1;}
  else {return 0;}
}
