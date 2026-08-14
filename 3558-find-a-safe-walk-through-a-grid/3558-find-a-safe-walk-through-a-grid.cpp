#include "../common/grid.hpp"

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = lc::rowCount(grid);
        int n = lc::colCount(grid);

        queue<vector<int>> q;

        vector<vector<int>> best(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        q.push({0,0,startHealth});

        best[0][0] = startHealth;

        while(!q.empty()){

            auto cur=q.front();

            q.pop();

            int x=cur[0];
            int y=cur[1];
            int h=cur[2];

            if(x==m-1 && y==n-1)
                return true;

            lc::forEachNeighbor4(x,y,m,n,[&](int nx,int ny){

                int nh=h-grid[nx][ny];

                if(nh<=0)
                    return;

                if(nh<=best[nx][ny])
                    return;

                best[nx][ny]=nh;

                q.push({nx,ny,nh});
            });
        }

        return false;
    }
};
