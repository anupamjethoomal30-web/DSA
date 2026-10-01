class Solution {
public:
    bool fun(int i , int j , string &haystack , string &needle)
    {   
        if(j == needle.size())
        return true;

        if(haystack[i] == needle[j])
        return fun(i+1,j+1,haystack,needle);
        else
        return false;

    }

    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
        return -1;

        int n = haystack.size();
        int m = needle.size();

        for(int i = 0 ; i<=n-m ; i++)
        {
            if(fun(i,0,haystack,needle))
            return i;
        }

        return -1;
    }
};