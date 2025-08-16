class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();

        int col = matrix[0].size();

        int indexrow = 0;
        int left = 0;
        int right = row-1;

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(matrix[mid][0] == target)
            {
                return true;
            }
            if(matrix[mid][0] > target)
            {
                right = mid - 1;
                
            }
            if(matrix[mid][0] < target)
            {
                left = mid + 1;
            }
        }
        indexrow = left;
        
        if (matrix[indexrow][0] > target) indexrow--;   
        if (indexrow < 0) return false;

        left = 0;
        right = col-1;
        while(left <= right)
        {
            int mid = (left + right)/2; 
            if(matrix[indexrow][mid] == target)
            {
                return true;
            }

            if(matrix[indexrow][mid] < target)
            {
                left = mid + 1;
            }
            if(matrix[indexrow][mid] > target)
            {
                right = mid - 1;
            }
        }

        return false;


    }
};
