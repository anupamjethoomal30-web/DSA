class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
       
        int V = numCourses;
        vector<bool>res;
        
        vector<vector<int>>reach(V,vector<int>(V,0));

        for(auto prereq : prerequisites)
        {
            int u = prereq[0];
            int v = prereq[1];

            reach[u][v] = 1;
        }
        

        // floyd warshall idea
        for(int k= 0 ;k<V ;k++)
        for(int i =0; i<V ;i++)
        for(int j= 0 ;j<V ;j++)
        {
            if(reach[i][k] && reach[k][j])
            reach[i][j] = true;
        }


        for(auto query : queries)
        {
            int u = query[0];
            int v = query[1];

            if(reach[u][v])
            res.push_back(true);
            else
            res.push_back(false);
        }
        
        return res;
    }
};