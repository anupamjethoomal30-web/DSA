class Solution {
public:
    int lengthOfLongestSubstring(string s) {

       int ans = 0;
       int left = 0;
       int n = s.size();
       unordered_map<char,int>mp;

       for(int i = 0 ; i<n ; i++) 
       {
        if(mp[s[i]] > 0)
        {   
            while(mp[s[i]] > 0)
            {
             mp[s[left]]--;
             left++;
            }
        }
        
         mp[s[i]]++;

         ans = max(ans,i-left+1);
       }


        return ans;

    }
};