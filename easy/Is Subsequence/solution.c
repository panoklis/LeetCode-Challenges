bool isSubsequence(char * s, char * t){
    int i=0,j=0,len_s=strlen(s),len_t=strlen(t);
    if(!len_s) {return true;}
    if(!len_t) {return false;}
    for(j;j<len_t;j++){
        if(s[i]==t[j]){i++;if (i==len_s) {return true;}}
    }
    return false;
}