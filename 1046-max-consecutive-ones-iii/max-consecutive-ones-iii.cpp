class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0;
        int n = nums.size();
        int bestLen = 0;
        int zeros = 0;
        while(r<n)
        {
          
          if(nums[r] == 0)
          zeros++;

          while(zeros > k)
          {
            if(nums[l] == 0)
            zeros--;
          
            l++;
          }

          bestLen = max(bestLen,r-l+1);
          r++;

        }


        return bestLen;
    }
};