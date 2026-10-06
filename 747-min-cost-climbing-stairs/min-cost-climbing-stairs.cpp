class Solution {
public:
    int fun(int idx , vector<int>&cost , vector<int>&dp )
    {
        if(idx >= cost.size())
        return 0;
        
        if(dp[idx] != -1)
        return dp[idx];

        return dp[idx] = min(cost[idx] + fun(idx+1,cost , dp) ,cost[idx] + fun(idx+2,cost , dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+2,-1);
        return min(fun(0,cost,dp) , fun(1,cost,dp));
    }
};