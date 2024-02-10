/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *uno=list1,*dos=list2,*final=NULL,*pivot=NULL;
    while(uno || dos){
        if(!dos || (uno && uno->val < dos->val)){if(final){pivot->next=uno;pivot=pivot->next;}else{final=uno;pivot=final;}uno=uno->next;}
        else if(!uno || (dos && dos->val<=uno->val)){if(final){pivot->next=dos;pivot=pivot->next;}else{final=dos;pivot=final;}dos=dos->next;}
    }
    return final;
}