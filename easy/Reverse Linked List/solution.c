/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *newhead=head,*finalhead=NULL,*temphead;
    while(newhead){
        temphead=newhead;
        newhead=newhead->next;
        if(finalhead){temphead->next=finalhead;finalhead=temphead;}
        else {finalhead=temphead;finalhead->next=NULL;}
    }
    return finalhead;
}
