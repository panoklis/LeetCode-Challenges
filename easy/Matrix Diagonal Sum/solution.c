int diagonalSum(int** mat, int matSize, int* matColSize){
    int i,sum=0,size=matSize-1;
    for(i=0;i<=size;i++){
        sum += mat[i][i] + mat[size-i][i];
    }
    if(matSize%2){
        sum -= mat[matSize/2][matSize/2];
    }
    return sum;
}