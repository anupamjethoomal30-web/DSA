class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        queue<vector<int>>q;  // stores state curr cell -> i, j and health at that cell
        vector<vector<vector<bool>>>visited(m+1,vector<vector<bool>>(n+1,vector<bool>(m+n + 1,0)));
        
        if(grid[0][0] == 0)
        q.push({0,0,health});
        else
        q.push({0,0,health-1});

        while(!q.empty())
        {
          int size = q.size();

          while(size--)
          {
            vector<int>temp = q.front();
            q.pop();

            int curr_i = temp[0];
            int curr_j = temp[1];
            int rem = temp[2] ;  // remaining health
            

            if(curr_i == m-1 && curr_j == n-1 && rem > 0)
            return true;

            for(int k = 0; k<4 ; k++)
            {
                int new_i = curr_i + dr[k];
                int new_j = curr_j + dc[k];

                if(new_i < 0 || new_j < 0 || new_i >= m || new_j >= n)
                continue;
                
                
                if(grid[new_i][new_j] == 0 && !visited[new_i][new_j][rem])
                {
                    q.push({new_i,new_j,rem});
                    visited[new_i][new_j][rem] = 1;
                }

                else if(grid[new_i][new_j] == 1 && rem > 0 && !visited[new_i][new_j][rem-1])
                {   
                    q.push({new_i,new_j,rem-1});
                    visited[new_i][new_j][rem-1] = 1;
                }

            }

          }

        }

        return false;
    }
};