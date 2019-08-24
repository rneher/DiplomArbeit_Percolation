//lattice dependent code


//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%((L*14)/3);
    row=(i-column)*6/(L*14/3);
    if (column>=2*L/3) {row++; column-=2*L/3;}    //calculate row and column number of site i
    if (column>=L) {row++; column-=L;
    if (column>=2*L/3) {row++; column-=2*L/3;
    if (column>=2*L/3) {row++; column-=2*L/3;
    if (column>=L) {row++; column-=L;
    if (column>=2*L/3) {row++; column-=2*L/3;}}}}}

    if (row%6==0) {
      if (column%2){
	nn[i][0]=(i-column+L*2/3+column*3/2+1)%N;
	nn[i][1]=(i-column+L*2/3+column*3/2)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-L*2/3+N-1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i-column+L*2/3+column*3/2+1)%N;
	nn[i][2]=(i-column+L*2/3+column*3/2)%N;
	nn[i][3]=(i-L*2/3+N-1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }      
    }
    if (row%6==1) {
      if ((column-1)%3==0){
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i-column+L+column*2/3+1)%N;
	nn[i][2]=(i-column+L+column*2/3)%N;
	nn[i][3]=(i-1+N)%N;
	nn[i][4]=(i-column-L*2/3+column*2/3+N)%N;
	nn[i][5]=(i-column-L*2/3+column*2/3+1+N)%N;
		
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i-column+L+column*2/3)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-column-L*2/3+column*2/3)%N;
	nn[i][4]=i;
	nn[i][5]=i;          	
      }
    }
    if (row%6==2) {
      if (column%2){
	nn[i][0]=(i+L*2/3-1)%N;
	nn[i][1]=(i-1+N)%N;
	nn[i][2]=(i-column-L+column*3/2+N)%N;
	nn[i][3]=(i-column-L+column*3/2+N+1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L*2/3-1)%N;
	nn[i][2]=(i-column-L+column*3/2+N)%N;
	nn[i][3]=(i-column-L+column*3/2+N+1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }      
    }
    if (row%6==3) {
      if (column%2){
	nn[i][0]=(i-column+L*2/3+column*3/2+1)%N;
	nn[i][1]=(i-column+L*2/3+column*3/2)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-L*2/3+N+1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i-column+L*2/3+column*3/2+1)%N;
	nn[i][2]=(i-column+L*2/3+column*3/2)%N;
	nn[i][3]=(i-L*2/3+N+1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }      
    }
    if (row%6==4) {
      if ((column-1)%3==0){
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i-column+L+column*2/3+1)%N;
	nn[i][2]=(i-column+L+column*2/3)%N;
	nn[i][3]=(i-1+N)%N;
	nn[i][4]=(i-column-L*2/3+column*2/3+N)%N;
	nn[i][5]=(i-column-L*2/3+column*2/3+1+N)%N;
		
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i-column+L+column*2/3)%N;
	nn[i][2]=(i-1+N)%N;
	nn[i][3]=(i-column-L*2/3+column*2/3)%N;
	nn[i][4]=i;
	nn[i][5]=i;          	
      }
    }
    if (row%6==5) {
      if (column%2){
	nn[i][0]=(i+L*2/3+1)%N;
	nn[i][1]=(i-1+N)%N;
	nn[i][2]=(i-column-L+column*3/2+N)%N;
	nn[i][3]=(i-column-L+column*3/2+N+1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }else{
	nn[i][0]=(i+1)%N;
	nn[i][1]=(i+L*2/3+1)%N;
	nn[i][2]=(i-column-L+column*3/2+N)%N;
	nn[i][3]=(i-column-L+column*3/2+N+1)%N;
	nn[i][4]=i;
	nn[i][5]=i;
      }      
    }


  }
  for(i=0; i<L*2/3;i++) {//cut bonds pointing upwards in first row 
    nn[i][3]=i;
  }
  for (i=0;i<L;i+=3)//cut right and left bound bonds in last and first column
    {
      nn[(i*7*L)/9+(L*2)/3][2]=(i*7*L)/9+(L*2)/3;
      nn[(i*7*L)/9+(L*5)/3-1][0]=(i*7*L)/9+(L*5)/3-1;
    }
  for(i=N-1; i>N-1-L*2/3;i--) {//cut bonds pointing downwards in last row 
      if (i%2) nn[i][0]=i; 
      else nn[i][1]=i;
  }
}
 
