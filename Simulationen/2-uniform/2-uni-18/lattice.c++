//lattice dependent code


//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%(5*L/2);      //determine row and column number
    row=(i-column)/(5*L/2)*3;  //substract # of vertices bigger than periodic row segment
    if (column>=L) {           //subtract different row length and increment row
      column-=L; row++;
      if (column>=L/2)
	{
	  column-=L/2; row++;
	}
    }
    if (row%3==0) {
      if (column%2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+3*L/2)%N;
	  nn[i][2]=(i+L-column+(column-1)/2)%N;
	  nn[i][3]=(i-L+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}else{
	  nn[i][0]=(i+L-column+column/2)%N;
          nn[i][1]=(i+3*L/2)%N;
          nn[i][2]=(i-1+N)%N;
          nn[i][3]=(i-L+N)%N;    
	  if (column==0) nn[i][2]=i;
	}
    }
    if (row%3==1) {
	nn[i][0]=(i+L/2+column+1)%N;
	nn[i][1]=(i+L/2+column)%N;
	nn[i][2]=(i-L+column+N)%N;
	nn[i][3]=(i-L+1+column+N)%N;
    }
    if (row%3==2) {
      if (column%2)
        {
          nn[i][0]=(i+1)%N;
          nn[i][1]=(i+L)%N;
          nn[i][2]=(i-L/2-column+(column-1)/2)%N;
          nn[i][3]=(i-3*L/2+N)%N;
	  if (column==L-1) nn[i][0]=i;
        }else{
          nn[i][0]=(i+L)%N;
          nn[i][1]=(i-1+N)%N;
          nn[i][2]=(i-3*L/2+N)%N;
          nn[i][3]=(i-L/2-column/2+N)%N;
	  if (column==0) nn[i][1]=i;
        }
  
    }
    
    if (row==0)
      {  
	nn[i][3]=i;
      }
    if (row==L-1) //cut bonds pointing downwards in last row 
      {
	if (column%2) nn[i][1]=i; 
	else nn[i][0]=i;
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
  for (i=0;i<L;i+=3)  if (findroot(i*5*L/6)==root) temp++;
  if (temp)
    { 
      temp=0;
      for (i=0;i<L;i+=3)  if (findroot(i*5*L/6+L-1)==root) temp++;
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
