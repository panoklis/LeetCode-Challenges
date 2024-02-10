/*
* Opening & Closing position is kept for every depth-level of parentheses.
* Opening is kept once, closing is kept always, as long as the depth hasn't dropped.
* Max valid length is kept on each close.
* Each level's opening position is removed, when that depth-level decreases.
*/

int longestValidParentheses(char * s){
    int i,j,max=0,zeroflag=0,k=0,*open,*close,len=strlen(s);
    open=malloc(sizeof(int)*(30000));
    close=malloc(sizeof(int)*(30000));
    for(i=0;i<30000;i++) {open[i]=-1;close[i]=-1;}
    for(i=0;i<len;i++){
        if(zeroflag){
            j=0;
            while(open[j] != -1)
                open[j++] = -1;
            zeroflag=0;
        }
        if(s[i] == '(') {if(open[k] == -1){open[k]=i;}k++;}
        else if(s[i] == ')' && k>0) {
            for(j=k;open[j]!=-1;j++)
                open[j] = -1;
            k--;
            close[k]=i;
            if(open[k]!=-1 && close[k]!=-1 && (close[k]-open[k])>max)
                max = close[k]-open[k]+1;
        }
        else {zeroflag=1;}
    }
    return max;
}