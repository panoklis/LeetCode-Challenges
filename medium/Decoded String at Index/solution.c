struct substr{
    int start;
    int end;
    int reps;
    int repcost;
    struct substr* next;
    struct substr* prev;
};

/*
    TODO :: Combine list of repetitions with array of counters
            One foreach node
            Use counters to exhaust final combination repetitions, until k is reached
            (or do it with recursion) ✅ (works well)
            (implement addition of counter without traversal, if k<(counter after traversal))✅ (using accumulative repcost)
            ^ This reduces execution time dramatically

*/

int scan(struct substr *start, int *counter, int limit){
    int rez=-1,i;
    if(start->prev){
        for(i=0;i<start->prev->reps;i++){
            if((*counter)+start->prev->repcost < limit) {(*counter) += start->prev->repcost;}  //Avoid reps, if k won't be found in them.
            else {rez = scan(start->prev,counter,limit);}
            if(rez != -1)
                return rez;
        }
    }
    for(i=start->start;i<=start->end;i++){
        (*counter)++;
        if((*counter) == limit) {return i;}
    }
    return -1;
}

char * decodeAtIndex(char * s, int k){
    int i,j,t,prev=0,next=0,sub=0,len=strlen(s),total=0;
    int tmp;
    struct substr *head=NULL,*curr;
    for(i=0;i<len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            tmp=1;
            j=0;
            //Calculate estimated length of 'decoded' string.
            //Check if, with current nodes, 'k' is reached.
            total += ((next - prev)+1);
            while(s[i] >= '0' && s[i] <= '9' && i<len){
                tmp *= s[i] - '0';
                i++;
                for(j;j<tmp;j++)
                    if(total*j >= k) {tmp=j;break;}
                if(total*tmp >= k) {break;}
            }
            if(!head){
                head=curr=malloc(sizeof(struct substr));
                head->prev = NULL;
            }
            else{
                curr->next=malloc(sizeof(struct substr));
                curr->next->prev=curr;
                curr=curr->next;
            }
            curr->start=prev;
            curr->end=next;
            curr->reps=tmp;
            curr->next=NULL;
            prev=next=i;

            curr->repcost=total;
            total *= tmp;
            if(total >= k) {break;}
        }
        else {next=i;}
    }

    if(i == len && s[i-1] < '0' || s[i-1] > '9'){       //If string finishes without repetitions, add final string with (1) repetition.
        if(!head){
                head=curr=malloc(sizeof(struct substr));
                head->prev = NULL;
        }
        else{
            curr->next=malloc(sizeof(struct substr));
            curr->next->prev=curr;
            curr=curr->next;
        }
        curr->start=prev;
        curr->end=next;
        curr->reps=1;
        curr->next=NULL;

        total += (next-prev+1);
        curr->repcost=total;
    }

    /*debug
    printf("TOTAL:%d STR:%s\n",total,s);
    curr=head;
    while(curr){
        printf("->[REPS:%d STR:(",curr->reps);
        for(i=curr->start;i<=curr->end;i++) {printf("%c",s[i]);}
        printf(") COST:%d]",curr->repcost);
        curr=curr->next;
    }
            printf("\n");
    debug*/

    int *tt=malloc(sizeof(int));
    *tt=0;
    int rez=-1;
    curr=head;
    while(curr->next){
        curr=curr->next;
    }
    for(i=0;i<curr->reps;i++){
        if((*tt)+curr->repcost < k) {(*tt) += curr->repcost;}
        rez = scan(curr,tt,k);
        if(rez != -1) {break;}
    }
    if(rez != -1) {
        char *rez_s=malloc(sizeof(char)*2);
        rez_s[0] = s[rez];
        rez_s[1] = NULL;
        return rez_s;
    }
    else {return "x";}
}