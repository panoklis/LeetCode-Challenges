struct last{
    char l;
    struct last *prev;
};
bool isValid(char * s){
    struct last *temp,*stack=NULL;
    int i,len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]=='('){temp=malloc(sizeof(struct last));temp->l=')';temp->prev=stack;stack=temp;}
        else if(s[i]=='['){temp=malloc(sizeof(struct last));temp->l=']';temp->prev=stack;stack=temp;}
        else if(s[i]=='{'){temp=malloc(sizeof(struct last));temp->l='}';temp->prev=stack;stack=temp;}
        else if(!stack || s[i] != stack->l) {return false;}
        else {temp=stack; stack=stack->prev; free(temp);}
    }
    return stack ? false : true;
}