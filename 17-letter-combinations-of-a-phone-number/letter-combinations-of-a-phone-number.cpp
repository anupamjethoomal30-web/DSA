class Solution {
public:
   
    void fun(int idx , string &digits ,vector<vector<char>>&store, string &temp , vector<string>&ans)
    { 

        if(idx == digits.size())
        {
            ans.push_back(temp);
            return ;
        }
  
        for(auto x : store[digits[idx] - '0'])
        {
            temp += x;
            fun(idx+1,digits,store,temp,ans);
            temp.pop_back();
        }

    }


    vector<string> letterCombinations(string digits) {
        
        vector<vector<char>>store(10);
        store[2] = {'a', 'b', 'c'};
        store[3] = {'d', 'e', 'f'};
        store[4] = {'g', 'h', 'i'};
        store[5] = {'j', 'k', 'l'};
        store[6] = {'m', 'n', 'o'};
        store[7] = {'p', 'q', 'r', 's'};
        store[8] = {'t', 'u', 'v'};
        store[9] = {'w', 'x', 'y', 'z'};


        vector<string>ans;
        string temp = "";
        int idx = 0;
        fun(idx,digits,store,temp,ans);
        
        return ans;
    }
};