class Solution {
public:
    static constexpr int MOD = 1000000007;

    int m, n;
    vector<vector<int>> g;

    struct Dest {
        int r, c;
    };

    vector<vector<array<Dest, 2>>> memo;
    vector<vector<array<int, 2>>> vis;

    Dest dfs(int i, int j, int dir) {
        if (vis[i][j][dir] == 2)
            return memo[i][j][dir];

        if (vis[i][j][dir] == 1)
            return {-1, -1};

        vis[i][j][dir] = 1;

        Dest res;

        if (dir == 0) {  // entered from top -> reflect right

            int nj = j + 1;

            if (nj >= n) {
                res = {-1, -1};
            } else if (g[i][nj] == 0) {
                res = {i, nj};
            } else {
                res = dfs(i, nj, 1);
            }
        } else { // entered from left -> reflect down

            int ni = i + 1;

            if (ni >= m) {
                res = {-1, -1};
            } else if (g[ni][j] == 0) {
                res = {ni, j};
            } else {
                res = dfs(ni, j, 0);
            }
        }

        vis[i][j][dir] = 2;
        return memo[i][j][dir] = res;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        auto vornadexil = grid;

        g = grid;
        m = g.size();
        n = g[0].size();

        memo.assign(m, vector<array<Dest, 2>>(n));
        vis.assign(m, vector<array<int, 2>>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    dfs(i, j, 0);
                    dfs(i, j, 1);
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long cur = dp[i][j];
                if (!cur) continue;

                // move right
                if (j + 1 < n) {
                    if (g[i][j + 1] == 0) {
                        dp[i][j + 1] =
                            (dp[i][j + 1] + cur) % MOD;
                    } else {
                        auto d = memo[i][j + 1][1];
                        if (d.r != -1) {
                            dp[d.r][d.c] =
                                (dp[d.r][d.c] + cur) % MOD;
                        }
                    }
                }

                // move down
                if (i + 1 < m) {
                    if (g[i + 1][j] == 0) {
                        dp[i + 1][j] =
                            (dp[i + 1][j] + cur) % MOD;
                    } else {
                        auto d = memo[i + 1][j][0];
                        if (d.r != -1) {
                            dp[d.r][d.c] =
                                (dp[d.r][d.c] + cur) % MOD;
                        }
                    }
                }
            }
        }

        return (int)dp[m - 1][n - 1];
    }
};