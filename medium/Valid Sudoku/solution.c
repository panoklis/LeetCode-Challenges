bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int seg1[9],seg2[9];
    int i,j,k,l,x;
    for(i=0;i<9;i++){seg1[i]=seg2[i]=0;}
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(board[i][j]!='.'){seg1[(int)(board[i][j])-49]++;}
            if(board[j][i]!='.'){seg2[(int)(board[j][i])-49]++;}
        }
        for(k=0;k<9;k++){
            if(seg1[k]>1 || seg2[k]>1) {return false;}
            seg1[k]=seg2[k]=0;
        }
    }
    for(x=0;x<9;x++){seg1[x]=0;}
    for(k=0;k<=6;k+=3){
        for(l=0;l<=6;l+=3){
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(board[i+k][j+l]!='.'){seg1[board[i+k][j+l]-49]++;}
                }
            }
            for(x=0;x<9;x++){
                if(seg1[x]>1) {return false;}
                seg1[x]=0;
            }
        }
    }
    return true;
}