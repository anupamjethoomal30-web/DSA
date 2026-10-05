class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

     int st = 0;
     int end = arr.size()-1;

     int ans = -1;

     while(st <= end)
     {
        int mid = st + (end - st)/2 ;

        if(arr[mid] - mid - 1 >= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else 
        {
            st = mid + 1;
        }
     }
     
     // agr ans update nhi hua mtlb 1 se n tk saare positive num already hai
     return ans == -1 ? arr.size() + k : ans + k;
    }
};