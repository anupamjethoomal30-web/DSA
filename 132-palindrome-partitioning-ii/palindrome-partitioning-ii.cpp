class Solution {
public:
    bool isPalindrome(int i , int j , string &s)
    {
        while(i<j)
        {
            if(s[i] != s[j])
            return false;

            i++;j--;
        }
        
        return true;
    }

    int fun(int index , int &n , string&s, vector<int>&dp)
    {
        if(index == n)
        return 0;

        if(dp[index] != -1)
        return dp[index];

        int mini = INT_MAX;
        
        for(int i = index ; i < n ;i++)
        {
            if(isPalindrome(index,i,s))
            mini = min(mini, 1 + fun(i+1,n,s,dp));
        }
        
        return dp[index] = mini;
    }

    int minCut(string s) {
        
        int index = 0;
        int n =s.size();
        vector<int>dp(n+1,-1);
        return fun(index,n,s,dp)-1;

    }
};