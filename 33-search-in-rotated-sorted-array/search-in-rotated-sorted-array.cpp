class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
    

        while(st <= end)
        {
            int mid = st + (end - st) / 2;
            
            if(nums[mid] == target)
            return mid;

            if(nums[0] <= nums[mid])
            {
                // left side sorted hai
                // agr left ki range me hai
                if(nums[st] <= target && target <= nums[mid]) // to left me hi hoga
                end = mid-1;
                else
                st = mid +1;
            }
            else
            {
                // right side sorted hoga
                // agr right ki range me hai
                if(nums[mid] <= target && target <= nums[end])
                st = mid + 1;
                else 
                end = mid -1 ;
            }
        }
        
        return -1;
    }
};