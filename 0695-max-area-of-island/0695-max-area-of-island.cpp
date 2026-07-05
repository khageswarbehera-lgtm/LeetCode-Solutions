class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    int dfs(vector<vector<int>>& grid,int r,int c)
    {
        int n=grid.size();
        int m=grid[0].size();

        grid[r][c]=0;

        int area=1;

        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 &&
               nr<n && nc<m &&
               grid[nr][nc]==1)
            {
                area+=dfs(grid,nr,nc);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }

        return ans;
    }
};