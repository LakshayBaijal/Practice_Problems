By memo + dp

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<long long>> maxDP(row, vector<long long>(col, LLONG_MIN));
        vector<vector<long long>> minDP(row, vector<long long>(col, LLONG_MAX));

        function(grid, maxDP, minDP, row - 1, col - 1);

        long long ans = maxDP[row - 1][col - 1];
        if(ans<0)
        {
            return -1;
        }
        return ans;    
    }

    void function(vector<vector<int>>&grid,vector<vector<long long>>&maxDP,vector<vector<long long>>&minDP,int i,int j)
    {
        int row = grid.size();
        int col = grid[0].size();

        if(i == 0 && j == 0)
        {
            maxDP[0][0] = grid[0][0];
            minDP[0][0] = grid[0][0];
            return;
        }

        if (maxDP[i][j] != LLONG_MIN && minDP[i][j] != LLONG_MAX)
        {
            return;
        }
        long long curr = grid[i][j];
        long long maxVal = LLONG_MIN;
        long long minVal = LLONG_MAX;

        if(i>0)
        {
            if(maxDP[i-1][j] == LLONG_MIN)
            function(grid, maxDP, minDP, i - 1, j);

            long long temp_min = min(curr*maxDP[i-1][j],curr*minDP[i-1][j]);
            long long temp_max = max(curr*maxDP[i-1][j],curr*minDP[i-1][j]);

            maxVal = max(maxVal, temp_max);
            minVal = min(minVal, temp_min);
        }

        if(j>0)
        {
            if(maxDP[i][j-1] == LLONG_MIN)
            function(grid, maxDP, minDP, i, j - 1);

            long long temp_min = min(curr*maxDP[i][j-1],curr*minDP[i][j-1]);
            long long temp_max = max(curr*maxDP[i][j-1],curr*minDP[i][j-1]);

            maxVal = max(maxVal, temp_max);
            minVal = min(minVal, temp_min);
        }

        maxDP[i][j] = maxVal;
        minDP[i][j] = minVal;

        return;
    }
};

By Top Down Approach

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<long long>> dpmax(row,vector<long long>(col,LLONG_MIN));
        vector<vector<long long>> dpmin(row,vector<long long>(col,LLONG_MAX));


        dpmax[0][0] = grid[0][0];
        dpmin[0][0] = grid[0][0];  


        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {

                if(i == 0 && j == 0)
                {
                    continue;
                }
                long long mintemp = LLONG_MAX;
                long long maxtemp = LLONG_MIN;
                
                if(i>0)
                {
                    long long a = max(dpmax[i-1][j] * grid[i][j],dpmin[i-1][j] * grid[i][j]);
                    maxtemp = max(maxtemp,a);

                    long long b = min(dpmax[i-1][j] * grid[i][j],dpmin[i-1][j] * grid[i][j]);
                    mintemp = min(mintemp,b);
                }

                if(j>0)
                {
                    long long a = max(dpmax[i][j-1] * grid[i][j],dpmin[i][j-1] * grid[i][j]);
                    maxtemp = max(maxtemp,a);

                    long long b = min(dpmax[i][j-1] * grid[i][j],dpmin[i][j-1] * grid[i][j]);
                    mintemp = min(mintemp,b);
                }

                dpmax[i][j] = maxtemp;
                dpmin[i][j] = mintemp;
            }
        }

        long long ans = dpmax[row - 1][col - 1];
        const int MOD = 1e9 + 7;

        if (ans < 0) return -1;
        return ans % MOD; 

    }
};
