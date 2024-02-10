

char * mergeAlternately(char * word1, char * word2){
    int len1,len2,maxlen,i,j=0;
    char *output;
    len1=strlen(word1);
    len2=strlen(word2);
    output=malloc(sizeof(char)*(len1+len2+1));

    for(i=0;i<len1||i<len2;i++){
        if(i<len1){output[j] = word1[i]; j++;}
        if(i<len2){output[j] = word2[i]; j++;}
    }
    output[j]=NULL;
    return output;
}