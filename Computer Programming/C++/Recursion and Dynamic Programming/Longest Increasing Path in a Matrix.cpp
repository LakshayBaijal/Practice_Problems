class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> vis(row,vector<int>(col,-1));
        int ans=0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                int temp = function(matrix,vis,i,j);
                ans = max(ans,temp);
            }
        }

        return ans;
    }

    int function(vector<vector<int>>&matrix,vector<vector<int>>&vis,int i,int j)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int best = 1;

        if(vis[i][j] != -1)
        {
            return vis[i][j];
        }
        if(i>0)
        {
            if(matrix[i-1][j] > matrix[i][j])
            {
                best = max(best,1 + function(matrix,vis,i-1,j)) ;
            }
        }
        if(i<row-1)
        {
            if(matrix[i+1][j] > matrix[i][j])
            {
                best = max(best,1 + function(matrix,vis,i+1,j));
            }
        }

        if(j>0)
        {
            if(matrix[i][j-1] > matrix[i][j])
            {
                best = max(best,1 + function(matrix,vis,i,j-1));
            }
        }
        if(j<col - 1)
        {
            if(matrix[i][j+1] > matrix[i][j])
            {
                best = max(best,1 + function(matrix,vis,i,j+1));
            }
        }
        
        vis[i][j] = best;

        return vis[i][j];
    }

};
