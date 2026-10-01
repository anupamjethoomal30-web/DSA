class Solution {
public:
    int mySqrt(int x) {
       
       if(x <= 1)
       return x;

       int st = 1 ;
       int end = x-1;

       while(st <= end)
       {
        int mid = st + (end - st)/2;

        if(mid == x/mid)
        return mid;

        else if(mid > x / mid)
        end = mid-1;

        else
        st = mid + 1;

       }
       
       return end;
    }
};