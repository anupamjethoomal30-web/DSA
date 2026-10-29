class Solution {
public:
    int n,m;

//    int fun(int i , int j , vector<vector<int>>&dungeon , vector<vector<int>>&dp)
//    {
//      if(i >= m || j>= n)
//      return INT_MAX;
     
//      if(i == m-1 && j == n-1)
//      {
//         if(dungeon[m-1][n-1] <= 0)
//         return dp[i][j] =  abs(dungeon[m-1][n-1]) + 1;
//         else 
//         return dp[i][j] =  1;
//      }

//      if(dp[i][j] != -1)
//      return dp[i][j];

//     int down = fun(i+1,j,dungeon,dp);
//     int right = fun(i,j+1,dungeon,dp);

//     int need = min(down,right);

//     if(dungeon[i][j] >= need)
//     return dp[i][j] = 1;
//     else
//     return dp[i][j] = need - dungeon[i][j];  

//    }
    

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    
    m = dungeon.size();
    n = dungeon[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    // return fun(0,0,dungeon,dp);




    // tabulation

     for(int i = m-1 ; i >= 0 ; i--)
     for(int j = n-1 ; j >= 0 ; j--)
     {

       if(i == m-1 && j == n-1)
       {
        if(dungeon[m-1][n-1] <= 0)
        dp[i][j] =  abs(dungeon[m-1][n-1]) + 1;
        else 
        dp[i][j] =  1;
       }

       else
       {
       int down = (i+1 < m) ? dp[i+1][j] : INT_MAX;
       int right = (j+1 < n) ? dp[i][j+1] : INT_MAX;

       int need = min(down,right);

       if(dungeon[i][j] >= need)
       dp[i][j] = 1;
       else
       dp[i][j] = need - dungeon[i][j];  
       }

     }
     
     return dp[0][0];
    }
};