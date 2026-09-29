class Solution {
public:
    int fun(string &text1 , int n , string &text2, int m , vector<vector<int>>&dp)
    {
        if(n == 0 || m== 0)
        return dp[n][m] = 0;
        
        if(dp[n][m] != -1)
        return dp[n][m];

        if(text1[n-1] == text2[m-1])
        return dp[n][m] = 1 + fun(text1,n-1,text2,m-1,dp);

        else{
            return dp[n][m] = max(fun(text1,n-1,text2,m,dp),fun(text1,n,text2,m-1,dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(text1,n,text2,m,dp);
    }
};