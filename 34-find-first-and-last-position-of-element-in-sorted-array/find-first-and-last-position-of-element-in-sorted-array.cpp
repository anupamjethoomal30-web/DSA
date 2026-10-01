class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;

        int firstOcc = -1 , lastOcc = -1;
        
        int n = nums.size();
        int start = 0;
        int end = n-1;

        // first occ
        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(nums[mid] == target)
            {
                firstOcc = mid;
                end = mid-1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else
            {
                end = mid-1;
            }
        }


        // last Occ
         start = 0;
         end =  n-1;

        while(start <= end)
        {
            int mid = start + (end-start) / 2;

            if(nums[mid] == target)
            {
                lastOcc = mid;
                start = mid+1;
            }
            else if (nums[mid] < target) {
                start = mid + 1; 
            }
            else
            {
                end = mid - 1;
            }
        }

        ans.push_back(firstOcc);
        ans.push_back(lastOcc);
        
        return ans;
    }
};