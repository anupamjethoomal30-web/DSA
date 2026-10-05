class Solution {
public:
    int fun(int idx , bool buy , int transaction , vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
      if(transaction == 0)
      return 0;

      if(idx == prices.size())
      return 0;

      if(dp[idx][buy][transaction] != -1)
      return dp[idx][buy][transaction];
      
      if(buy)
      {
        return dp[idx][buy][transaction] = max(-prices[idx] + fun(idx+1,0,transaction,prices,dp) , fun(idx+1,1,transaction,prices,dp));
      }
      else
      {
        return dp[idx][buy][transaction] = max(prices[idx] + fun(idx+1,1,transaction-1,prices,dp) , fun(idx+1,0,transaction,prices,dp));
      }


    }


    int maxProfit(int k, vector<int>& prices) {
        int idx = 0;
        bool buy = 1;
        int transaction = k;
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(idx,buy,transaction,prices,dp);
    }
};