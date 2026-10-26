class Solution {
public:
    bool fun(int index ,string &s , unordered_set<string>&st , vector<int>&dp)
    {
       if(index == s.size())
       return true;

       if(dp[index] != -1)
       return dp[index];

       for(int len = 1 ; len <= s.size() - index ; len++)
       {
         string temp = s.substr(index , len);
         
         if(st.find(temp) != st.end())
         {
           if(fun(index + len , s , st ,dp))
           return dp[index] = 1; // return true;
         }

       }
       
       return dp[index] = 0;  // return false
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        unordered_set<string>st(wordDict.begin(),wordDict.end());
        
        if(st.find(s) != st.end())
        return true;
        
        vector<int>dp(n,-1);
        return fun(0,s,st,dp);
    }
};