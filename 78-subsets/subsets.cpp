class Solution {
public:
    void fun(int idx, vector<int>&nums, int n ,vector<int>&temp, vector<vector<int>>&result)
    {
      if(idx == n)
      {
        result.push_back(temp);
        return;
      }

      temp.push_back(nums[idx]);
      fun(idx+1,nums,n,temp,result);
      temp.pop_back();
      fun(idx+1,nums,n,temp,result);
    }
 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        int n = nums.size();
        int idx = 0;
        vector<int>temp;
        fun(idx,nums,n,temp,result);
        return result;
    }
};