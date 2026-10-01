class Solution {
public:
    set<vector<int>>s;

    void fun(int idx ,vector<int>&candidates , int target , vector<int>&temp , vector<vector<int>>&ans)
    {
       if(target == 0)
       {
        if(s.find(temp) == s.end())
        {
            s.insert(temp);
            ans.push_back(temp);
        }
       }

       if(target < 0 || idx == candidates.size())
       return ;

       // ek baar usko single time lo aur aage bdh jao
       temp.push_back(candidates[idx]);
       fun(idx+1 , candidates , target - candidates[idx] , temp , ans);

       // ek baar usko multiple times le sakte hai to idx aage nhi bdhega
       fun(idx , candidates , target-candidates[idx] , temp , ans);

       // ek baar usko lo hi mat aur aage bdh jao-> backtrack me temp me jo dala tha vo nikalo
       temp.pop_back();
       fun(idx + 1 , candidates ,target , temp ,ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
      // ek baar us index ko lelo aur aage bdh jao-> fun i+1
      // ek baar us index ko multiples lo -> fun i
      // ek baar usko lo hi mat -> fun i+1
      
      vector<vector<int>>ans;
      vector<int>temp;
      int idx = 0;
      fun(idx,candidates,target,temp,ans);
      return ans;

    }
};