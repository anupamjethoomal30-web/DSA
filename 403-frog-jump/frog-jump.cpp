class Solution {
public:
    bool fun(int index , int k , vector<int>&stones , unordered_set<int>&st , vector<vector<int>>&dp)
    {
      if(index == stones.size() - 1)
      return true;
      

      if(dp[index][k] != -1)
      return dp[index][k];


      int pos = stones[index];

      bool left = false , mid = false , right = false;

      if(k-1 > 0 && st.count(pos + k - 1)){
       
       int newPos = pos + k - 1;
       // find index of newPos;
       int newPosIdx = lower_bound(stones.begin(),stones.end(),newPos) - stones.begin();

       left = fun(newPosIdx,k-1,stones,st, dp);

      }

      if(k != 0 && st.count(pos + k))
      {
       int newPos = pos + k ;
       // find index of newPos;
       int newPosIdx = lower_bound(stones.begin(),stones.end(),newPos) - stones.begin();

       mid = fun(newPosIdx,k,stones,st ,dp); 
      }
      
      if(st.count(pos + k + 1))
      {
        int newPos = pos + k + 1;
       // find index of newPos;
       int newPosIdx = lower_bound(stones.begin(),stones.end(),newPos) - stones.begin();

       right = fun(newPosIdx,k+1,stones,st ,dp);
      }


      return dp[index][k] = left || mid || right;

    }

    bool canCross(vector<int>& stones) {
        int index = 0 , n = stones.size();
        int k = 0 ; // last jump;
        unordered_set<int>st(stones.begin(),stones.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));  // idx ,k
        return fun(index,k,stones,st,dp);
    }
};