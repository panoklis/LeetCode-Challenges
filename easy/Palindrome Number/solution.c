struct stack{
    struct node *top;
};

struct node{
    int index;
    struct node *prev;
};

struct stack *stack_create(){
    struct stack *stc=malloc(sizeof(struct stack));
    stc->top=NULL;
    return stc;
}

void push(struct stack *stck, int index){
    struct node *nd=malloc(sizeof(struct node));
    nd->index=index;
    if(stck->top) {
        nd->prev=stck->top;
    }
    else {nd->prev=NULL;}
    stck->top=nd;
}
int pop(struct stack *stck){
    struct node *tmp;
    int ret;
    if(stck->top){
        tmp=stck->top;
        stck->top=stck->top->prev;
        ret=tmp->index;
        free(tmp);
    }
    else {ret = -1;}
    return ret;
}

int peek(struct stack *stck){
    if(stck->top)
        return stck->top->index;
    else
        return -1;
}

bool isPalindrome(int x){
    if(x<10 && x>=0) {return true;}
    if(x<0) {return false;}
    struct stack *stc = stack_create();
    int i,y=x,depth=1,len=0;
    while(y/depth) {y/=10;len++;}
        for(i=0;i<(len/2);i++){
        push(stc,x%10);
        x/=10;
    }
    if(len%2) {x/=10;} //If odd, ignore middle digit.
    for(i=0;i<(len/2);i++){
        if( pop(stc) != (x%10) ) {return false;}
        x/=10;
    }
    return true;
}