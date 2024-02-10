int myAtoi(char * s){
    int j,i=0,len=strlen(s),mul=1;
    long rez=0;
    while(s[i] == ' '){i++;}
    if(s[i] == '-') {mul=-1; i++;}
    else if(s[i] == '+') {i++;}
    for(i;i<len;i++){
        if(s[i] > '9' || s[i] < '0') {break;}
        if(rez*10 + (s[i] - 48) >= 2147483648) {
            if(mul == -1) {return -2147483648;}
            else {return 2147483647;}
        }
        rez*=10;
        rez+=s[i]-48;
    }
    return (int) rez*mul;
}