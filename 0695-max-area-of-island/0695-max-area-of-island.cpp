#include "../common/grid.hpp"

class Solution {
public:

    int dfs(vector<vector<int>>& grid,int r,int c)
    {
        int n=lc::rowCount(grid);
        int m=lc::colCount(grid);

        grid[r][c]=0;

        int area=1;

        lc::forEachNeighbor4(r,c,n,m,[&](int nr,int nc)
        {
            if(grid[nr][nc]==1)
            {
                area+=dfs(grid,nr,nc);
            }
        });

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int n=lc::rowCount(grid);
        int m=lc::colCount(grid);

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
