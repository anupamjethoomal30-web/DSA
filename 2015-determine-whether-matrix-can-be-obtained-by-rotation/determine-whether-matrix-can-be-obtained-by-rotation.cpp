class Solution {
public:
    
    bool fun(vector<vector<int>>&mat,vector<vector<int>>&target , int n)
    {
      
      // rotating by 90
      
      //transpose
      for(int i = 0 ; i<n ;i++)
      for(int j = 0; j<i ;j++)
      swap(mat[i][j],mat[j][i]);

      int i = 0 ;
      int j = n-1;

      while(i<j)
      {
        for(int k = 0 ;k<n ;k++)
        swap(mat[k][i],mat[k][j]);

        i++;
        j--;
      }
      

      // check with target
      for(int i= 0 ; i<n; i++)
      for(int j= 0 ; j<n ;j++)
      {
        if(mat[i][j] != target[i][j])
        return false;
      }

      return true;
    }


    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i =0; i<4 ; i++)
        {
            if(fun(mat,target,n))
            return true;
        }

        return false;
    }
};