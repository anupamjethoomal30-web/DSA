class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;

        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty())
        {
           int size = q.size();

           while(size--)
           {
            pair<string,int> node = q.front();
            q.pop();
            
            string s = node.first;
            int len = node.second;

            if(s == endWord)
            return len;

            for(int i = 0 ; i<s.size() ; i++)
            {
                char original = s[i];

                for(char ch = 'a' ; ch <= 'z' ; ch++)
                {
                    s[i] = ch;
                    
                    // agr ye s mil gya to q me push krdo seq len increase krke aur set se hata do
                    if(st.find(s) != st.end())
                    {
                        q.push({s,len+1});
                        st.erase(s);
                    }
                }
                s[i] = original;
            }

           }
        }
        
        return 0;
    }
};