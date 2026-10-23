class Solution {
public:
    #define P pair<int,pair<int,int>>

    int minimumObstacles(vector<vector<int>>& grid) {

     int m = grid.size();
     int n = grid[0].size();
     
     int dr[4] = {-1,0,1,0};
     int dc[4] = {0,1,0,-1};
     
     vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
     dist[0][0] = 0;

     priority_queue <P, vector<P>, greater<P>> pq;
     
     pq.push({0,{0,0}});

     while(!pq.empty())
     {
        auto x = pq.top();
        pq.pop();

        int distance = x.first;
        int row_i = x.second.first;
        int row_j = x.second.second;

        if(dist[row_i][row_j] < distance)
        continue;

        // check all neib

        for(int k = 0 ; k<4 ; k++)
        {
            int new_i = row_i + dr[k];
            int new_j = row_j + dc[k];
            
            if(new_i < 0 || new_j < 0 || new_i >= m || new_j >= n)
            continue;

            int wt = grid[new_i][new_j] == 1 ? 1 : 0 ;

            if(distance + wt < dist[new_i][new_j])
            {
                dist[new_i][new_j] = distance + wt;
                pq.push({dist[new_i][new_j],{new_i,new_j}});
            }

        }        

     }
     
     return dist[m-1][n-1];
    }
};