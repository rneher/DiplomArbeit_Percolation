//lattice dependent code
//2-uniform lattice 4

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%L;        //determine row and column number
    row=(i-column)/L;

    if (row%8==0) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-L+N-1)%N;
	nn[i][4]=(i-L+N)%N;
	nn[i][5]=i;
	if (row==0) {nn[i][3]=i;nn[i][4]=i;}    //boundary condition in first row
	if (column==0) {nn[i][2]=i;nn[i][3]=i;}  //left boundary
	if (column==L-1) {nn[i][0]=i;}   //right boundary 
    }
    if (row%8==1) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i+L-1)%N;
	nn[i][3]=(i-1+N)%N;
	nn[i][4]=(i-L)%N;
	nn[i][5]=i%N;
        if (column==0) {nn[i][2]=i;nn[i][3]=i;}     //left boundary
        if (column==L-1) {nn[i][0]=i;}   //right boundary
    }
    if (row%8==2) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i+L-1)%N;
	nn[i][3]=(i-1+N)%N;
 	nn[i][4]=(i-L-1+N)%N;
	nn[i][5]=(i-L+N)%N;         
        if (column==0) {nn[i][2]=i; nn[i][3]=i;nn[i][4]=i;}  //left boundary
        if (column==L-1) {nn[i][0]=i;}  //right boundary
    }
    if (row%8==3) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L+1)%N;
	nn[i][2]=(i+L)%N;
	nn[i][3]=(i-1+N)%N;
 	nn[i][4]=(i-L+N)%N;
	nn[i][5]=(i-L+1+N)%N;         
        if (column==0) {nn[i][3]=i;}  //left boundary
        if (column==L-1) {nn[i][0]=i;nn[i][5]=i;nn[i][1]=i;}  //right boundary
    }
    if (row%8==4) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-L+N-1)%N;
	nn[i][4]=(i-L+N)%N;
	nn[i][5]=i;
	if (column==0) {nn[i][2]=i;nn[i][3]=i;}  //left boundary
	if (column==L-1) {nn[i][0]=i;}   //right boundary 
    }
    if (row%8==5) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i+L-1)%N;
	nn[i][3]=(i-1+N)%N;
	nn[i][4]=(i-L)%N;
	nn[i][5]=i%N;
        if (column==0) {nn[i][2]=i;nn[i][3]=i;}     //left boundary
        if (column==L-1) {nn[i][0]=i;}   //right boundary
    }
    if (row%8==6) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L+1)%N;
	nn[i][2]=(i+L)%N;
	nn[i][3]=(i-1+N)%N;
 	nn[i][4]=(i-L+N)%N;
	nn[i][5]=(i-L+1+N)%N;         
        if (column==0) {nn[i][3]=i;}  //left boundary
        if (column==L-1) {nn[i][0]=i;nn[i][5]=i;nn[i][1]=i;}  //right boundary
    }
    if (row%8==7) {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i+L-1)%N;
	nn[i][3]=(i-1+N)%N;
 	nn[i][4]=(i-L+N-1)%N;
	nn[i][5]=(i-L+N)%N;         
        if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}  //last row 
        if (column==0) {nn[i][2]=i;nn[i][3]=i;nn[i][4]=i;}  //left boundary
        if (column==L-1) {nn[i][0]=i;}  //right boundary
    }
  }

  /*
  
  for(i=0; i<L;i++) {//cut bonds pointing upwards in first row 
    nn[i][3]=i; nn[i][4]=i;
  }
  for (i=0;i<L;i++)//cut right and left bound bonds in last and first column
    {
      nn[i*L+L-1][0]=i*L+L-1;
      nn[i*L][3]=i*L;
      if ((i%3)==2) {nn[i*L+L-1][1]=i*L+L-1;nn[i*L+L-1][5]=i*L+L-1;}
      else nn[i*L][2]=i*L;
    }
  for(i=N-L; i<N;i++) {//cut bonds pointing downwards in last row 
     nn[i][1]=i; nn[i][2]=i;
     
     } */
}
 
int spanning(int root)
{
  int i,temp=0;
  for(i=0;i<L;i++) if (findroot(i)==root) temp++;
  if (temp) {
    temp=0;
    for(i=N-1;i>N-1-L;i--) if (findroot(i)==root) temp++;
    if (temp) {return 1;}
  }
  for (i=0;i<L;i++)  if (findroot(i*L)==root) temp++;
  if (temp)
    { 
      temp=0;
      for (i=0;i<L;i++)  if (findroot(i*L+L-1)==root) temp++;
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
