class Solution {
public:
    bool fun(string &s ,string &p , int n , int m , vector<vector<int>>&dp)
    { 

       if( n == 0 && m == 0)
       return dp[n][m] = true;

       if( m == 0 && n)
       {
        return dp[n][m] = false;
       }

       if( n == 0 && m)
       {
          for(int i = 0 ; i<m ; i++)
          {
            if(p[i] != '*')
            return dp[n][m] = false;
          }
          return dp[n][m] = true;
       }
       
       if(dp[n][m] != -1)
       return dp[n][m];

       if(s[n-1] == p[m-1])
       return dp[n][m] = fun(s,p,n-1,m-1,dp);

       else if(p[m-1] == '?')
       return dp[n][m] = fun(s,p,n-1,m-1,dp);

       else if(p[m-1] == '*')
       return dp[n][m] = fun(s,p,n-1,m,dp) || fun(s,p,n,m-1,dp); 
       
       else 
       return dp[n][m] = 0;

    }

    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(s,p,n,m,dp);
    }
};