class Solution {
public:
    
    bool fun(int index , vector<int>&nums , vector<int>&dp)
    {
        if(index >= nums.size()-1)
        return true;

        if(nums[index] == 0)
        return false;
        
        if(dp[index] != -1)
        return dp[index];

        for(int i = 1; i<=nums[index] ;i++)
        {
          if(fun(index + i , nums ,dp))
          return dp[index] = true;
        }

        return dp[index] = false;
    }

    bool canJump(vector<int>& nums) {
        
     int index =0;
     int n = nums.size();
     //index kaha tk jayga max -> 
     vector<int>dp(n,-1);
     return fun(index,nums,dp);

    }
};