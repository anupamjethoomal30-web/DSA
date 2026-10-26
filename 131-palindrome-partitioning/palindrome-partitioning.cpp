class Solution {
public:
    bool isPalindrome(string &x)
    {
        int i = 0;
        int j = x.size()-1;

        while(i<=j)
        {
            if(x[i] != x[j])
            return false;

            i++;j--;
        }
        
        return true;
    }

    void fun(int index , string &s , int n, vector<string>&temp, vector<vector<string>>&res)
    {
        if(index == n){
            res.push_back(temp);
            return;
        }

        for(int len = 1; len <= n - index ; len++)
        {
            string tempStr = s.substr(index , len);
            if(isPalindrome(tempStr))
            {
                temp.push_back(tempStr);
                fun(index+len,s,n,temp,res);
                temp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>res;
        vector<string>temp;
        string tempstr = "";
        fun(0,s,n,temp,res);
        return res;
    }
};