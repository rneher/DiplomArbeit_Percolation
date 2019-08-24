//lattice dependent code
//lattice 5

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%(14*L/5);      //determine row and column number
    row=3*(i-column)/(14*L/5);
    if (column>=L) 
      {
	row++; column-=L;
	if (column>=L) {row++; column-=L;}
      }

    //-------------------row 1 --------------------------   
    if (row%3==0) {
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-4*L/5+4*column/5+N)%N;
	  nn[i][5]=i;
	  if (column==0) {nn[i][3]=i;}
	  if (row==0) {nn[i][4]=i;}
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-4*L/5+4*(column-1)/5+1+N)%N;
	  nn[i][5]=i;
	  if (row==0) {nn[i][4]=i;}
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-4*L/5+4*(column-2)/5+1+N)%N;
	  nn[i][4]=(i-column-4*L/5+4*(column-2)/5+2+N)%N;
	  nn[i][5]=i;
	  if (row==0) {nn[i][3]=i;nn[i][4]=i;}
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L+N)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-4*L/5+4*(column-3)/5+2+N)%N;
	  nn[i][5]=(i-column-4*L/5+4*(column-3)/5+3+N)%N;
	  if (row==0) {nn[i][4]=i;nn[i][5]=i;}
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-4*L/5+4*(column-4)/5+3+N)%N;
	  nn[i][4]=(i-column-4*L/5+4*(column-4)/5+4+N)%N;
	  nn[i][5]=i;
	  if (row==0) {nn[i][3]=i;nn[i][4]=i;}
	  if (column==L-1) {nn[i][0]=i;nn[i][4]=i;}
	}
     }

    //------------------row 2---------------------
    if (row%3==1) {
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+4*column/5)%N;
	  nn[i][2]=(i-column+L+4*column/5-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=i;
	  if (column==0) {nn[i][2]=i;nn[i][3]=i;}
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+4*(column-1)/5+1)%N;
	  nn[i][2]=(i-column+L+4*(column-1)/5)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L-1+N)%N;
	  nn[i][5]=(i-L+N)%N;
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+4*(column-2)/5+2)%N;
	  nn[i][2]=(i-column+L+4*(column-2)/5+1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L-1+N)%N;
	  nn[i][5]=i;
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+4*(column-3)/5+2)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=i;
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+4*(column-3)/5+3)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=i;
	  if (column==L-1) {nn[i][0]=i;}
	}
     }
    //-------------------- row 3 -------------------
    if (row%3==2) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+4*L/5+5*column/4)%N;
	  nn[i][2]=(i-column+4*L/5+5*column/4-1)%N;
	  nn[i][3]=(i-column-L+5*column/4+N)%N;
	  nn[i][4]=(i-column-L+5*column/4+1+N)%N;
	  nn[i][5]=i;
	  if (column==0) {nn[i][2]=i;}
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%4==1)
	{
	  nn[i][0]=(i-column+4*L/5+5*(column-1)/4+2)%N;
	  nn[i][1]=(i-column+4*L/5+5*(column-1)/4+1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-L+5*(column-1)/4+1+N)%N;
	  nn[i][4]=(i-column-L+5*(column-1)/4+2+N)%N;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][0]=i;nn[i][1]=i;}
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+4*L/5+5*(column-2)/4+3)%N;
	  nn[i][2]=(i-column+4*L/5+5*(column-2)/4+2)%N;
	  nn[i][3]=(i-column-L+5*(column-2)/4+2+N)%N;
	  nn[i][4]=(i-column-L+5*(column-2)/4+3+N)%N;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%4==3)
	{
	  nn[i][0]=(i-column+4*L/5+5*(column-3)/4+4)%N;
	  nn[i][1]=(i-column+4*L/5+5*(column-3)/4+3)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-L+5*(column-3)/4+4+N)%N;
	  nn[i][4]=(i-column-L+5*(column-3)/4+5+N)%N;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][0]=i;nn[i][1]=i;}
	  if (column==4*L/5-1) {nn[i][4]=i;}
	}
     }
  }
  /*  int j;
  for (i=0; i<N; i++) {         
    column=i%(14*L/5);      //determine row and column number
    row=3*(i-column)/(14*L/5);
    if (column>=L) 
      {
	row++; column-=L;
	if (column>=L) {row++; column-=L;}
      }

    if (column==0) cout <<"\n";
    cout << i<<": ";
    for(j=0;j<NN;j++) cout <<nn[i][j]<<", ";
    cout <<"\n";
    }  */ 
} 

int spanning(int root)
{
  int i,temp=0;
  for(i=0;i<L;i++) if (findroot(i)==root) temp++;
  if (temp) {
    temp=0;
    for(i=N-1;i>N-1-4*L/5;i--) if (findroot(i)==root) temp++;
    if (temp) {return 1;}
  }
  for (i=0;i<N;i+=14*L/5)  
    {
      if (findroot(i)==root) temp++;
      if (findroot(i+L)==root) temp++;
      if (findroot(i+2*L)==root) temp++;
    }
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=14*L/5)   
	{
	  if (findroot(i+L-1)==root) temp++;
	  if (findroot(i+2*L-1)==root) temp++;
	  if (findroot(i+14*L/5-1)==root) temp++;
	}
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
