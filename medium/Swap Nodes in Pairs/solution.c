/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void sswitch(bool *state){
    if(*state)
        *state = false;
    else
        *state = true;
}

struct ListNode* swapPairs(struct ListNode* head){
    bool state=false;
    struct ListNode *init=head,*last=NULL,*prev=NULL,*pivot=head;
    while(pivot){
        if(state){
            if(prev == head) {init = pivot;}
            if(last){last->next = pivot;}
            prev->next = pivot->next;
            pivot->next = prev;
            pivot = prev->next;
            last = prev;
        }
        prev=pivot;
        if(!state) {pivot = pivot->next;}
        sswitch(&state);
    }
    return init;
}