//lattice dependent code
//lattice 1

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column,shift;
  

  for (i=0; i<N; i++) {         
    column=i%L;      //determine row and column number
    row=(i-column)/L;  
    shift=(9*(row%L))%13;
      if ((column-shift+13)%13==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=i;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=(i-L+1+N)%N;
	}
       else if ((column-shift+13)%13==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=i;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=(i-L+1+N)%N;
	}
      else if ((column-shift+13)%13==4)
	{
	  nn[i][0]=i;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=(i-L+1)%N;
	}
      else if ((column-shift+13)%13==5)
	{
	  nn[i][0]=i;
	  nn[i][1]=i;
	  nn[i][2]=i;
	  nn[i][3]=i;
	  nn[i][4]=i;
	  nn[i][5]=i;
	}
      else if ((column-shift+13)%13==6)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=i;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=(i-L+1)%N;
	}
      else if ((column-shift+13)%13==8)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=i;
	}
      else if ((column-shift+13)%13==9)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=i;
	  nn[i][5]=(i-L+1)%N;
	}
      else
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  nn[i][5]=(i-L+1)%N;
	}
      if (row==0) {nn[i][4]=i;nn[i][5]=i;}
      if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
      if (column==0) {nn[i][2]=i;nn[i][3]=i;}
      if (column==L-1) {nn[i][0]=i;nn[i][5]=i;}

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
  for (i=0;i<N;i+=L)  
    {
      if (findroot(i)==root) temp++;
    }
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=L)   
	{
	  if (findroot(i+L-1)==root) temp++;
	}
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
