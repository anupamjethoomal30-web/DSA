class Solution {
public:
    // bool fun(string &s ,string &p , int n , int m , vector<vector<int>>&dp)
    // { 

    //    if( n == 0 && m == 0)
    //    return dp[n][m] = true;

    //    if( m == 0 && n)
    //    {
    //     return dp[n][m] = false;
    //    }

    //    if( n == 0 && m)
    //    {
    //       for(int i = 0 ; i<m ; i++)
    //       {
    //         if(p[i] != '*')
    //         return dp[n][m] = false;
    //       }
    //       return dp[n][m] = true;
    //    }
       
    //    if(dp[n][m] != -1)
    //    return dp[n][m];

    //    if(s[n-1] == p[m-1])
    //    return dp[n][m] = fun(s,p,n-1,m-1,dp);

    //    else if(p[m-1] == '?')
    //    return dp[n][m] = fun(s,p,n-1,m-1,dp);

    //    else if(p[m-1] == '*')
    //    return dp[n][m] = fun(s,p,n-1,m,dp) || fun(s,p,n,m-1,dp); 
       
    //    else 
    //    return dp[n][m] = 0;

    // }

    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return fun(s,p,n,m,dp);



        // tabulation
        // vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        // dp[0][0] = 1;
        
        // for(int j = 1 ; j<= m ;j++)
        // {
        //     if(p[j-1] == '*' && dp[0][j-1] == 1)
        //     dp[0][j] = true;
        //     else 
        //     dp[0][j] = false;   // ye nhi likhunga to bhi chalega kyuki dp initialize hi 0 se hua hai;
        // }

        // for(int i = 1 ; i<= n ; i++)
        // for(int j = 1 ; j<= m ; j++)
        // {

        //     if(s[i-1] == p[j-1])
        //     dp[i][j] = dp[i-1][j-1];

        //     else if(p[j-1] == '?')
        //     dp[i][j] = dp[i-1][j-1];

        //     else if(p[j-1] == '*')
        //     dp[i][j] = dp[i-1][j] || dp[i][j-1];
            
        //     else
        //     dp[i][j] = 0;
        // }
        
        // return dp[n][m];





        // space optimization to 1 D array
        vector<bool>dp(m+1,0);
        dp[0] = 1;

        for(int j = 1 ; j<= m ;j++)
        {
            if(p[j-1] == '*' && dp[j-1] == 1)
            dp[j] = true;
            else 
            dp[j] = false;   // ye nhi likhunga to bhi chalega kyuki dp initialize hi 0 se hua hai;
        }

        
        for(int i = 1; i<=n ; i++)
        {
            int Diagonal = dp[0];
            dp[0] = 0 ;  // taki ye curr row ke left block ko dikha sake i.e i, j-1;

            for(int j =1 ; j<= m ;j++)
            {   
                int temp = dp[j];

                if(s[i-1] == p[j-1])
                dp[j] = Diagonal;

                else if(p[j-1] == '?')
                dp[j] = Diagonal;

                else if(p[j-1] == '*')
                dp[j] = dp[j] || dp[j-1];

                else
                dp[j] = 0;


                Diagonal = temp; 
            }
        }
        
        return dp[m];
    } 
};