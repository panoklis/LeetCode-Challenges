/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    int i,j,pi=0;                     //pi :: pairs last empty
    struct Node *newhead, *pivot = head, *newpivot;
    struct Node* pairs[1000][2];    //original list node -> new list node

    if(!head)
        return NULL;
    for (i=0;i<1000;i++){
        pairs[i][0] = NULL;
        pairs[i][1] = NULL;
    }
    
    newpivot=malloc(sizeof(struct Node));
    newhead=newpivot;
    
    while(pivot){
        newpivot->val = pivot->val;
        newpivot->random = NULL;

        pairs[pi][0]=pivot;
        pairs[pi][1]=newpivot;
        pi++;

        if(pivot->next){
            newpivot->next=malloc(sizeof(struct Node));
            newpivot=newpivot->next;
        }
        pivot=pivot->next;
    }
    newpivot->next = NULL;

    for(i=0;i<1000;i++){
        if(pairs[i][0]){
            if(pairs[i][0]->random){
                for(j=0;j<1000;j++){
                    if(pairs[i][0]->random == pairs[j][0]){
                        pairs[i][1]->random = pairs[j][1];
                        break;
                    }
                }
            }
        }
        else
            break;
    }

    return newhead;
}