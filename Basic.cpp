#include<iostream>
#define size 9
#define mini 3
using namespace std;

//========= Is Row OK =========//
// Checks and returns whether it's legal
// to put 'val' in A specific row.
int check_row(int row[], int col, int value)
{
    for(int i = 0; i < size; i++)
        if(i != col && row[i] == value)
            return 0;       // Found the same value again!
    return 1;
}

//========= Is Column OK =========//
// Checks and returns whether it's legal
// to put 'val' in A specific column.
int check_col(int grid[][size], int row, int col, int value)
{
    for(int i = 0; i < size; i++)
        if(i != row && grid[i][col] == value)
            return 0;       // Found the same value again!
    return 1;
}

int check_square(int grid[][size],int row,int col,int value)
{
    int row_corner=(row/mini)*mini, col_corner=(col/mini)*mini;
    for(int i=row_corner;i<(row_corner+mini);i++)
        for(int j=col_corner;j<(col_corner+mini);j++)
            if((i!=row || j!=col) && grid[i][j]==value)
                return 0;
    return 1;
}

int valid(int grid[][size],int row,int col,int value)
{
    if(check_row(grid[row],col,value) && check_col(grid,row,col,value) && check_square(grid,row,col,value))
        return 1;
    return 0;
}

int assign(int grid[][size], int row=0, int col=0)
{
    int next_row,next_col;
    if(col == size-1)
            next_row=row+1;
        else
            next_row=row;
        next_col=(col+1)%9;
    if(row==size)
        return 1;
    else if(grid[row][col]!=0)
        assign(grid,next_row,next_col);
    else
    {
        for(int value=1;value<=size;value++)
        {
            grid[row][col]=value;
            if(valid(grid,row,col,value) && assign(grid,next_row,next_col)) //to be tested
                return 1;
            grid[row][col]=0;
        }
        return 0;
    }
}

int main()
{
    int grid[size][size]={{0}};
    cout<<"Enter the numbers"<<endl;
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            cin>>grid[i][j];

        if(assign(grid))
        {
            cout<<"OUTPUT"<<endl;
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                    cout<<grid[i][j]<<" ";
                cout<<endl;
            }
        }
        else
            cout<<"Error"<<endl;
        return 0;
}
