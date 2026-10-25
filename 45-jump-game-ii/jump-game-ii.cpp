class Solution {
public:
    int fun(int index , vector<int>&nums , vector<int>&dp)
    {
        if(index >= nums.size()-1)
        return 0;
        
        if(dp[index] != -1)
        return dp[index];

        int mini = 1e7;
        for(int i = 1 ; i<= nums[index] ; i++)
        {
            mini = min(mini, 1 + fun(index + i , nums ,dp));
        }
        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        vector<int>dp(n,-1);
        return fun(index,nums,dp);
    }
};