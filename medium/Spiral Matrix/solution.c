/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int k,j1,j2,i1,i2,g=0,max=matrixSize*(*matrixColSize);
    int* result = (int*)calloc(max, sizeof(int));
    i1=0;
    i2=matrixSize-1;
    j1=0;
    j2=*matrixColSize-1;

    while(true){
        for(k=j1;k<=j2;k++){
            result[g++] = matrix[i1][k];
            //printf("(g=%d) matrix[%d][%d]::%d \n",g,i1,k,matrix[i1][k]);
            if(g == max) {break;}
        }
        if(g == max) {break;}
        i1++;

        for(k=i1;k<=i2;k++){
            result[g++] = matrix[k][j2];
            //printf("(g=%d) matrix[%d][%d]::%d \n",g,k,j2,matrix[k][j2]);
            if(g == max) {break;}
        }
        if(g == max) {break;}
        j2--;
        
        for(k=j2;k>=j1;k--){
            result[g++] = matrix[i2][k];
            //printf("(g=%d) matrix[%d][%d]::%d \n",g,i2,k,matrix[i2][k]);
            if(g == max) {break;}
        }
        if(g == max) {break;}
        i2--;

        for(k=i2;k>=i1;k--){
            result[g++] = matrix[k][j1];
            //printf("(g=%d) matrix[%d][%d]::%d \n",g,k,j1,matrix[k][j1]);
            if(g == max) {break;}
        }
        if(g == max) {break;}
        j1++;
    }
    *returnSize = g;
    //for(int k=0;k<*returnSize;k++){printf("%d -> ",result[k]);}
    return result;
}