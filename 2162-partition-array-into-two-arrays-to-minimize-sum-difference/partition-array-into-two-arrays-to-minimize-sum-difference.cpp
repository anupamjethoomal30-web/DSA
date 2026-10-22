class Solution {
public:
    void gen(int idx , int n , int offset ,int count , int sum, vector<int>&nums , vector<vector<int>>&map)
    {   
        if(idx == n)
        {
            map[count].push_back(sum);
            return;
        }
    
        gen(idx + 1, n, offset , count + 1 , sum + nums[idx + offset] , nums, map);
        gen(idx + 1 ,n ,offset , count , sum , nums , map);

    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        int S = accumulate(nums.begin(),nums.end(),0);
        
        vector<vector<int>> L(n+1) , R(n+1);
        
        gen(0,n,0,0,0,nums,L);  // L
        gen(0,n,n,0,0,nums,R);    // R

        int ans = INT_MAX;

        for(int k = 0 ; k<=n ; k++)
        sort(R[k].begin(),R[k].end());

        for(int k = 0; k<= n ;k++)
        {   
            // abhi me k size wale L subset sums dekh ra hu
            for(auto x : L[k])
            { 
              int need = (S - 2 * x) / 2;
              
              // yaha andar mujhe n-k size wale R subset sums dekhne honge

              int low = lower_bound(R[n-k].begin(),R[n-k].end(),need) - R[n-k].begin();
            
              if(low < R[n-k].size())
              ans = min(ans , abs(2*(x + R[n-k][low]) - S ));
              
              if(low - 1 >= 0)
              ans = min(ans , abs(2*(x + R[n-k][low-1]) - S));
            }
        }
        
        return ans;
    }
};