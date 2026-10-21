class Solution {
public:
    
    int fun(char &c , string &s , int &k)
    {
        int best = 0;
        int others = 0;

        int l = 0 , r = 0;
        int n = s.size();

        while(r < n)
        {

          if(s[r] != c)
          others++; 

          while(others > k)
          {
            if(s[l] != c)
            others--;

            l++;
          } 
         
         
         best = max (best , r-l +1);
         r++;
        }
           
           
        return best;
    }  
  

    int characterReplacement(string s, int k) {

    int ans = 0;

    for(char c = 'A' ; c <= 'Z' ; c++)
    {
        ans = max(ans, fun(c,s,k));
    }
    
    return ans;
    }
};