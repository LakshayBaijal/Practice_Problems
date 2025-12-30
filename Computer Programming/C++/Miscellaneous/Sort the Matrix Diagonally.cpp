class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        unordered_map<int, priority_queue<int,vector<int>,greater<int>>> mp;

        int row = mat.size();
        int col = mat[0].size();

        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                int diff = i-j;
                mp[diff].push(mat[i][j]);
            }
        }
        vector<vector<int>>list(row,vector<int>(col));
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                int diff = i - j;
                list[i][j] = mp[diff].top();
                mp[diff].pop();
            }
        }

        return list;
    }
};
