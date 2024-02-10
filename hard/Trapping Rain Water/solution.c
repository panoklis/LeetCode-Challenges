struct border{
    int lborder;
    int rborder;
};
//This struct keeps the height of the columns that act as a border for each column.
// '0' cannot be a height for a border, therefore it is used as an invalid border.
// The minimum of two borders defines the area that will fill with water, for each column.

int min(int a, int b){
    return a<b ? a : b;
}

int trap(int* height, int heightSize){
    int i,out=0,max;
    struct border* borders = malloc(sizeof(struct border)*heightSize);
    //Record borders of each column from the left
    max=0;
    for(i=0;i<heightSize;i++){
        if(height[i]>max) {
            max = height[i];
            borders[i].lborder = 0;
        }
        else {borders[i].lborder = max;}
    }
    //Record borders of each column from the right
    //At the same time, calculate & add the water that this column entraps,
    //  as the information of the two highest borders is now available for each column.
    max=0;
    for(i=heightSize-1;i>=0;i--){ 
        if(height[i]>max) {
            max = height[i];
            borders[i].rborder = 0;
        }
        else {borders[i].rborder = max;}

        if(borders[i].lborder && borders[i].rborder)
            out += min(borders[i].lborder,borders[i].rborder) - height[i];
    }
    return out;
}