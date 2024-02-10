/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int k=0,i;
    struct ListNode *curr=head,*prev=NULL;
 
    while(curr){curr=curr->next; k++;}
 
    curr=head;
    for(i=0;i<(k-n);i++) {prev=curr; curr=curr->next;}

    if(prev) {prev->next = curr->next;}
    else     {return curr->next;}
    
    return head;
}