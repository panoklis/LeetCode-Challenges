char * convert(char * s, int numRows){
  int i,j,k,z=0,d_d,d_u,flag,len=strlen(s);
  char *zigzag = malloc(sizeof(char)*(len+1));
  if(numRows == 1)
    return s;
  for(k=0;k<numRows;k++){
    if(k == 0 || k == numRows-1){
      j = d_d = d_u = 2*(numRows-1);
      flag = 0;
    }
    else{
      d_d = 2*(numRows-1-k);
      d_u = 2*k;
      flag = 1;
    }
    for(i=k;i<len;i+=j){
      zigzag[z] = s[i];
      z++;
      if      (flag == 1)  {j = d_d; flag = 2;}
      else if (flag == 2)  {j = d_u; flag = 1;}
    }
  }
  zigzag[len] = NULL;
  return zigzag;
}