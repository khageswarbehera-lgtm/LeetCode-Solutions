class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // litterId[i][j] = which litter number is at (i,j)
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Find starting position and give every litter an ID
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        /*
            State:
            row, col, remainingEnergy, mask
        */

        queue<tuple<int, int, int, int>> q;

        // Initially no litter has been collected
        int startMask = 0;

        q.push({sr, sc, energy, startMask});

        /*
            visited[row][col][energy][mask]

            If we have already reached the same
            state, we don't need to process it again.
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        visited[sr][sc][energy][startMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == (1 << litterCount) - 1)
                    return moves;

                // No energy -> cannot move
                if (currEnergy == 0)
                    continue;

                // Try 4 directions
                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Calculate new energy
                    int nextEnergy;

                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }
                    else {
                        nextEnergy = currEnergy - 1;
                    }

                    // Calculate new mask
                    int nextMask = mask;

                    if (classroom[nr][nc] == 'L') {

                        int id = litterId[nr][nc];

                        nextMask |= (1 << id);
                    }

                    // Already visited?
                    if (visited[nr][nc][nextEnergy][nextMask])
                        continue;

                    visited[nr][nc][nextEnergy][nextMask] = true;

                    q.push({
                        nr,
                        nc,
                        nextEnergy,
                        nextMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};