class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;

        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i<n-2 ; i++)
        {
            // to skip duplicate i
            if(i>0 && nums[i] == nums[i-1])
            continue;

            //two sum;
            int j = i+1;
            int k = n-1;

            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                

                // to skip duplicate j  
                while(j<k && nums[j] == nums[j+1])
                j++;
                
                // to skip duplicate k
                while(j<k && nums[k] == nums[k-1])
                k--;
                
                j++;
                k--;
                }
                
                else if(sum < 0)
                j++;
                else
                k--;
                
            }
        }
        return result;
    }
};