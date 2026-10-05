class Solution {
public:
    
    int fun(int idx , int m , int n , vector<pair<int,int>>&count , vector<vector<vector<int>>>&dp)
    {
        if(idx == count.size())
        return 0;
        
        if(m == 0 && n == 0)
        return 0;
        
        if(dp[idx][m][n] != -1)
        return dp[idx][m][n];

        int take = 0;
        if(count[idx].first <= m && count[idx].second <= n)
        take = 1 + fun(idx+1,m-count[idx].first , n - count[idx].second , count ,dp);

        int skip = fun(idx + 1 , m , n , count , dp);

        return dp[idx][m][n] = max(take , skip);

    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int size = strs.size();
        vector<pair<int,int>>count(size);

        for(int i= 0; i<size; i++)
        {    
            int cntZero = 0;
            int cntOne = 0;
            for(char ch : strs[i])
          {
            if(ch == '0')
            cntZero++;
            else
            cntOne++;
          }
            
            count[i] = {cntZero,cntOne};
        }


        int idx =0;
        
        // same as knapsack dp -> take or skip
        vector<vector<vector<int>>>dp(size+1 , vector<vector<int>>(m+1 , vector<int>(n+1,-1)));
        return fun(idx,m,n,count,dp);

    }
};