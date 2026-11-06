class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();
        vector<pair<int, int>> qs;

        for (int i = 0; i < q; i++) {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        vector<int> ans(q);
        vector<int> cnt(n + 1, 0);

        int active = 0;
        int l = 0, r = 0;
        int m = logs.size();

        for (auto& [time, idx] : qs) {
            while (r < m && logs[r][1] <= time) {
                int server = logs[r][0];

                if (cnt[server] == 0)
                    active++;

                cnt[server]++;
                r++;
            }

            while (l < m && logs[l][1] < time - x) {
                int server = logs[l][0];

                cnt[server]--;

                if (cnt[server] == 0)
                    active--;

                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};