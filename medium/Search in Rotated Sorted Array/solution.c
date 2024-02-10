int search(int* nums, int numsSize, int target){
    int i, min=nums[0],min_i=0;;
    for(i=1;i<numsSize;i++){
        if(nums[i]<min){
            min=nums[i];
            min_i=i;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[min_i]==target){return min_i;}
        if(++min_i==numsSize) {min_i=0;}
    }
    return -1;
}