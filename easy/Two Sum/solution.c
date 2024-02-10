/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASHMAP_SIZE 25000

 struct node{
     int val;
     int index;
     struct node *next;
 };

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j,off, *ret=malloc(sizeof(int)*(*returnSize=2));
    struct node *pivot,*temp,**ht=malloc(sizeof(struct node*)*HASHMAP_SIZE);
    memset(ht,NULL,sizeof(struct node*)*HASHMAP_SIZE);

    for(i=0;i<numsSize;i++){
        //printf("%d\n",nums[i]);
        temp=malloc(sizeof(struct node));
        temp->val=nums[i];
        temp->index=i;
        temp->next=NULL;
        pivot=ht[abs(nums[i])%HASHMAP_SIZE];
        if(!pivot) {ht[abs(nums[i])%HASHMAP_SIZE]=temp;}
        else {while(pivot->next) {pivot=pivot->next;}pivot->next=temp;}
    }

    for(i=0;i<numsSize;i++){
        off=target-nums[i];
        pivot=ht[abs(off)%HASHMAP_SIZE];
        if(pivot){
            while(pivot->next && (pivot->val != off || pivot->index == i)) {pivot=pivot->next;}
            if(pivot->val == off && pivot->index != i){
                ret[0]=i;
                ret[1]=pivot->index;
                return ret;
            }
        }
    }

    ret[0]=-1;
    ret[1]=-1;
    return ret;
}