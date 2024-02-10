/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

    int i,target=0,ended=0,min,firstflag=1;
    struct ListNode **k,*head,*tail;
    printf("ListsSize: %d\n",listsSize);
    if(listsSize == 0)
        return NULL;
    k=malloc(sizeof(struct ListNode*)*listsSize);
    for(i=0;i<listsSize;i++){
        k[i]=lists[i];
        if(!k[i]) {ended++;}
    }
    head=tail=NULL;

    while(ended < listsSize){
        min=10001;
        for(i=0;i<listsSize;i++){
            if(k[i] && k[i]->val < min) {min=k[i]->val;target=i;}
        }
        if(firstflag) {head=tail=k[target];k[target]=k[target]->next;firstflag=0;}
        else {tail->next = k[target]; k[target] = k[target]->next; tail=tail->next;}
        if(!k[target]) {ended++;}
    }
        if(tail) {tail->next=NULL;}
        else
            return NULL;
        return head;
}