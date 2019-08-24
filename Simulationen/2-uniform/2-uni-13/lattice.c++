//lattice dependent code
//Gitter 13

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%L;      //determine row and column number
    row=(i-column)/L;  
    if (row%8==0) 
      {
 	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i+L-1)%N;
	nn[i][3]=(i-1+N)%N;
	nn[i][4]=(i-L+N)%N;
	if (column==0) {nn[i][2]=i;nn[i][3]=i;}
	if (column==L-1) {nn[i][0]=i;}
      }
    if (row%8==1) 
      {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-L+N)%N;
	nn[i][4]=(i-L+1+N)%N;
	if (column==0) {nn[i][2]=i;}	
	if (column==L-1) {nn[i][0]=i;nn[i][4]=i;}	
      }
    if (row%8==2) 
      {
          nn[i][0]=(i+1)%N;
          nn[i][1]=(i+L+N)%N;
          nn[i][2]=(i-1+N)%N;
          nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	  if (column==L-1) nn[i][0]=i;
      }
    if (row%8==3) 
      {
          nn[i][0]=(i+1)%N;
          nn[i][1]=(i+L+N)%N;
          nn[i][2]=(i-1+N)%N;
          nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	  if (column==L-1) nn[i][0]=i;
      }
    if (row%8==4) 
      {
 	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L+1)%N;
	nn[i][2]=(i+L)%N;
	nn[i][3]=(i-1+N)%N;
	nn[i][4]=(i-L+N)%N;
	if (column==0) {nn[i][3]=i;}
	if (column==L-1) {nn[i][0]=i;nn[i][1]=i;}
      }
    if (row%8==5) 
      {
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-L-1+N)%N;
	nn[i][4]=(i-L+N)%N;
	if (column==0) {nn[i][2]=i; nn[i][3]=i;}	
	if (column==L-1) {nn[i][0]=i;}	
      }
    if (row%8==6) 
      {
          nn[i][0]=(i+1)%N;
          nn[i][1]=(i+L+N)%N;
          nn[i][2]=(i-1+N)%N;
          nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	  if (column==L-1) nn[i][0]=i;
      }
    if (row%8==7) 
      {
          nn[i][0]=(i+1)%N;
          nn[i][1]=(i+L+N)%N;
          nn[i][2]=(i-1+N)%N;
          nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	  if (column==L-1) nn[i][0]=i;
      }
       
    if (row==0)
      {  
	nn[i][4]=i;
      }
    if (row==L-1) //cut bonds pointing downwards in last row 
      {
	nn[i][1]=i; 
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
  for (i=0;i<L;i++) if (findroot(i*L)==root) temp++;
  if (temp)
    { 
      temp=0;
      for (i=0;i<L;i++)  if (findroot(i*L+L-1)==root) temp++;
      if (temp) return 1;
      else return 0; 
    }
  return 0;

}
