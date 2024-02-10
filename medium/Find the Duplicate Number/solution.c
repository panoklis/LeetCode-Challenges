int findDuplicate(int* nums, int numsSize){
    int i,j,max=0,*nnums;

    for(i=0;i<numsSize;i++){if(nums[i]>max){max=nums[i];}}
    nnums=malloc(sizeof(int)*(max+1));
    for(i=0;i<=max;i++){nnums[i]=0;}

    for(i=0;i<numsSize;i++){nnums[nums[i]]++;}
    for(i=0;i<=max;i++){if(nnums[i]>=2){return i;}}
    return nums[0];
}