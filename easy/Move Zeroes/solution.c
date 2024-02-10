void moveZeroes(int* nums, int numsSize){
    int i,j=0;
    for(i=0;i<numsSize;i++)
        if(nums[i]) {nums[j] = nums[i]; j++;}
    for(j;j<numsSize;j++)
        if(nums[j]) {nums[j]=0;}
}