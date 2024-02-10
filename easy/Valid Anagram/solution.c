bool isAnagram(char * s, char * t){
    int i=0,j,l_s=strlen(s),l_t=strlen(t);
    if(l_s != l_t)
        return false;
    int ABC[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (i=0;i<l_s;i++){
        ABC[s[i] - 'a']++;
        ABC[t[i] - 'a']--;
    }
    for (i=0;i<26;i++)
        if(ABC[i]) {return false;}

    return true;

}