class Solution {
public:
    string convert(string s, int numRows) {
        int rows = numRows;


        if(rows == 1 || rows >= s.size())
        return s;
      
        int n = s.size();
        int ElementsInOneCycle = 2 * rows - 2;
        int colsInOneCycle = rows;
        //Let x be the total no of cycle, therfore cols in x cycle => x->cycle = x.colsInOneCycle => x*(rows-1);
        
        int totalCycle = n/ElementsInOneCycle + 1;
        int cols = totalCycle * (rows);


        vector<vector<char>>grid(rows,vector<char>(cols,'\0')); 

        int r = 0;
        int c = 0;

        bool down = true;

        for(int i = 0;i<s.size() ;i++)
        {
            grid[r][c] = s[i];
            
            if(down)
            {
                if(r == rows - 1)
                {   
                    down = false;
                    r--;
                    c++;
                }
                else
                r++;
            }

            else
            {
                if(r == 0)
                {
                    down = true;
                    r++;
                }
                else{
                    r--;
                    c++;
                }
            }

        }

        string res = "";

        for(int i = 0; i<rows ; i++)
        for(int j = 0 ; j<cols ; j++)
        {
            if(grid[i][j] != '\0')
            res.push_back(grid[i][j]);
        }
        
        return res;
    }
};