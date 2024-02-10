bool isRobotBounded(char * instructions){

    /*
    * If robot returns to (0,0), it always runs in circles.
    *   After first movement ::
    * If robot is facing south, it always returns to (0,0), after one run (moves -x -y).
    * If robot is facing east or west, it always returns to (0,0) after 3 runs.
    * If robot is facing north and is not at (0,0), it goes on forever.
    *   ^ This is the only condition that is checked after the 1st run.
    */
    int orientation=0,x=0,y=0,i,len=strlen(instructions);
    for(i=0;i<len;i++){
        if(instructions[i] == 'L')
            orientation--;
        else if(instructions[i] == 'R')
            orientation++;
        else if(instructions[i] == 'G'){
            if(orientation % 4 == -1 || orientation % 4 == 3)
                x--;
            else if(orientation % 4 == 1 || orientation % 4 == -3)
                x++;
            else if(orientation % 4 == 0)
                y++;
            else if(orientation % 4 == 2 || orientation % 4 == -2)
                y--;
        }
    }
    if((x!=0 || y!=0) && orientation%4 == 0)
        return false;
    return true;
}