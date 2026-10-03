class Solution {
public:
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int st = 0; int end = m*n - 1; 
        
        while(st <= end)
        {
            int mid = st + (end - st) /2;
            
            int row_idx = mid / n;
            int col_idx = mid % n;

            if(matrix[row_idx][col_idx] == target)
            return true;

            else if(matrix[row_idx][col_idx] < target)
            st = mid+1;
            
            else
            end = mid-1;
        }

        return false;
    }
};