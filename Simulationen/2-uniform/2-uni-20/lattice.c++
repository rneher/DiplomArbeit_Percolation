//lattice dependent code
//lattice 6

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%(3*L);      //determine row and column number
    row=4*(i-column)/(3*L); //3*L is the length of 4 rows of differetn length  
    if (column>=L) 
      {
	row++; column-=L;        //next row
	if (column>=L/2) 
	  {
	    row++; column-=L/2;    //next row
	    if (column>=L/2) {row++;  column-=L/2;}  //next row
	  }
      }
   
    if (row%4==0) {
      if (column%6==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+column/2)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (column==0) nn[i][2]=i;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%6==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+(column-1)/2)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%6==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+(column-2)/2+1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=i;
	}
      if (column%6==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-L+1+N)%N;
	  nn[i][3]=i;
	  if (row==0) {nn[i][2]=i;}
	}
      if (column%6==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-L+1+N)%N;
	  nn[i][3]=i;
	  if (row==0) {nn[i][2]=i;}
	}
      if (column%6==5)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+(column-5)/2+2)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=i;
	  if (column==L-1) nn[i][0]=i;
	}
    }

    //----------------------row 2----------------------------
    if (row%4==1) {
      if (column%3==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-column-L+2*column+N)%N;
	  nn[i][3]=(i-column-L+2*column+1+N)%N;
	  if (column==0) nn[i][1]=i;
	}
      if (column%3==1)
	{
	  nn[i][0]=(i+L/2-1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-column-L+2*(column-1)+2)%N;
	  nn[i][3]=i;
	}
      if (column%3==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L/2-1)%N;
	  nn[i][2]=(i-column-L+2*(column-2)+5+N)%N;
	  nn[i][3]=i;
	  if (column==L/2-1) nn[i][0]=i;
	}
    }
    //----------------------row 3----------------------------
    if (row%4==2) {
      if (column%3==0)
	{
	  nn[i][0]=(i-column+L/2+2*column)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-L/2+1+N)%N;
	  nn[i][3]=i;
	  if (column==0) nn[i][1]=i;
	}
      if (column%3==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L/2+2*(column-1)+3+N)%N;
	  nn[i][2]=(i-L/2+1)%N;
	  nn[i][3]=i;
	}
      if (column%3==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L/2+2*(column-2)+4)%N;
	  nn[i][2]=(i-column+L/2+2*(column-2)+5)%N;
	  nn[i][3]=(i-1+N)%N;
	  if (column==L/2-1) nn[i][0]=i;
	}
    }
    //--------------- row 4
    if (row%4==3) {
      if (column%6==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-column-L/2+column/2+N)%N;
	  nn[i][3]=i;
	  if (column==0) nn[i][1]=i;
	}
      if (column%6==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%6==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%6==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-column-L/2+(column-3)/2+1)%N;
	  nn[i][3]=i;
	}
      if (column%6==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1+N)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-L/2+(column-4)/2+2+N)%N;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%6==5)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-column-L/2+(column-5)/2+2+N)%N;
	  if (column==L-1) nn[i][0]=i;
	  if (row==L-1) nn[i][1]=i;
	}
    }
  }   
  /*  int j;
  for (i=0; i<N; i++) {         
    column=i%(3*L);      //determine row and column number
    row=4*(i-column)/(3*L); //3*L is the length of 4 rows of differetn length  
    if (column>=L) 
      {
	row++; column-=L;        //next row
	if (column>=L/2) 
	  {
	    row++; column-=L/2;    //next row
	    if (column>=L/2) {row++;  column-=L/2;}  //next row
	  }
      }
    if (column==0) cout <<"\n";
    cout <<i<<": ";
    for (j=0;j<NN;j++) cout << nn[i][j]<< "   ";
    cout <<"\n";
  }
  */
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
  for (i=0;i<N;i+=3*L)  
    {
      if (findroot(i)==root) temp++;
      if (findroot(i+L)==root) temp++;
      if (findroot(i+3*L/2)==root) temp++;
      if (findroot(i+2*L)==root) temp++;
    }
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=3*L)   
	{
	  if (findroot(i+L-1)==root) temp++;
	  if (findroot(i+3*L/2-1)==root) temp++;
	  if (findroot(i+2*L-1)==root) temp++;
	  if (findroot(i+3*L-1)==root) temp++;}
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
