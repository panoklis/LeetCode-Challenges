bool isMonotonic(int* nums, int numsSize){
    int i=1,direction=0;
    if(nums[0]<nums[numsSize-1]) {direction=1;}
    else if(nums[0]>nums[numsSize-1]) {direction=2;}
    else{
        for(i;i<numsSize;i++){
            if(nums[i-1]<nums[i]) {i++; direction=1; break;}
            if(nums[i-1]>nums[i]) {i++; direction=2; break;}
        }
    }
    if(!direction) {return true;}
    if(direction == 1){
        for(i;i<numsSize;i++)
            if(nums[i-1] > nums[i]) {return false;}
    }
    else if(direction == 2){
         for(i;i<numsSize;i++)
             if(nums[i-1] < nums[i]) {return false;}
    }
    return true;
}