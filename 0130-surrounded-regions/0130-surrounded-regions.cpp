#include "../common/grid.hpp"

class Solution {
public:

    void dfs(vector<vector<char>>& board,int r,int c)
    {
        int n=lc::rowCount(board);
        int m=lc::colCount(board);

        board[r][c]='#';

        lc::forEachNeighbor4(r,c,n,m,[&](int nr,int nc)
        {
            if(board[nr][nc]=='O')
            {
                dfs(board,nr,nc);
            }
        });
    }

    void solve(vector<vector<char>>& board)
    {
        int n=lc::rowCount(board);

        if(n==0) return;

        int m=lc::colCount(board);

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);

            if(board[i][m-1]=='O')
                dfs(board,i,m-1);
        }

        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
                dfs(board,0,j);

            if(board[n-1][j]=='O')
                dfs(board,n-1,j);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};
