/**
 * Return an array of arrays of size * returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int*  returnSize, int** returnColumnSizes){
    int i,j,a,b,**FinalArray;
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int)*numRows);
    FinalArray = (int**)malloc(sizeof(int*)*numRows);
    for(i=0;i<numRows;i++){
        FinalArray[i]=(int*)malloc(sizeof(int)*(i+1));
        for(j=0;j<=i;j++){
            if(i==0) {*FinalArray[i] = 1; break;}
            if(i==1) {FinalArray[i][0] = FinalArray[i][1] = 1; break;}
            a=(j-1<0) ? 0 : FinalArray[i-1][j-1];
            b=(j==i)  ? 0 : FinalArray[i-1][j];
            FinalArray[i][j] = a+b;
        }
        (*returnColumnSizes)[i]=i+1;
    }
/*
    printf("[");
    for(i=0;i<*returnSize;i++){
        printf("[");
        for(j=0;j<(*returnColumnSizes)[i];j++){
            if(j) {printf(",");}
            printf("%d",FinalArray[i][j]);
        }
        printf("]");
    }
    printf("]");
*/
    return FinalArray;
}