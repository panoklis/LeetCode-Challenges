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

char * removeDuplicateLetters(char * s){
    struct stack *lex_stack=stack_create();
    int tmp,i,k=0,len=strlen(s);
    bool *entered=malloc(sizeof(bool)*26);
    int *abc=malloc(sizeof(int)*26);

    for(i=0;i<26;i++){abc[i]=0; entered[i]=false;}

    for(i=0;i<len;i++) {abc[s[i]-97]++;}

    for(i=0;i<len;i++){
        abc[s[i] - 97]--;
        if(!(entered[s[i]-97])){
            while(peek(lex_stack) != -1 && s[i]<s[peek(lex_stack)] && abc[s[peek(lex_stack)]-97]){
                entered[s[pop(lex_stack)]-97]=false; k--;
            }
            entered[s[i]-97]=true;
            push(lex_stack,i); k++;
        }
    }
    char *out=malloc(sizeof(char)*(k+1));
    out[k]=NULL;
    for(i=k-1;i>=0;i--) {out[i]=s[pop(lex_stack)];}
    return out;
}

//TODO :: Learn C++