int roman(char* chr){
    if (chr == 'I') {return 1;}
    if (chr == 'V') {return 5;}
    if (chr == 'X') {return 10;}
    if (chr == 'L') {return 50;}
    if (chr == 'C') {return 100;}
    if (chr == 'D') {return 500;}
    if (chr == 'M') {return 1000;}
    return 0;
}

int romanToInt(char * s){
    int i,temp,prev,sum=0,len=strlen(s);
    if(len == 1)
        return roman(*s);
    prev=roman(s[0]);
    for(i=1;i<len;i++){
        temp=roman(s[i]);
        if(temp<=prev)
            sum+=prev;
        else if(temp>prev)
            sum-=prev;
        prev=temp;
    }
    return sum+temp;
}