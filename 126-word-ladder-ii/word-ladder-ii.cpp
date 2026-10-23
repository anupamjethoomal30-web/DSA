class Solution {
public:
    
    void dfs(string s , vector<string>&seq ,unordered_map<string,int>&mp, string &beginWord , vector<vector<string>>&ans)
    {
       if(s == beginWord)
       {
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return ;
       } 

       int steps = mp[s];    
       for(int i = 0 ; i<s.size() ; i++)
       {
           char original = s[i];

           for(char ch = 'a' ; ch <= 'z' ;ch++)
           {
            s[i] = ch;
            
            if(mp.find(s) != mp.end() && mp[s] + 1 == steps)
            {
              seq.push_back(s);
              dfs(s,seq,mp,beginWord,ans);
              seq.pop_back();
            }
            
           }

           s[i] = original;
       }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        unordered_map<string,int>mp;
        mp[beginWord] = 1;
        int steps = 1;
        
        q.push(beginWord);
        st.erase(beginWord);

        while(!q.empty())
        {
            int size = q.size();
            
            steps++;
            while(size--)
            {
                string s = q.front();
                q.pop();
                
                for(int i = 0; i<s.size() ; i++)
                {
                    char original = s[i];

                    for(int ch = 'a' ; ch <= 'z' ; ch++)
                    {
                        s[i] = ch;

                        if(st.find(s) != st.end())
                        {
                            q.push(s);
                            st.erase(s);
                            mp[s] = steps;
                        }
                    }

                    s[i] = original;
                }


            }


        }

       vector<vector<string>>ans;
        if(mp.find(endWord) != mp.end())
        {   
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq,mp,beginWord,ans);
        }
        
        return ans;
    }
};