int lengthOfLastWord(char * s){
 int i,wlen=0,len=strlen(s);
 for(i=len-1;i>=0;i--){
     if(s[i] != ' ')
        break;
 }
 for(i;i>=0;i--){
     if(s[i] == ' ')
        break;
    wlen++;
 }
 return wlen;
}