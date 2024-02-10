char findTheDifference(char * s, char * t){
    int l_s=strlen(s),l_t=strlen(t),i=0,j,found=0;

    if(!l_s)
        return t[0];
    
    while(i<l_s){
        for(j=0;j<l_t;j++){
            if(s[i] == t[j]){
                t[j]=NULL;
                if(++i >= l_s)
                    break;
                }
        }
    }
    for(i=0;i<l_t;i++){
        if(t[i])
            return t[i];
    }
    return NULL;
}