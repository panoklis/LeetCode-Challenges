char * longestCommonPrefix(char ** strs, int strsSize){
    int max=strlen(strs[0]),i,j;
    for(i=1;i<strsSize;i++){
        for(j=0;j<strlen(strs[i]) && j<max;j++){
            if(strs[i][j] != strs[0][j]) {break;}
        }
        max=j;
    }
    char* result = malloc(sizeof(char)*(max+1));
    for(i=0;i<max;i++){result[i] = strs[0][i];}
    result[i] = NULL;
    return result;
}