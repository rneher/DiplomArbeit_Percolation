//lattice dependent code
//gitter 19

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%(5*L/2);      //determine row and column number
    row=(i-column)/(5*L/2)*4;  //substract # of vertices bigger than periodic row segment
    if (column>=L) {           //subtract different row length and increment row
      column-=L; row++;
      if (column>=L/4)
	{
	  column-=L/4; row++;
	  if (column>=L) {column-=L; row++;} 
	}
    }
    if (row%4==0) {                      //first row
      if (column%4==0)
	{
	  nn[i][0]=(i+L-column+column/4)%N;
	  nn[i][1]=(i+5*L/4)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-5*L/4+N)%N;
	  if (column==0) nn[i][2]=i;
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+5*L/4)%N;
	  nn[i][2]=(i+L-column+(column-1)/4+N)%N;
	  nn[i][3]=(i-5*L/4+N)%N;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+5*L/4)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-5*L/4+N)%N;
	  nn[i][3]=(i-column-L/4+(column-2)/4+N)%N;
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+5*L/4)%N;
	  nn[i][2]=(i-column-L/4+(column-3)/4+N)%N;
	  nn[i][3]=(i-5*L/4+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}
    }
    

    if (row%4==1) {                      //second row
	nn[i][0]=(i+L/4+3*column+1)%N;
	nn[i][1]=(i+L/4+3*column)%N;
	nn[i][2]=(i-L+3*column+N)%N;
	nn[i][3]=(i-L+1+3*column+N)%N;
    }


    if (row%4==2) {                      //third row=first row shifted by 2
      if ((column+2)%4==0)
	{
	  nn[i][0]=(i+L-column+(column-2)/4)%N;
	  nn[i][1]=(i+5*L/4)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-5*L/4+N)%N;
	  if (row==L-2) nn[i][1]=i;
	}
      if ((column+2)%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+5*L/4)%N;
	  nn[i][2]=(i+L-column+(column-3)/4+N)%N;
	  nn[i][3]=(i-5*L/4+N)%N;
	  if (column==L-1) nn[i][0]=i;
	  if (row==L-2) nn[i][1]=i;
	}
      if ((column+2)%4==2)
	{
	  nn[i][0]=(i+5*L/4)%N;
	  nn[i][1]=(i-1+N)%N;
	  nn[i][2]=(i-5*L/4+N)%N;
	  nn[i][3]=(i-column-L/4+column/4+N)%N;
	  if (column==0) nn[i][1]=i;
	  if (row==L-2) nn[i][0]=i;
	}
      if ((column+2)%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+5*L/4)%N;
	  nn[i][2]=(i-column-L/4+(column-1)/4+N)%N;
	  nn[i][3]=(i-5*L/4+N)%N;
	  if (row==L-2) nn[i][1]=i;
	}
    }
    if (row%4==3) {                      //forth row = second shifted by two
	nn[i][0]=(i+L/4+3*column+3)%N;
	nn[i][1]=(i+L/4+3*column+2)%N;
	nn[i][2]=(i-L+3*column+N+2)%N;
	nn[i][3]=(i-L+3*column+N+3)%N;
    }
    
    
    if (row==0)
      {  
	nn[i][3]=i;
	if ((column%4)>=2) nn[i][2]=i;
      }
    if (row==L-1) //cut bonds pointing downwards in last row 
      {
	nn[i][1]=i; 
	nn[i][0]=i;
      }
  }   
} 

int spanning(int root)
{
  int i,temp=0;
  for(i=0;i<L;i++) if (findroot(i)==root) temp++;
  if (temp) {
    temp=0;
    for(i=N-1-L/4;i>N-1-5*L/4;i--) if (findroot(i)==root) temp++;
    if (temp) {return 1;}
  }
  for (i=0;i<L;i+=2)  if (findroot(i*5*L/8)==root) temp++;
  if (temp)
    { 
      temp=0;
      for (i=0;i<L;i+=2)  if (findroot(i*5*L/8+L-1)==root) temp++;
      if (temp) return 1;
      else return 0; 
      }
  return 0;

}
