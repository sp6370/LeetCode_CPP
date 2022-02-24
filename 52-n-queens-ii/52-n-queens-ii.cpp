class Solution {
public:
    
    int board[9][9];
    
    Solution()
    {
        memset(board, 0, sizeof(board));
    }
    
    bool isSafe(int rowIndex, int colIndex, int N)
    {
        for(int i=0; i<rowIndex; i++)
        {
            if(board[i][colIndex] == 1)
            {
                return false;
            }
        }
        
        for(int i=rowIndex-1, j=colIndex-1; i>=0 && j>=0; i--,j--)
        {
            if(board[i][j]==1)
            {
                return false;
            }
        }
        
        for(int i=rowIndex-1, j=colIndex+1; i>=0 && j<N; i--, j++)
        {
            if(board[i][j]==1)
            {
                return false;
            }
        }
        
        return true;
    }
    
    int queenSolver(int rowIndex, int N)
    {
        if(rowIndex == N)
        {
            return 1;
        }
        
        int count = 0;
        for(int i=0; i<N; i++)
        {
            if(isSafe(rowIndex, i, N))
            {
                board[rowIndex][i] = 1;
                count = count + queenSolver(rowIndex+1, N);
                board[rowIndex][i] = 0;
            }
        }
        return count;
    }
    
    int totalNQueens(int n) {
        return queenSolver(0, n);
    }
};