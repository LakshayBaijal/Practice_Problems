class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> timevec(row,vector<int>(col,INT_MAX));
        int time = 0;
        for(int i = 0; i < row ; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 2)
                {
                    function(grid,timevec,i,j,time);
                }
            }
        }

        int maximum = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1 && timevec[i][j] == INT_MAX) {
                    return -1;
                }
                if(timevec[i][j] != INT_MAX) {
                    maximum = max(maximum, timevec[i][j]);
                }
            }
        }

        return maximum;
    }


    void function(vector<vector<int>>&grid,vector<vector<int>>&timevec,int i ,int j,int time)
    {
        int row = grid.size();
        int col = grid[0].size();

        if(i<0 || j<0 || i>=row || j>=col)
        {
            return;
        }
        if(grid[i][j] == 0 || timevec[i][j] <= time)
        {
            return;
        }

        timevec[i][j] = time;

        function(grid,timevec,i,j-1,time+1);
        function(grid,timevec,i,j+1,time+1);
        function(grid,timevec,i-1,j,time+1);
        function(grid,timevec,i+1,j,time+1);
    }
};
