#define P pair<int,int> 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int V = n+1;
        int src = k;
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto time : times)
        {
            int u = time[0];
            int v = time[1];
            int wt = time[2];

            adj[u].push_back({v,wt});
        }
        

        // standard dijsktra
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,src});

        vector<int>dist(V,1e8);
        dist[src] = 0;

        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int node = x.second;
            int distance = x.first;

            
            if(dist[node] < distance)
            continue;


            for(auto N : adj[node])
            {
              int neib = N.first;
              int wt = N.second;

              if(distance + wt < dist[neib])
              {
                dist[neib] = distance + wt;
                pq.push({dist[neib],neib}); 
              }
            }

        }
        
        int ans = *max_element(dist.begin()+1,dist.end());

        return ans != 1e8 ? ans : -1;
    }
};