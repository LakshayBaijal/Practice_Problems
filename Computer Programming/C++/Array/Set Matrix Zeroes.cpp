class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<pair<int,int>> pairs;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(matrix[i][j] == 0)
                {
                    pairs.push_back({i,j});
                }
            }
        }    

        for (auto &it : pairs)
        {
            int i = it.first;
            int j = it.second;

            for(int k = 0;k<row;k++)
            {
                matrix[k][j] = 0;
            }
            for(int k = 0;k<col;k++)
            {
                matrix[i][k] = 0;
            }
        }

        return;
    }
};
