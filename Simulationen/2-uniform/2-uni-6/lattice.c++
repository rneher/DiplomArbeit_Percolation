//lattice dependent code
//lattice 6

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%(14*L/5);      //determine row and column number
    row=4*(i-column)/(14*L/5); //14*L/5 is the length of 4 rows of differetn length  
    if (column>=L) 
      {
	row++; column-=L;        //next row
	if (column>=2*L/5) 
	  {
	    row++; column-=2*L/5;    //next row
	    if (column>=2*L/5) {row++;  column-=2*L/5;}  //next row
	  }
      }
   
    if (row%8==7) {
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==0) nn[i][3]=i;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-column-2*L/5+2*(column-2)/5)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=(i-column-2*L/5+2*(column-3)/5)%N;
	  nn[i][5]=(i-column-2*L/5+2*(column-3)/5+1)%N;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-column-2*L/5+2*(column-4)/5+1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==L-1) nn[i][0]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
    }

    //----------------------row 1----------------------------
    if (row%8==0) {
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*column/5)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==0) nn[i][2]=i;
	  if (row==0) nn[i][3]=i;
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-1)/5+1)%N;
	  nn[i][2]=(i-column+L+2*(column-1)/5)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=(i-L-1+N)%N;
	  nn[i][5]=(i-L+N)%N;
	  if (row==0) {nn[i][4]=i;nn[i][5]=i;}
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-2)/5+1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (row==0) nn[i][3]=i;
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1)%N;
	  nn[i][2]=(i-L-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (row==0) {nn[i][3]=i;nn[i][2]=i;}
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-L-1+N)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==L-1) nn[i][0]=i;
	  if (row==0) {nn[i][3]=i;nn[i][2]=i;}
	}
    }

    //----------------------row 2----------------------------
    if (row%8==1) {
      if (column%2==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+2*L/5)%N;
	  nn[i][2]=(i-column-L+5*column/2)%N;
	  nn[i][3]=(i-column-L+5*column/2+1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
      if (column%2==1)
	{
	  nn[i][0]=(i+2*L/5)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-column-L+5*(column-1)/2+1)%N;
	  nn[i][3]=(i-column-L+5*(column-1)/2+2)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
    }
    //----------------------row 3----------------------------
    if (row%8==2) {
      if (column%2==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+2*L/5+5*column/2+1)%N;
	  nn[i][2]=(i-column+2*L/5+5*column/2)%N;
	  nn[i][3]=(i-2*L/5)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
      if (column%2==1)
	{
	  nn[i][0]=(i-column+2*L/5+5*(column-1)/2+2)%N;
	  nn[i][1]=(i-column+2*L/5+5*(column-1)/2+1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-2*L/5)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
    }
 
    //----------------------row 4----------------------------

   if (row%8==3) {
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==L-1) nn[i][0]=i;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-column-2*L/5+2*(column)/5)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==0) nn[i][2]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=(i-column-2*L/5+2*(column-1)/5)%N;
	  nn[i][5]=(i-column-2*L/5+2*(column-1)/5+1)%N;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-column-2*L/5+2*(column-2)/5+1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
    }

    //----------------------row 5----------------------------
    if (row%8==4) {
      if (column%5==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-2)/5)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L+1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
      if (column%5==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-3)/5+1)%N;
	  nn[i][2]=(i-column+L+2*(column-3)/5)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=(i-L+1+N)%N;
	}
      if (column%5==4)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-4)/5+1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==L-1) nn[i][0]=i;
	}
      if (column%5==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1)%N;
	  nn[i][2]=(i-L+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	  if (column==0) nn[i][1]=i;
	}
      if (column%5==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-L+N)%N;
	  nn[i][3]=(i-L+1)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
    }

    //----------------------row 6----------------------------
    if (row%8==5) {
      if (column%2==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+2*L/5)%N;
	  nn[i][2]=(i-column-L+5*column/2+2)%N;
	  nn[i][3]=(i-column-L+5*column/2+3)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
      if (column%2==1)
	{
	  nn[i][0]=(i+2*L/5)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-column-L+5*(column-1)/2+3)%N;
	  nn[i][3]=(i-column-L+5*(column-1)/2+4)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
    }
    //----------------------row 7----------------------------
    if (row%8==6) {
      if (column%2==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+2*L/5+5*column/2+3)%N;
	  nn[i][2]=(i-column+2*L/5+5*column/2+2)%N;
	  nn[i][3]=(i-2*L/5)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
      if (column%2==1)
	{
	  nn[i][0]=(i-column+2*L/5+5*(column-1)/2+4)%N;
	  nn[i][1]=(i-column+2*L/5+5*(column-1)/2+3)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-2*L/5)%N;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
    }
  }   
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
  for (i=0;i<N;i+=14*L/5)  {if (findroot(i)==root) temp++;if (findroot(i+9*L/5)==root) temp++;}
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=14*L/5)   {if (findroot(i+L-1)==root) temp++;if (findroot(i+9*L/5+L-1)==root) temp++;}
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
