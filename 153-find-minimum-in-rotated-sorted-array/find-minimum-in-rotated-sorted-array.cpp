class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;
        
        int ans = -1;
        while(st <= end)
        {
            int mid = st + (end - st) /2 ;

            if(nums[0] <= nums[mid])
            {
                // left side sorted hai 
                // min element right side me hi hoga
                st = mid + 1;
            }
            else
            {
                // right side sorted hai 
                // right side increase hoga to minimum left trf hi hoga
                ans = nums[mid];
                end = mid-1; 
            }
        }
        
        // ans == -1 mtlb rotate hi nhi hua hai
        return ans == -1 ? nums[0] : ans;
    }
};