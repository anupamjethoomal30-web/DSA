class Solution {
public:
    
    int fun(vector<int>&coins , int index ,int amount ,vector<vector<int>>&dp)
    {
      
      if(amount == 0)
      return 0;

      if(index == 0)
      return 1e7;
      
      if(dp[index][amount] != -1)
      return dp[index][amount];

      int nottake = fun(coins , index-1 , amount ,dp);
      
      int take = 1e7;
      if(coins[index-1] <= amount)
      {
        take = 1 + fun(coins,index,amount-coins[index-1],dp);
      }
      
      return dp[index][amount] = min(take , nottake);
    }


    int coinChange(vector<int>& coins, int amount) {
        
        int index = coins.size();
        int steps = 0;  // number of coins
        vector<vector<int>>dp(index+1,vector<int>(amount+1,-1));
        int ans = fun(coins,index,amount,dp);

        return ans < 1e7 ? ans : -1;
    }
};