class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int firstOcc = -1, lastOcc = -1;
        int n = nums.size();
        int st = 0;
        int end = n-1;

        while(st <= end)
        {
            int mid = st + (end - st) / 2;

            if(target < nums[mid])
            {
                end = mid -1;
            }
            else if(nums[mid] == target)
            {
                firstOcc = mid;
                end = mid-1;
            }
            else
            {
                st = mid + 1;
            }
        }

        if(firstOcc == -1)
        return vector<int>{};

        st = 0;
        end = n-1;

        while(st <= end)
        {
            int mid = st + (end - st) / 2;

            if(nums[mid] < target)
            {
                st = mid + 1;
            }
            else if(nums[mid] == target)
            {
                lastOcc = mid;
                st = mid +1 ;
            }
            else{
                end = mid -1;
            }
        }
        
        if(firstOcc == lastOcc)
        return vector<int>{firstOcc};
        else
        {
            vector<int>ans;
            for(int i = firstOcc ; i<= lastOcc ; i++)
            ans.push_back(i);

            return ans;
        }
    }
};