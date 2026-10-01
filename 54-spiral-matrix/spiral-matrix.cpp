class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        int n = matrix.size();
        int m = matrix[0].size();
        int row_s = 0;
        int row_e = n-1;
        int col_s = 0;
        int col_e = m-1;

        while(row_s <= row_e && col_s <= col_e)
        {
         
         // first row
         for(int j = col_s ; j<= col_e ; j++)
         result.push_back(matrix[row_s][j]);

         row_s++;

         // last col
         
         for(int i = row_s ; i<= row_e ; i++)
         result.push_back(matrix[i][col_e]);

         col_e--;
         

         // last row -> reverse order
         if(row_s <= row_e){
         for(int j = col_e ; j>= col_s ; j--)
         result.push_back(matrix[row_e][j]);

         row_e--;
         }

         // first col -> reverse order
         if(col_s <= col_e){
         for(int i = row_e ; i>= row_s ; i--)
         result.push_back(matrix[i][col_s]);

         col_s++;
         }

        }
        
        return result;
    }
};