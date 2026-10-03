class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size() > a.size())
        swap(a,b);

        int x = a.size() - b.size();
        while(x--)
        {
            b = "0" + b;
        }
        
        int n = a.size();
        int carry = 0;
        string ans = "";

        for(int i = n-1; i>=0 ; i--)
        {
            if(a[i] == '1' && b[i] == '1')
            {   
                if(carry == 0){
                ans = '0' + ans;
                carry = 1;
                }
                else{
                    ans = '1' + ans;
                    carry = 1;
                }
            }
            else if(a[i] == '0' && b[i] == '0')
            {
                if(carry == 0)
                {
                    ans = '0' + ans;
                    carry = 0;
                }
                else{
                    ans = '1' + ans;
                    carry = 0;
                }
            }
            else{
                if(carry == 0)
                {
                    ans = '1' + ans;
                    carry = 0;
                }
                else{
                    ans = '0' + ans;
                    carry = 1;
                }
            }
        }

        if(carry == 1)
        {
            ans = '1' + ans;
        }
        
        return ans;
    }
};