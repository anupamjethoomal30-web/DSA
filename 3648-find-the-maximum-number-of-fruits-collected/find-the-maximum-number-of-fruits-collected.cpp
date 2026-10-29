class Solution {
public:
    int n ;
    
    int dfs1(int i , int j , vector<vector<int>>&fruits , vector<vector<int>>&dp)
    {  
        if(i == n && j == n)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = fruits[i][j] + dfs1(i+1,j+1,fruits,dp);
    }




    int dr2[3] = {1,1,1};
    int dc2[3] = {-1,0,1};

    int dfs2(int i , int j , vector<vector<int>>&fruits, vector<vector<int>>&dp)
    {
      
      if(i == n-1 && j == n-1)
      return 0;
      
      if(dp[i][j] != -1)
      return dp[i][j];

      int maxi = INT_MIN;
      
      for(int k = 0 ; k<3 ; k++)
      {
        int new_i = i + dr2[k];
        int new_j = j + dc2[k];

        if( (new_i < n && new_j < n && new_i < new_j) || (new_i == n-1 && new_j == n-1))
        {
            maxi = max(maxi, fruits[i][j] + dfs2(new_i , new_j , fruits ,dp));
        }
      }
 
      return dp[i][j] = maxi;
    }


    int dr3[3] = {-1,0,1};
    int dc3[3] = {1,1,1};

    int dfs3(int i , int j , vector<vector<int>>&fruits , vector<vector<int>>&dp)
    {
      
      if(i == n-1 && j == n-1)
      return 0;
      
      if(dp[i][j] != -1)
      return dp[i][j];

      int maxi = INT_MIN;
      
      for(int k = 0 ; k<3 ; k++)
      {
        int new_i = i + dr3[k];
        int new_j = j + dc3[k];

        if( (new_i < n && new_j < n && new_i > new_j) || (new_i == n-1 && new_j == n-1))
        {
            maxi = max(maxi, fruits[i][j] + dfs3(new_i , new_j , fruits ,dp));
        }
      }
 
      return dp[i][j] = maxi;
    }



    int maxCollectedFruits(vector<vector<int>>& fruits) {
        
        n = fruits.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        int child2 = dfs2(0,n-1,fruits,dp);
        int child3 = dfs3(n-1,0,fruits,dp);
        int child1 = dfs1(0,0,fruits,dp);  // isme to dp nhi lagaunga to bhi hojayga kyuki bs diagonal hi dekhna hai

        return child1 + child2 + child3;
    }
};