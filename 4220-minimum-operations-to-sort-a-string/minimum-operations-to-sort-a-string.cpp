class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        bool sorted = true;
        
        unordered_map<char,int>freq;
        char minChar = 'z' , maxChar = 'a';
        for(int i = 0 ; i<n-1 ; i++)
        {
            freq[s[i]]++;

            minChar = min(minChar , s[i]);
            maxChar = max(maxChar , s[i]);

            if(s[i] <= s[i+1])
            continue;
            else
            sorted = false;
            
        }
        
        freq[s[n-1]]++;
        minChar = min(minChar , s[n-1]);
        maxChar = max(maxChar , s[n-1]);
        
        if(sorted)
        return 0;
        
        if(n == 2)
        return -1;

        if(s[0] == minChar || s[n-1] == maxChar)
        return 1;

        if(s[0] == maxChar && freq[maxChar] == 1 && s[n-1] == minChar && freq[minChar] == 1)
        return 3;

        return 2;
    }
};