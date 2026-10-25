class Solution {
public:
    int dr[8] = {-2,-2,2,2,-1,1,-1,1};
    int dc[8] = {1,-1,1,-1,2,2,-2,-2};

    bool isValid(int row,int col , int n)
    {
        return row >= 0 && row<n && col >= 0 && col < n;
    }

    bool dfs(int row, int col ,int index, vector<vector<int>>&grid , vector<vector<bool>>&visited)
    {
        if(index == grid.size()*grid.size() - 1)
        return true; 

        visited[row][col] = 1;

        for(int k = 0 ; k<8 ;k++)
        {
            int new_row = row + dr[k];
            int new_col = col + dc[k];

            if(isValid(new_row,new_col,grid.size()) && !visited[new_row][new_col] && grid[new_row][new_col] == index + 1)
            {
                return dfs(new_row,new_col,index+1,grid,visited);
            }
        }
        
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,0));

        return dfs(0,0,0,grid,visited);

    }
};