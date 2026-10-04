class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size() , m = num2.size();
        if(num1 == "0" || num2 == "0")
        return "0";

        vector<int>ans(n+m,0);

        for(int i = n-1 ; i >= 0 ; i--)
        for(int j = m-1 ; j >= 0 ; j--)
        {
            int a = num1[i] - '0';
            int b = num2[j] - '0';

            int prod = a*b;
            
            int pos1 = i+j;  // here goes carry with addn 
            int pos2 = i+j+1;   // here goes last digit of product

            int sum = prod + ans[pos2];

           
            ans[pos2] = sum % 10;
            ans[pos1] += sum / 10;
        }

        string res = "";
        
        for(int i= 0 ;i<n+m ; i++)
        {
            if(i == 0 && ans[i] == 0)
            continue;
            
            res += char(ans[i] + '0');
        }

        return res;
    }
};