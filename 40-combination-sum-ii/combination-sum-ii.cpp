class Solution {
public:
    

    void fun(int idx, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

       for(int i = idx ; i < candidates.size() ; i++)
       {
        if(i>idx && candidates[i] == candidates[i-1])
        continue;

        if(candidates[i] > target)
        break;

        temp.push_back(candidates[i]);
        fun(i+1,candidates,target-candidates[i] , temp,ans);
        temp.pop_back();
       }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        fun(0, candidates, target, temp, ans);

        return ans;
    }
};