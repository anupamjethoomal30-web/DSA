class Solution {
public:
   
    void DFS(int node ,int parent, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&disc, vector<int>&low, int &timer , vector<vector<int>>&ans)
    {

        visited[node] = 1;
        disc[node] = low[node] = timer;

        timer++;

        for(auto neib : adj[node])
        {

         if(neib == parent)
         continue;

         if(!visited[neib])
         {
            DFS(neib,node,adj,visited,disc,low,timer,ans);
            low[node] = min(low[node],low[neib]);

            if(disc[node]<low[neib])
            {
                ans.push_back({node,neib});
            }
         }
         else
         {
            low[node] = min(low[node],low[neib]);
         }

        }

         
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n);

        for(auto connection : connections)
        {
            int u = connection[0];
            int v = connection[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<bool>visited(n,0);
        
        vector<int>disc(n);
        vector<int>low(n);
        int timer =0;
        vector<vector<int>>ans;
       

        for(int i = 0 ; i<n ; i++)
        {
            if(!visited[i])
            {   
                int parent = -1;
                DFS(i,parent,adj,visited,disc,low,timer,ans);
            }
        }
        

        return ans;
    }
};