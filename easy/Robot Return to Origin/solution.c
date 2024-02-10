bool judgeCircle(char * moves){
    int x=0,y=0,i,len=strlen(moves);
    for(i=0;i<len;i++){
        if(moves[i] == 'U')
            y++;
        if(moves[i] == 'D')
            y--;
        if(moves[i] == 'R')
            x++;
        if(moves[i] == 'L')
            x--;
    }
    if(!y && !x)
        return true;
    return false;
}