class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

       int n = digits.size();
       int carry = 0;
       for(int i= n-1 ; i>= 0 ;i--)
       {
        
        int sum ; 

        if(i == n-1)
        sum = digits[i] + 1 ;
        else
        sum = digits[i] + carry;

        
        if(sum == 10){
        digits[i] = 0;
        carry = 1;
        }
        else{
            digits[i]= sum;
            carry = 0;
        }

       }

       if(carry == 1)
       digits.insert(digits.begin(),1);
       

       return digits;
    }
};