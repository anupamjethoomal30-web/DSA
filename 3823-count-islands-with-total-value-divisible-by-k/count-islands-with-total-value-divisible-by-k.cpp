class Solution {
public:
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

    void dfs(int row , int col , vector<vector<int>>&grid, long long &temp)
    {  
        temp += grid[row][col];
        grid[row][col] = 0;

        for(int x = 0 ;x<4 ; x++)
        {
            int new_row = row + dr[x];
            int new_col = col + dc[x];

            if(new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size() && grid[new_row][new_col] != 0)
            dfs(new_row,new_col,grid,temp);
        }
     
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n=grid[0].size();
        
        int ans = 0;

        for(int i= 0; i<m ;i++)
        for(int j = 0;j<n ;j++)
        {
            long long temp = 0;
            if(grid[i][j] != 0)
            {
                dfs(i,j,grid,temp);
            }

            if(temp != 0 && temp % k == 0)
            ans++;
        }

        return ans;
    }
};