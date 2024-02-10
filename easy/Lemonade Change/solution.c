bool lemonadeChange(int* bills, int billsSize){
    int i,fives,tens;
    fives=tens=0;
    for(i=0;i<billsSize;i++){
        if(bills[i]==5){fives++;}
        else if(bills[i]==10){
            tens++;
            if(fives){fives--;}
            else     {return false;}
        }
        else if(bills[i]==20){
            if(fives && tens){fives--;tens--;}
            else if(fives>=3){fives-=3;}
            else             {return false;}
        }
    }
    return true;
}