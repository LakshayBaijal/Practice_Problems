class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
         int row = board.size();
         int col = board[0].size();

         vector<vector<int>> vis(row,vector<int>(col,0));

         for(int i = 0; i<row;i++)
         {
            for(int j = 0; j<col;j++)
            {
                if(i==0 || j == 0 || i == row - 1 || j == col - 1)
                {
                    if(board[i][j] == 'O' && vis[i][j] == 0)
                    {
                        function(vis,board,i,j);
                    }
                }
            }
         } 

         for(int i = 0; i<row;i++)
         {
            for(int j = 0; j<col; j++)
            {
                if(board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
         }  

         return; 
    }

    void function(vector<vector<int>>&vis,vector<vector<char>>&board,int i,int j)
    {
        int row = board.size();
        int col = board[0].size();

        if(i >= row || j >= col || i<0 || j<0)
        {
            return;
        }

        if(board[i][j] == 'X')
        {
            return;
        }
        if(vis[i][j] == 1)
        {
            return;
        }

        vis[i][j] = 1;
        function(vis,board,i-1,j);
        function(vis,board,i+1,j);
        function(vis,board,i,j-1);
        function(vis,board,i,j+1);
    }
};
