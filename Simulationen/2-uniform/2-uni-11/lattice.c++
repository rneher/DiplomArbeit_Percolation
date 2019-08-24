//lattice dependent code
//lattice 11

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%L;      //determine row and column number
    row=(i-column)/L;   

    if (row%6==0) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=(i-L)%N;
	  if (row==0) {nn[i][4]=i;}
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=i;
	  if (column==L-1) nn[i][0]=i;
	}
    }

    //----------------------row 2----------------------------
    if (row%6==1) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=(i-L+1+N)%N;
	  if (column==0) nn[i][2]=i;
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=(i-L+1+N)%N;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+1+N)%N;
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}
    }

    //----------------------row 3----------------------------
    if (row%6==2) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1)%N;
	  nn[i][2]=(i-L+N)%N;
	  nn[i][3]=(i-L+1+N)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][1]=i;
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+1)%N;
	  nn[i][4]=i;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=(i-L+1+N)%N;
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	  if (column==L-1) nn[i][0]=i;
	}
    }
    //----------------------row 4----------------------------
    if (row%6==3) {
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=(i-L)%N;
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	  if (column==L-1) {nn[i][0]=i;}
	}
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][3]=i;
	}
    }

    //----------------------row 5----------------------------
    if (row%6==4) {
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  if (column==0) nn[i][3]=i;
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L-1+N)%N;
	}
    }

    //----------------------row 6----------------------------
    if (row%6==5) {
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-1)%N;
	  nn[i][2]=(i-L-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==L-1) nn[i][0]=i;
	}
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	  if (row==L-1) nn[i][1]=i;
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  if (row==L-1) nn[i][1]=i;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1)%N;
	  nn[i][4]=i;
	  if (row==L-1) nn[i][1]=i;
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
  /*  for (i=0;i<N;i+=L)  {if (findroot(i)==root) temp++;}
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=L)   {if (findroot(i+L-1)==root) temp++;}
      if (temp) return 1;
      else return 0; 
      }*/
  return 0;

}
