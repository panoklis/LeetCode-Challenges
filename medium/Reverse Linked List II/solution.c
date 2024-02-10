/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *temp=head,*ttemp,*leftnode,*lleft=NULL,*rightnode=NULL,*rright=NULL,*prev=NULL;
    int i=0;

    while(temp){
        i++;
        if(i == left){
            leftnode = temp;
            if(prev)
                lleft=prev;
        }
        if(i == right){
            rightnode=temp;
            rright=temp->next;
            break;
        }

        prev=temp;
        temp=temp->next;
    }

    if (rightnode == leftnode || !rightnode || !leftnode)
        return head;

    temp=leftnode;
    prev=NULL;
    while(temp != rright){
        ttemp=temp->next;
        if(prev){
            temp->next=prev;
        }
        prev=temp;
        temp=ttemp;
    }
    leftnode->next=rright;
    if(lleft)
        lleft->next=rightnode;
    else
        head=rightnode;

    return head;
}