//lattice dependent code
//lattice 2

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%(8*L/3);      //determine row and column number
    row=3*(i-column)/(8*L/3); //8*L/3 is the length of 3 rows of differetn length  
    if (column>=L) 
      {
	row++; column-=L;        //next row
	if (column>=2*L/3) 
	  {
	    row++; column-=2*L/3;    //next row
	  }
      }
    //-------------------row 1 --------------------------   
    if (row%6==0) {
      if (column%3==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*column/3+1)%N;
	  nn[i][2]=(i-column+L+2*column/3)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=(i-L+1+N)%N;
	  if (column==0) {nn[i][3]=i;}
	  if (row==0) {nn[i][4]=i;nn[i][5]=i;}
	}
      if (column%3==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-1)/3+1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=(i-L+1+N)%N;
	  nn[i][5]=i;
	  if (row==0) {nn[i][3]=i;nn[i][4]=i;}
	}
      if (column%3==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-2)/3+2)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=(i-L+1+N)%N;
	  nn[i][5]=i;
	  if (row==0) {nn[i][3]=i;nn[i][4]=i;}
	  if (column==L-1) {nn[i][0]=i;nn[i][1]=i;nn[i][4]=i;}
	}
    }

    //----------------------row 2----------------------------
    if (row%6==1) {
      if (column%2==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+2*L/3+3*column/2)%N;
	  nn[i][2]=(i-column+2*L/3+3*column/2-1)%N;
	  nn[i][3]=(i-column-L+3*column/2-1+N)%N;
	  nn[i][4]=(i-column-L+3*column/2+N)%N;
	  nn[i][5]=i;
	  if (column==0) {nn[i][2]=i;nn[i][3]=i;}
	}
      if (column%2==1)
	{
	  nn[i][0]=(i-column+2*L/3+3*(column-1)/2+1)%N;
	  nn[i][1]=(i-column+2*L/3+3*(column-1)/2)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-L+3*(column-1)/2+N)%N;
	  nn[i][4]=(i-column-L+3*(column-1)/2+N+1)%N;
	  nn[i][5]=i;
	}
    }
    //-----------------row 3 -------------------
    if (row%6==2) {
      if (column%3==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-2*L/3+2*column/3)%N;
	  nn[i][5]=(i-column-2*L/3+2*column/3+1)%N;
	  if (column==0) {nn[i][3]=i;}
	}
      if (column%3==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-2*L/3+2*(column-1)/3+1+N)%N;
	  nn[i][5]=i;
	}
      if (column%3==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-2*L/3+2*(column-2)/3+2+N)%N;
	  nn[i][5]=i;
	  if (column==L-1) {nn[i][0]=i;nn[i][1]=i;nn[i][4]=i;}
	}
    }
    //-------------------row 4 --------------------------   
    if (row%6==3) {
      if (column%3==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*column/3-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=i;
	  if (column==0) {nn[i][1]=i;nn[i][2]=i;nn[i][3]=i;}
	}
      if (column%3==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-1)/3)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=i;
	}
      if (column%3==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+2*(column-2)/3+1)%N;
	  nn[i][2]=(i-column+L+2*(column-2)/3)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L-1+N)%N;
	  nn[i][5]=(i-L+N)%N;
	  if (column==L-1) {nn[i][0]=i;}
	}
    }

    //----------------------row 5----------------------------
    if (row%6==4) {
      if (column%2==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+2*L/3+3*column/2+2)%N;
	  nn[i][2]=(i-column+2*L/3+3*column/2+1)%N;
	  nn[i][3]=(i-column-L+3*column/2+1+N)%N;
	  nn[i][4]=(i-column-L+3*column/2+2+N)%N;
	  nn[i][5]=i;
	}
      if (column%2==1)
	{
	  nn[i][0]=(i-column+2*L/3+3*(column-1)/2+3)%N;
	  nn[i][1]=(i-column+2*L/3+3*(column-1)/2+2)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-L+3*(column-1)/2+N+2)%N;
	  nn[i][4]=(i-column-L+3*(column-1)/2+N+3)%N;
	  nn[i][5]=i;
	  if (column==2*L/3-1) {nn[i][0]=i;nn[i][4]=i;}
	}
    }
    //-----------------row 6 -------------------
    if (row%6==5) {
      if (column%3==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-2*L/3+2*column/3-1)%N;
	  nn[i][5]=i;
	  if (column==0) {nn[i][2]=i;nn[i][3]=i;nn[i][4]=i;}
	  if (row==L-1) {nn[i][1]=i; nn[i][2]=i;}
	}
      if (column%3==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-2*L/3+2*(column-1)/3+N)%N;
	  nn[i][5]=i;
	  if (row==L-1) {nn[i][1]=i; nn[i][2]=i;}
	}
      if (column%3==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-2*L/3+2*(column-2)/3+N)%N;
	  nn[i][5]=(i-column-2*L/3+2*(column-2)/3+1+N)%N;
	  if (column==L-1) {nn[i][0]=i;}
	  if (row==L-1) {nn[i][1]=i; nn[i][2]=i;}
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
  for (i=0;i<N;i+=8*L/3)  
    {
      if (findroot(i)==root) temp++;
      if (findroot(i+L)==root) temp++;
      if (findroot(i+5*L/3)==root) temp++;
    }
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=8*L/3)   
	{
	  if (findroot(i+L-1)==root) temp++;
	  if (findroot(i+5*L/3-1)==root) temp++;
	  if (findroot(i+8*L/3-1)==root) temp++;
	}
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
