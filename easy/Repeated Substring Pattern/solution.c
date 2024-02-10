bool repeatedSubstringPattern(char * s){
    int i,j=0,k,len=strlen(s),s_len;
    char *sub = malloc(sizeof(char)*(len+1));
    for(i=0;i<len+1;i++) {sub[i]=(char)0;}
    for(i=0;i<len/2;i++){
        sub[j]=s[i];
        j++;
        s_len = j;
        if(!(len % s_len)){
            j=0;
            for(k=0;k<len;k++){
                sub[k]=sub[j];
                j++;
                if(j == s_len) {j=0;}
            }
            //printf("gonna compare %s : %s\n",s,sub);
            if(!strcmp(s,sub))
                return true;
            for(k=s_len;k<len+1;k++) {sub[k]=(char)0;}
            j=s_len;
        }
    }
    return false;
}