class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> vis(row,vector<int>(col,-1));
        int health = 0;

        int ans = function(dungeon,vis,row,col,0,0);    
        return ans;
    }

    int function(vector<vector<int>> &dungeon,vector<vector<int>> &vis, int row, int col, int i,int j)
    {
        if(i>=row || j>=col)
        {
            return INT_MAX;
        }

        if(i==row-1 && j==col-1)
        {
            return max(1,1-dungeon[i][j]);
        }

        if(vis[i][j] != -1)
        {
            return vis[i][j];
        }

        int right = function(dungeon,vis,row,col,i,j+1);
        int down = function(dungeon,vis,row,col,i+1,j);

        int health = min(right,down);
        
        int remaininghealth = health - dungeon[i][j];
        if(remaininghealth <= 0)
        {
            remaininghealth = 1;
        }
        vis[i][j] = remaininghealth;
        return vis[i][j];



    }
};
