int strStr(char * haystack, char * needle){
    int len=strlen(haystack),i,j=0,first;
    for(i=0;i<len;i++){
        if(haystack[i]==needle[j]){
            if(!j)
                first=i;
            j++;
            if(!needle[j])
                return first;
        }
        else if(j) {i-=j; j=0;}
    }
    return -1;
}