char * tictactoe(int** moves, int movesSize, int* movesColSize){
    int i,j,movements,row1,row2,col1,col2,diag11,diag12,diag21,diag22;
    row1=row2=col1=col2=diag11=diag12=diag21=diag22=0;
    movements=9;
    char board[3][3], player='X',*a,*b,*draw,*pending;
    a=malloc(sizeof(char)*2);
    b=malloc(sizeof(char)*2);
    draw=malloc(sizeof(char)*5);
    pending=malloc(sizeof(char)*8);
    a="A";
    b="B";
    draw="Draw";
    pending="Pending";
    for(i=0;i<3;i++) {for(j=0;j<3;j++) {board[i][j]=' ';} }
    for(i=0;i<movesSize;i++){
        board[moves[i][0]][moves[i][1]] = player;
        if(player == 'X') {player = 'O'; movements--;}
        else              {player = 'X'; movements--;}
    }
    /*debug print*/
    //for(i=0;i<3;i++) {for(j=0;j<3;j++) {printf("%c ",board[i][j]);} printf("\n");}

    for(i=0;i<3;i++) {
        for(j=0;j<3;j++){
            if(i==j && board[i][j] == 'X')
                diag11++;
            if(i== 2-j && board[i][j] == 'X')
                diag12++;
            if(board[i][j] == 'X')
                row1++;
            if(board[j][i] == 'X')
                col1++;

            if(i==j && board[i][j] == 'O')
                diag21++;
            if(i==2-j && board[i][j] == 'O')
                diag22++;
            if(board[i][j] == 'O')
                row2++;
            if(board[j][i] == 'O')
                col2++;
        }
        if(row1 == 3 || col1 == 3)
            return a;
        if(row2 == 3 || col2 == 3)
            return b;
        col1=row1=col2=row2=0;
    }
    if (diag11 == 3 || diag12 == 3 )
        return a;
    if (diag21 == 3 || diag22 == 3 )
        return b;
    if(movements)
        return pending;
    return draw;
}