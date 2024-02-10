

double champagneTower(int poured, int query_row, int query_glass){
    int i,j,transfer;
    if(!poured) {return (double)(0);}
    double a,b,**glass=malloc(sizeof(double*)*(100));
    for(i=0;i<100;i++){glass[i]=malloc(sizeof(double)*(i+1));}
    for(i=0;i<=query_row;i++){
        if(!i) {glass[0][0] = poured;}
        else{
            transfer=0;
            for(j=0;j<i+1;j++){
                    if(j>0 && glass[i-1][j-1]>1) {a=(glass[i-1][j-1]-1)/2; transfer=1;}
                    else {a=0;}
                    if(j<i && glass[i-1][j]>1) {b=(glass[i-1][j]-1)/2; transfer=1;}
                    else {b=0;}
                    glass[i][j]=a+b;
                }
            for(j=0;j<i;j++) {if(glass[i-1][j]>1){glass[i-1][j]=1;}}
            if(!transfer){break;}
        }
    }
    if(transfer) {printf("i:%d\n",i);for(j=0;j<i;j++) {if(glass[i-1][j]>1){glass[i-1][j]=1;} } }
    else {return (double)(0);}

    /*debug
    for(int i=0;i<=query_row;i++){
        for(j=0;j<i+1;j++){
            printf("%f ",glass[i][j]);
        }
        printf("\n");
    }
    debug*/

    return glass[query_row][query_glass];
}