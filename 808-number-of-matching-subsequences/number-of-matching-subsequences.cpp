class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        unordered_map<char,vector<int>>mp;  // stores char and its position

        for(int i= 0; i<s.size() ;i++)
        {
            mp[s[i]].push_back(i);
        }

        int count = 0;

        for(auto &word : words)
        {
           int last = -1;
           for(int i = 0 ;i<word.size() ; i++)
           {
             
            char ch = word[i];

            // if(mp.find(ch) == mp.end())
            // break;

            auto it = upper_bound(mp[ch].begin(),mp[ch].end(),last);

            if(it == mp[ch].end())
            break;
            
            last = *it;
            
            if(i == word.size()-1)
            count++;

           }
        }

        return count;        
    }
};