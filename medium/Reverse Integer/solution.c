int reverse(int x){
    long i=1,y=x,rez=0;
    if(x<0) {y*=-1;}
    while(y/i) {rez*=10; rez += y%10; y/=10;}
    if (rez >= 2147483648) {return 0;}
    if(x<0) {rez*=-1;}
    return (int) rez;
}