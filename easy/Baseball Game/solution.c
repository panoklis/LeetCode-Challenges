int calPoints(char ** operations, int operationsSize){
    int i,g=0,sum=0;
    int *record=malloc(sizeof(int)*operationsSize);
    for(i=0;i<operationsSize;i++){
        if(!strcmp(operations[i],"D")){
            sum += record[g] = 2*record[g-1];
            g++;          
        }
        else if(!strcmp(operations[i],"C")){
            sum -= record[g-1];
            g--;
        }
        else if(!strcmp(operations[i],"+")){
            sum += record[g] = record[g-1]+record[g-2];
            g++;
        }
        else{
            sum += record[g] = atoi(operations[i]);
            g++;
        }
    }
    return sum;
}