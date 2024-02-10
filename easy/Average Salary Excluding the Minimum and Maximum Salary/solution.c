double average(int* salary, int salarySize){
    double sum=0,min=1000001,max=999;
    int i,min_i,max_i;
    if(!salarySize) {return 0;}
    for(i=0;i<salarySize;i++){
        sum+=(double)(salary[i]);
        if(salary[i]<min) {min=salary[i];min_i=i;}
        if(salary[i]>max) {max=salary[i];max_i=i;}
    }
    if(min_i == max_i) {return (sum-max)/(salarySize-1);}
    else               {return (sum-min-max)/(salarySize-2);}
}