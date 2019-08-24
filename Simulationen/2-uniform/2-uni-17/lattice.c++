//lattice dependent code
//lattice 17

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%L;      //determine row and column number
    row=(i-column)/L; //  
   
    if (row%4==0) {
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+N)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1)%N;
	  if (column==0) nn[i][2]=i;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}
    }
    //----------------------row 2---------------------

    if (row%4==1) {
      if (column%5==0)
	{
	  nn[i][0]=(i+L)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-L+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (column==0) nn[i][1]=i;
	}
      if (column%5==1)
	{
	  nn[i][0]=i;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-L+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}
    }
    //----------------------row 3---------------------

    if (row%4==2) {
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  if (column==0) nn[i][2]=i;
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+L)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	}
      if (column%5==3)
	{
	  nn[i][0]=i;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}
    }
    //------------------row 4-----------
    if (row%4==3) {
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-L+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (column==0) nn[i][1]=i;
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L+N)%N;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  if (column==L-1) nn[i][0]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
    }
   }   
  /* int j;
  for (i=0; i<N; i++) {         
    column=i%L;      //determine row and column number
    row=(i-column)/L; //  
    if (column==0) cout << "\n";
    cout <<i<<": ";
    for (j=0;j<NN;j++) cout << nn[i][j]<<"  ";
    cout <<"\n";
    }*/
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
  for (i=0;i<N;i+=L)  if (findroot(i)==root) temp++;
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=L)   if (findroot(i+L-1)==root) temp++;
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
