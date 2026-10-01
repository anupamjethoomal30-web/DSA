class Solution {
public:

bool isSafe(int row, int col , int n , vector<string>&board)
    {
      // same col

      for(int i = 0 ;i<n ; i++)
      {
        if(board[i][col] == 'Q')
        return false;
      }


      // upper diagonals
      int col2 = col;

      for(int i = row ; i>= 0 ; i--)
      {
        if(col < n && board[i][col] == 'Q')
        return false;
        else
        col++;

        if(col2 >= 0 && board[i][col2] == 'Q')
        return false;
        else
        col2--;

      } 
      
      return true;
    }

    void fun(int row , int n , vector<string>&board , vector<vector<string>>&ans)
    {
         
         if(row == n)
         {
            ans.push_back(board);
            return;
         }
        
        for(int j = 0; j<n ; j++)
        {
            if(isSafe(row,j,n,board))
            {
                board[row][j] = 'Q';
                fun(row+1,n,board,ans);
                board[row][j] = '.';
            }
        }

    }

    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        fun(0,n,board,ans);
        return ans.size();
    }
};