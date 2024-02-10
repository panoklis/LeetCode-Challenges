void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, *zero_i,*zero_j;
    zero_i=malloc(sizeof(int*)*matrixSize);
    zero_j=malloc(sizeof(int*)*(*matrixColSize));
    for(i=0;i<matrixSize;i++){zero_i[i]=0;}
    for(j=0;j<*matrixColSize;j++){zero_j[j]=0;}

    for(i=0;i<matrixSize;i++){
        for(j=0;j<*matrixColSize;j++){
            if(!matrix[i][j]) {zero_i[i]=1;zero_j[j]=1;}
        }
    }
    for(i=0;i<matrixSize;i++){
        for(j=0;j<*matrixColSize;j++){
            if(zero_i[i] || zero_j[j]) {matrix[i][j]=0;}
        }
    }
}