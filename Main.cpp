#include"header_files.cpp"
#include"functions.cpp"
// Main Body of  Program
int main()
{
    int grid[size][size];
        if(!(input(grid) && assign(grid)))
            cout<<"\nInvalid Input"<<endl;
        else
        {
            cout<<"OUTPUT"<<endl;
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                    cout<<grid[i][j]<<" ";
                cout<<endl;
            }
        }
        return 0;
}
