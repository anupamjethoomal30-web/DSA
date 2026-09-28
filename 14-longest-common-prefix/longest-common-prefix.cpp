class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        
        int n = strs.size();
        string str1 = strs[0];
        string str2 = strs[n-1];
        
        int left = 0;
        int right = 0;

        while(left < str1.size() && right < str2.size())
        {
            if(str1[left] == str2[right])
            {
                 left++;
                 right++;
            }
            else
            break;
        }
        
        return str1.substr(0,left);
    }
};