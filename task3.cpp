#include<iostream>
using namespace std;
#define N 9 //SIZE OF SUDOKU GRID

//FUNCTION TO PRINT SUDOKU GRID
void printGrid(int grid[N][N]){
    for (int row=0;row<N;row++){
        for(int col=0;col<N;col++) cout<<grid[row][col]<<"";
        cout<<endl;
    }
}

    //NOW TO CHECK IF A GIVEN NUMBER CAN BE PLACED IN A GIVEN ROW, COLUMN,AND 3 BY 3 BOX
    bool isSafe(int grid[N][N],int row,int col,int num){

        // NOW CHECK ROW
        for(int p=0;p<N;p++)
        if(grid[row][p]==num)
        return false;

        //NOW CHECK COLUMN
        for(int p=0;p<N;p++)
        if(grid[p][col]==num)
        return false;

        //CHECK 3 BY 3 SUBGRID
        int startrow=row-row % 3;
        int startcol=col-col % 3;

        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if (grid[i+startrow][j+startcol]== num)
        return false;
        return true;
    }

    // SOLVE SUDOKU USING BACKTRACING 
    bool solvesudoku(int grid[N][N]) {
        int row,col;
        bool emptycell=false;

        //NOW FIND THE EMPTY CELL
        for(row=0;row<N;row++){
            for(col=0;col<N;col++){
                if(grid[row][col]==0){
                    emptycell=true;
                    break;
                }
            }
            if(emptycell)break;
        }
        
        // IF THERE IS NO ANY EMPTY CELL, PUZZLE IS SOLVED
        if(!emptycell)return true;

        //TRY PLACING NUMBERS 1 TO 9
        for(int num=1;num<=9;num++){
            if(isSafe(grid,row,col,num)){
                grid[row][col]=num;

                if(solvesudoku(grid))
                return true;

                //UNDO MOVE(BACKTRACK)
                grid[row][col]=0;
            }
        }

        return false; //TRIGGER BACKTRACING
    }

    int main(){
        int grid[N][N]={
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };

        if(solvesudoku(grid))
        printGrid(grid);
        else
        cout<<"no solution found";
        return 0;
    }
    
            

         
        
    


    
            
        
    
