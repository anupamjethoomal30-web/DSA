class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
         
        // 1 se n tk ke nums ko unki sahi index me le jao;
        // 1->idx 0
        // 2-> idx 1
        for(int i = 0 ; i<n ;i++)
        {
            while(nums[i] >= 1 && nums[i] <=n && nums[nums[i]-1] != nums[i])
            {
                swap(nums[nums[i]-1],nums[i]);
            }
        }

        // check which is not in it's correct position

        for(int i = 0; i<n ;i++)
        {
            if(nums[i] != i+1)
            return i+1;
        }

        return n+1;
    }
};