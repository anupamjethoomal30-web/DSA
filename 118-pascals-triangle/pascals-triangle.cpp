class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return {};

        vector<vector<int>> ans(numRows);

        ans[0] = {1};

        if(numRows == 1)
            return ans;

        ans[1] = {1, 1};

        int n = numRows;
        for(int i = 2 ; i<n ; i++)
        {
            vector<int>temp;

            for(int j = 0 ; j<= i ;j++)
            {
                if(j == 0 || j == i)
                temp.push_back(1);
                else
                {
                    int num = ans[i-1][j-1] + ans[i-1][j];
                    temp.push_back(num);
                }
            }

            ans[i] = temp;
        }


        return ans;
    }
};