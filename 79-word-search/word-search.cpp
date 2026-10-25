class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool dfs(int row,int col,int index ,vector<vector<char>>&board , string &word)
    {   
        if(board[row][col] != word[index])
        return false;
        
        if(index == word.size()-1)
        return true;

        char temp = board[row][col];
        board[row][col] = '#';

        for(int k = 0;k<4 ; k++)
        {
            int new_row = row + dr[k];
            int new_col = col + dc[k];

            if(new_row >= 0 && new_row < board.size() && new_col >= 0 && new_col < board[0].size())
            {
                if(dfs(new_row,new_col,index+1,board,word)){
                    board[row][col] = temp;  
                    return true;
                }
                
            }
        }

        board[row][col] = temp;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for(int i= 0 ; i<m ; i++)
        for(int j =0; j<n ;j++)
        {
            if(board[i][j] == word[0])
            {
                if(dfs(i,j,0,board,word)) // 0 => index ptr in word
                return true;
            }
        }

        return false;
    }
};