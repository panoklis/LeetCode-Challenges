/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* retarray;
    int i, remainder=1;
    for(i=0;i<digitsSize;i++){
        if(digits[i]!=9)
            break;
    }
    if(i == digitsSize) {
        *returnSize = digitsSize+1;
        retarray = malloc(sizeof(int)*(digitsSize+1));
        retarray[0] = 1;
        for(i=1;i<=digitsSize;i++) {retarray[i] = 0;}
        return retarray;
    }
    else                {retarray = malloc(sizeof(int)*digitsSize); *returnSize = digitsSize;}
    
    for(i=digitsSize-1;i>=0;i--){
        retarray[i] = (digits[i]+remainder) % 10;
        if(remainder)
            remainder = (digits[i]+remainder) / 10;
    }
    return retarray;
}