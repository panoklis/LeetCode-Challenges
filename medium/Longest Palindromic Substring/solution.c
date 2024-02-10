/*
* We sort out all palindromes of length 2 or 3
* We place their leftmost & rightmost character indexes (in string s[]) on a linked-list
* After that, we extend the left && right indexes of each palindrome one-by-one, if s[left] == s[right].
* As a result, we only check palindromes by extending the length of previously identified palindromes,
*   instead of exhaustively checking for all palindromes of all lengths, in the whole string.
* When we find a maximum length that cannot be exceeded by further extension of a palindrome
*   (a.k.a prevmax == max), we terminate, and display the best palindrome candidate, if available.
*/


struct palin{
    int left;
    int right;
    bool final;
    struct palin *next;
};

struct palin *palin_create(int left, int right, bool final){
    struct palin *newpalin = malloc(sizeof(struct palin));
    newpalin->left=left;
    newpalin->right=right;
    newpalin->final=final;
    newpalin->next=NULL;
    return newpalin;
}

char * longestPalindrome(char * s){
    int i,len=strlen(s),max=0,prevmax=-1;
    struct palin *head=NULL, *tail,*trav,*candidate=NULL;
    for(i=0;i<len;i++){
        if(i+1 < len && s[i] == s[i+1]) {
            if(!head)   {head = tail = palin_create(i,i+1,false);}
            else        {tail->next = palin_create(i,i+1,false); tail = tail->next;}
            if(max<1){
                candidate = tail;
                max=1;
            }
        }
        if(i+2 < len && s[i] == s[i+2]) {
            if(!head)   {head = tail = palin_create(i,i+2,false);}
            else        {tail->next = palin_create(i,i+2,false); tail = tail->next;}
            if(max<2){
                candidate = tail;
                max=2;
            }
        }
    }

    while(max != prevmax){
        trav=head;
        prevmax = max;
        while(trav){
            if(!(trav->final) && trav->left>0 && (trav->right+1)<len){
                if(s[trav->left -1] == s[trav->right +1]){
                    trav->left--;
                    trav->right++;
                    if(trav->right - trav->left >max) {max=trav->right - trav->left; candidate = trav;}
                }
                else {trav->final = true;}
            }
            trav=trav->next;
        }
    }


    /*debug*/ /*
    tail=head;
    while(tail){
        printf("->[");
        for(i=tail->left;i <= tail->right;i++) {printf("%c",s[i]);}
        printf("]");
        tail=tail->next;
    }
    /*debug*/


    if(candidate){
        int canlen = candidate->right - candidate->left +1;
        char* result = malloc(sizeof(char)*(canlen+1));
        for(i=0;i<canlen;i++) {result[i] = s[candidate->left + i];}
        result[i] = NULL;
        return result;
    }
    else {
        char* result = malloc(sizeof(char)*2);
        result[0] = s[0];
        result[1] = NULL;
        return result;
    }
    return "abc";

}