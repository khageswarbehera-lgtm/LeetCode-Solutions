class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

       
        vector<vector<int>> fa(n, vector<int>(17));
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (nums[p[i]] - nums[p[j]] > maxDiff) {
                j++;
            }
            fa[i][0] = j;
        }

     
        for (int k = 1; k < 17; k++) {
            for (int i = 0; i < n; i++) {
                fa[i][k] = fa[fa[i][k - 1]][k - 1];
            }
        }

        vector<int> mp(n);
        for (int i = 0; i < n; i++) mp[p[i]] = i;

        vector<int> ans;
        for (auto &q : queries) {
            int a = mp[q[0]], b = mp[q[1]];
            if (a == b) { ans.push_back(0); continue; }
            if (a < b) swap(a, b);
            
            int steps = 0;
            for (int k = 16; k >= 0; k--) {
                if (fa[a][k] > b) {
                    a = fa[a][k];
                    steps |= (1 << k);
                }
            }
            
            if (fa[a][0] > b) ans.push_back(-1);
            else ans.push_back(steps + 1);
        }
        return ans;
    }
};