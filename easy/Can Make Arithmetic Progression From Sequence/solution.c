int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    int i,diff;
    qsort(arr, arrSize, sizeof(int), cmpfunc);
    diff=arr[1]-arr[0];
    for(i=2;i<arrSize;i++){
        if(diff != arr[i] - arr[i-1])
            return false;
        diff=arr[i] - arr[i-1];
    }
    return true;
}