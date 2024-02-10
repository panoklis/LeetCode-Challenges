int lengthOfLongestSubstring(char * s){
    int len = strlen(s),i,j,j_t=0,cnt=0,largest=0;
    char temp;
    for(i=0;i<len;i++){
        temp = s[i];
        cnt++;
        for(j=j_t;j<i;j++){
            if(s[j] == temp){
                if(largest<cnt-1)
                    largest=cnt-1;
                cnt = i-j;
                j_t = j+1;
                break;
            }
        }
    }
    if(cnt>largest)
        return cnt;
    else
        return largest;
}