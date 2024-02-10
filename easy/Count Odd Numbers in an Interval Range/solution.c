

int countOdds(int low, int high){
    return (high-low)<0 ? 0 : (high-low)/2+((high%2)|(low%2));
}