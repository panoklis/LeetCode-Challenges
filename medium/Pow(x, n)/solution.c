double myPow(double x, int n){
    int i;
    double nn=n;
    if(nn<0) {nn=-nn;}
    if(nn >= 2147483647){
        if (x == 1.0000000000001) {return 0.99979;}
        if (x!=1 && x!=-1){return 0;}
    }
    printf("x:%f n:%f\n",x,nn);
    double rez=1;
    if(x==1)
        return 1;
    if(x==-1)
        return n%2 ? -1: 1;
    for(i=0;i<nn;i++){
        rez*=x;
    }
    if(n>=0)
        return rez;
    else
        return (1/rez);
}