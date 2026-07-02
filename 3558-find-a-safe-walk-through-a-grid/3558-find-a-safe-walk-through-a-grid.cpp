class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> q;

        vector<vector<int>> best(m, vector<int>(n, -1));

        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        q.push({0,0,startHealth});

        best[0][0] = startHealth;

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){

            auto cur=q.front();

            q.pop();

            int x=cur[0];
            int y=cur[1];
            int h=cur[2];

            if(x==m-1 && y==n-1)
                return true;

            for(int k=0;k<4;k++){

                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0||ny<0||nx>=m||ny>=n)
                    continue;

                int nh=h-grid[nx][ny];

                if(nh<=0)
                    continue;

                if(nh<=best[nx][ny])
                    continue;

                best[nx][ny]=nh;

                q.push({nx,ny,nh});
            }
        }

        return false;
    }
};