class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();  // use 0 instead of row-1 for column size
        int minSum = INT_MAX;
        vector<vector<int>> vis(column, vector<int>(row, INT_MAX));  // [col][row] as per your usage

        for (int i = 0; i < column; i++) {
            int cost = function(matrix, vis, i, 0);
            if (minSum > cost) {
                minSum = cost;
            }
        }
        return minSum;
    }

    int function(vector<vector<int>>& matrix, vector<vector<int>>& vis, int i, int j) {
        int n = matrix.size();        // rows
        int m = matrix[0].size();     // columns

        if (i < 0 || i >= m) return INT_MAX;  // out of column bounds
        if (j >= n) return INT_MAX;           // out of row bounds

        if (vis[i][j] != INT_MAX) return vis[i][j];

        if (j == n - 1) return matrix[j][i];  // reached last row

        int mid = function(matrix, vis, i, j + 1);
        int left = function(matrix, vis, i - 1, j + 1);
        int right = function(matrix, vis, i + 1, j + 1);

        int minimum = min({mid, left, right});
        vis[i][j] = minimum + matrix[j][i];
        return vis[i][j];
    }
};
