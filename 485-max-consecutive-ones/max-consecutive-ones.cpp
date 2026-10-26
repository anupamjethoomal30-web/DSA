class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        
        int ans = 0;

        for(int j = 0 ;j<n ;j++)
        {
            if(nums[j] == 0)
            i = j + 1;
            else
            ans = max(ans,j-i+1);
        }

        return ans;
    }
};