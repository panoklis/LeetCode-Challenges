char * toLowerCase(char * s){
    int i, len=strlen(s);
    for(i=0;i<len;i++) {
        if(s[i] < 91 && s[i] > 64)
            s[i] = s[i] + 32;
    }
    return s;
}