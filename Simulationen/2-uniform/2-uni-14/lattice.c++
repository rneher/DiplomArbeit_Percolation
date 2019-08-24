//lattice dependent code
//lattice 14

//set adjacencies and boundary conditions
void boundaries(void)            
{
  int i,row,column;
  

  for (i=0; i<N; i++) {         
    column=i%(3*L);      //determine row and column number
    row=(i-column)/(3*L)*5;   
    if (column>=L)
      {
	row++; column-=L;
	if (column>=L/4)
	  {
	    row++; column-=L/4;
	    if (column>=L/2)
	      {
		row++; column-=L/2;
		if (column>=L/4)
		  {
		    row++; column-=L/4;
		  }
	      }
	  }
      }
    //-----------------------row 1--------------

    if (row%10==0) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+5*L/4+column/2)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	  if (row==0) {nn[i][3]=i;}
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+(column-1)/4)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1)%N;
	  nn[i][4]=(i-L)%N;
	  if (row==0) {nn[i][3]=i;nn[i][4]=i;}
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+(column-2)/4)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=(i-L+1+N)%N;
	  if (row==0) {nn[i][3]=i;nn[i][4]=i;}
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+5*L/4+(column-3)/2+1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==L-1) nn[i][0]=i;
	  if (row==0) {nn[i][3]=i;}
	}
    }
    //---------------------row 2 --------------
    if (row%10==1)
      {
	nn[i][0]=(i+L/4+column+1)%N;
	nn[i][1]=(i+3*L/4)%N;
	nn[i][2]=(i+L/4+column)%N;
	nn[i][3]=(i-column-L+4*column+1)%N;
	nn[i][4]=(i-column-L+4*column+2)%N;
      }

    //----------------------row 3----------------------------
    if (row%10==2) {
      if (column%2==0)
	{
	  nn[i][0]=(i-column+L/2+column/2)%N;
	  nn[i][1]=(i+3*L/4+column)%N;
	  nn[i][2]=(i-5*L/4+column)%N;
	  nn[i][3]=(i-column-L/4+column/2)%N;
	  nn[i][4]=i;
	}
      if (column%2==1)
	{
	  nn[i][0]=(i-column+3*L/4+2*column+1)%N;
	  nn[i][1]=(i-column+L/2+(column-1)/2)%N;
	  nn[i][2]=(i-column-L/4+(column-1)/2+N)%N;
	  nn[i][3]=(i-column-5*L/4+2*column+1)%N;
	  nn[i][4]=i;
	}
    }
    //---------------------row 4 --------------
    if (row%10==3)
      {
	nn[i][0]=(i-column+L/4+4*column+2)%N;
	nn[i][1]=(i-column+L/4+4*column+1)%N;
	nn[i][2]=(i-3*L/4+N)%N;
	nn[i][3]=(i-column-L/2+2*column)%N;
	nn[i][4]=(i-column-L/2+2*column+1)%N;
      }


    //-------------------- row 5---------------
    if (row%10==4) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-3*L/4+column/2+N)%N;
	  nn[i][4]=i;
	  if (column==0) nn[i][2]=i;
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1+N)%N;
	  nn[i][3]=(i-1)%N;
	  nn[i][4]=(i-column-L/4+(column-1)/4)%N;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-L/4+(column-2)/4)%N;
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-3*L/4+(column-3)/2+1+N)%N;
	  nn[i][4]=i;
	  if (column==L-1) {nn[i][0]=i;}
	}
    }
    //--------------------row 6----------------
    if (row%10==5) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+column/4-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=(i-L+1+N)%N;
	  if (column==0) {nn[i][1]=i;nn[i][2]=i;}
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+5*L/4+(column-1)/2-1)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	  if (column==1) nn[i][1]=i;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+5*L/4+(column-2)/2)%N;
	  nn[i][2]=(i-1)%N;
	  nn[i][3]=(i-L+N)%N;
	  nn[i][4]=i;
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i-column+L+(column-3)/4)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-L-1+N)%N;
	  nn[i][4]=(i-L+N)%N;
	  if (column==L-1) nn[i][0]=i;
	}
    }
    //---------------------row 7 --------------
    if (row%10==6)
      {
	nn[i][0]=(i+L/4+column+1)%N;
	nn[i][1]=(i+3*L/4)%N;
	nn[i][2]=(i+L/4+column)%N;
	nn[i][3]=(i-column-L+4*column+3)%N;
	nn[i][4]=(i-column-L+4*column+4)%N;
	if (column==L/4-1) nn[i][4]=i;
      }

    //----------------------row 8----------------------------
    if (row%10==7) {
      if (column%2==0)
	{
	  nn[i][0]=(i-column+L/2+column/2)%N;
	  nn[i][1]=(i+3*L/4+column+2)%N;
	  nn[i][2]=(i-5*L/4+column+2)%N;
	  nn[i][3]=(i-column-L/4+column/2)%N;
	  nn[i][4]=i;
	}
      if (column%2==1)
	{
	  nn[i][0]=(i-column+3*L/4+2*column+3)%N;
	  nn[i][1]=(i-column+L/2+(column-1)/2)%N;
	  nn[i][2]=(i-column-L/4+(column-1)/2+N)%N;
	  nn[i][3]=(i-column-5*L/4+2*column+3)%N;
	  nn[i][4]=i;
	  if (column==L/2-1) {nn[i][0]=i;nn[i][3]=i;}
	}
    }
    //---------------------row 9 --------------
    if (row%10==8)
      {
	nn[i][0]=(i-column+L/4+4*column+4)%N;
	nn[i][1]=(i-column+L/4+4*column+3)%N;
	nn[i][2]=(i-3*L/4+N)%N;
	nn[i][3]=(i-column-L/2+2*column)%N;
	nn[i][4]=(i-column-L/2+2*column+1)%N;
	if (column==L/4-1) nn[i][0]=i;
      }


    //-------------------- row 10---------------
    if (row%10==9) {
      if (column%4==0)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L+1)%N;
	  nn[i][2]=(i+L)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-L/4+column/4-1+N)%N;
	  if (row==L-1) {nn[i][1]=i;nn[i][2]=i;}
	  if (column==0) {nn[i][3]=i;nn[i][4]=i;}
	}
      if (column%4==1)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-3*L/4+(column-1)/2-1)%N;
	  nn[i][4]=i;
	  if (row==L-1) {nn[i][1]=i;}
	  if (column==1) nn[i][3]=i;
	}
      if (column%4==2)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i-1+N)%N;
	  nn[i][3]=(i-column-3*L/4+(column-2)/2+N)%N;
	  nn[i][4]=i;
	  if (row==L-1) {nn[i][1]=i;}
	}
      if (column%4==3)
	{
	  nn[i][0]=(i+1)%N;
	  nn[i][1]=(i+L)%N;
	  nn[i][2]=(i+L-1+N)%N;
	  nn[i][3]=(i-1+N)%N;
	  nn[i][4]=(i-column-L/4+(column-3)/4+N)%N;
	  if (column==L-1) nn[i][0]=i;
	  if (row==L-1) {nn[i][1]=i; nn[i][2]=i;}
	}
    }
  }  
  /*  int j;
  for (i=0; i<N; i++) {         
    column=i%(3*L);      //determine row and column number
    row=(i-column)/(3*L)*5;   
    if (column>=L)
      {
	row++; column-=L;
	if (column>=L/4)
	  {
	    row++; column-=L/4;
	    if (column>=L/2)
	      {
		row++; column-=L/2;
		if (column>=L/4)
		  {
		    row++; column-=L/4;
		  }
	      }
	  }
      }
    if (column==0) cout <<"\n";
    cout << i<<": ";
   for(j=0;j<NN;j++) cout <<nn[i][j]<<", ";
    cout <<"\n";
    }*/
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
  /*   for (i=0;i<N;i+=3*L)  
    {
      if (findroot(i)==root) temp++;
      if (findroot(i+L)==root) temp++;
      if (findroot(i+5*L/4)==root) temp++;
      if (findroot(i+7*L/4)==root) temp++;
      if (findroot(i+2*L)==root) temp++;
    }
  if (temp)
    { 
      temp=0;
      for (i=0;i<N;i+=3*L)   
	{
	  if (findroot(i+L-1)==root) temp++;
	  if (findroot(i+5*L/4-1)==root) temp++;
	  if (findroot(i+7*L/4-1)==root) temp++;
	  if (findroot(i+2*L-1)==root) temp++;
	  if (findroot(i+3*L-1)==root) temp++;
	}
      if (temp) return 1;
      else return 0; 
      }*/
  return 0;

}
