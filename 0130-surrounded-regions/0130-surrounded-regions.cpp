class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    void dfs(vector<vector<char>>& board,int r,int c)
    {
        int n=board.size();
        int m=board[0].size();

        board[r][c]='#';

        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 &&
               nr<n && nc<m &&
               board[nr][nc]=='O')
            {
                dfs(board,nr,nc);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        int n=board.size();

        if(n==0) return;

        int m=board[0].size();

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