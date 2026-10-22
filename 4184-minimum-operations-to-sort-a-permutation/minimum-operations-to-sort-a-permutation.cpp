class Solution {
public:
    int minOperations(vector<int>& nums) {

     int idx = -1;
     int n = nums.size();

     if(n == 1)
     return 0;

     bool incr = true;
      
     for(int i = 0 ; i<n-1 ; i++)
     {
        if(nums[i] == 0)
        idx = i;
        if(nums[i+1] == 0)
        idx = i+1;

        if(nums[i+1] == (nums[i] + 1) % n)
        continue;
        else{
            incr = false;
            break;
        }
     }

     if(incr)
     {
        return min(idx , n-idx + 2);
     }

     
     idx = -1;

     bool decr = true;

     for(int i = 0 ; i<n-1 ; i++)
     {
        if(nums[i] == 0)
        idx = i;
        if(nums[i+1] == 0)
        idx == i+1;

        if(nums[i] == (nums[i+1] + 1) % n)
        continue;
        else{
            decr = false;
            break;
        }
     }

     if(decr)
     {
        return min(idx + 2 , n - idx);
     }
    

     return -1;
    }
};