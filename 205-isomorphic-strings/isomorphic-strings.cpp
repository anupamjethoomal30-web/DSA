class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();

        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;

        for(int i= 0; i<n ;i++)
        {
            char a = s[i];
            char b = t[i];
            
            //mapped nhi hai
            if(mp1.find(a) == mp1.end())
            {
              mp1[a] = b;
            }
            else
            {
                // already mapped hai
                if(mp1[a] != b)
                return false;
            }

            a = t[i];
            b = s[i];   
            
            if(mp2.find(a) == mp2.end())
            {
              mp2[a] = b;
            }
            else
            {
                // already mapped hai
                if(mp2[a] != b)
                return false;
            }
        }

        return true;
    }
};