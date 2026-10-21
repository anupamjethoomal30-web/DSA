class Solution {
public:
    
    void fun(int n , int open , int close , string &temp , vector<string>&ans)
    {

     if(temp.size() == 2*n)
     {
        ans.push_back(temp);
        return;
     }  

     if(open < n)
     {
        temp += '(';
        fun(n,open+1,close,temp,ans);
        temp.pop_back();
     }
     
     if(close < open)
     {
        temp += ')';
        fun(n,open,close+1,temp,ans);
        temp.pop_back();
     }

    }

    vector<string> generateParenthesis(int n) {
        
      vector<string>ans;
      string temp = "";

      int open = 0 , close = 0;

      fun(n,open,close,temp,ans);

      return ans;

    }
};