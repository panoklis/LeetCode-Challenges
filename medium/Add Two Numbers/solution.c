/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int i,tmp,rem=0,a,b,f1=1,f2=1;
    struct ListNode *ll1=l1,*ll2=l2,*result = NULL,*node;
    while(ll1 || ll2){
        if(f1 && ll1) {a = ll1->val; ll1=ll1->next;}
        else    {a=0; f1=0;}
        if(f2 && ll2) {b = ll2->val; ll2=ll2->next;}
        else    {b=0; f2=0;}
        tmp = a + b + rem;
        rem = tmp/10;
        tmp %= 10;
        //printf("%d",tmp);
        if(!result) {result=node=malloc(sizeof(struct ListNode));}
        else        {node->next=malloc(sizeof(struct ListNode));node=node->next;}

        node->val = tmp;
        node->next = NULL;
    }
    if(rem) {
        //printf("%d",rem);
        node->next=malloc(sizeof(struct ListNode));
        node=node->next;
        node->val = rem;
        node->next = NULL;
    }
    return result;
}