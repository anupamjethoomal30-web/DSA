class Solution {
public:
    void fun(int idx , int n , int k ,vector<int>&temp, vector<vector<int>>&result)
    {   
       
        if(temp.size() == k)
        {
            result.push_back(temp);
            return;
        }
         
       
        for(int i = idx ; i<= n ;i++)
        {
           temp.push_back(i);
           fun(i+1,n,k,temp,result);
           temp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;\
        vector<int>temp;
        int idx = 1;
        fun(idx,n,k,temp,result);
        return result;
    }
};