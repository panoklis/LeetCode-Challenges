int arraySign(int* nums, int numsSize){
    int i,negatives=0;
    for(i=0;i<numsSize;i++){
        if(nums[i] == 0)
            return 0;
        if(nums[i]<0)
            negatives++;
    }
    return (negatives%2 ? -1 : 1);
}