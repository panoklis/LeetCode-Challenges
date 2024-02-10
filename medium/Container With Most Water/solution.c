int maxArea(int* height, int heightSize){
    int i,j,maxvol=0;
    for(i=0;i<heightSize-1;i++){
        if((heightSize-i)*height[i] > maxvol){   //exclude combination search for i,
                                                //if max potential area cannot surpass maxvol
            for(j=i+1;j<heightSize;j++){
                if(height[i]<=height[j]){
                    if((j-i)*height[i] > maxvol)
                        maxvol = (j-i)*height[i];
                }
                else{
                    if((j-i)*height[j] > maxvol)
                        maxvol = (j-i)*height[j];
                }
            }
        }
    }
    return maxvol;
}