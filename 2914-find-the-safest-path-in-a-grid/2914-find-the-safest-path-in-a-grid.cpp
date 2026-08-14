#include "../common/grid.hpp"

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = lc::rowCount(grid);

        vector<vector<int>> dist(n, vector<int>(n, -1));

        queue<pair<int,int>> q;

        // Multi-source BFS
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==1){

                    dist[i][j]=0;

                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto [x,y]=q.front();

            q.pop();

            lc::forEachNeighbor4(x,y,n,n,[&](int nx,int ny){

                if(dist[nx][ny]!=-1)
                    return;

                dist[nx][ny]=dist[x][y]+1;

                q.push({nx,ny});
            });
        }

        priority_queue<vector<int>> pq;

        vector<vector<int>> best(n,vector<int>(n,-1));

        pq.push({dist[0][0],0,0});

        best[0][0]=dist[0][0];

        while(!pq.empty()){

            auto cur=pq.top();

            pq.pop();

            int safe=cur[0];
            int x=cur[1];
            int y=cur[2];

            if(x==n-1 && y==n-1)
                return safe;

            lc::forEachNeighbor4(x,y,n,n,[&](int nx,int ny){

                int newSafe=min(safe,dist[nx][ny]);

                if(newSafe>best[nx][ny]){

                    best[nx][ny]=newSafe;

                    pq.push({newSafe,nx,ny});
                }
            });
        }

        return 0;
    }
};
