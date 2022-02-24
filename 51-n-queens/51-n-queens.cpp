class Solution {
public:
    int board[9][9];
    vector<vector<string>> result;
    
    Solution()
    {
        memset(board, 0, sizeof(board));
    }
    
    bool isSafe(int rowIndex, int colIndex, int N)
    {
        //check vertically
        for(int i=0; i<rowIndex; i++)
        {
            if(board[i][colIndex] == 1)
            {
                return false;
            }
        }
        
        //check the left daigonal
        for(int i=rowIndex-1, j=colIndex-1; i>=0 && j>=0; i--,j--)
        {
            if(board[i][j]==1)
            {
                return false;
            }
        }
        
        //check the right daigonal
        for(int i=rowIndex-1, j=colIndex+1; i>=0 && j<N; i--,j++)
        {
            if(board[i][j]==1)
            {
                return false;
            }
        }
        
        return true;
    }
    
    void queenSolver(int rowIndex, int N)
    {
        if(rowIndex == N)
        {
            vector<string> tmpSol;
            for(int i=0; i<N; i++)
            {
                string tmpStr = "";
                for(int j=0; j<N; j++)
                {
                    if(board[i][j] == 0)
                    {
                        tmpStr = tmpStr + ".";
                    }
                    else
                    {
                        tmpStr = tmpStr + "Q";
                    }
                }
                tmpSol.push_back(tmpStr);
            }
            
            result.push_back(tmpSol);
            return;
        }
        
        for(int j=0; j<N; j++)
        {
            if(isSafe(rowIndex,j,N))
            {
                board[rowIndex][j] = 1;
                queenSolver(rowIndex+1, N);
                board[rowIndex][j] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        queenSolver(0, n);
        return result;
    }
};