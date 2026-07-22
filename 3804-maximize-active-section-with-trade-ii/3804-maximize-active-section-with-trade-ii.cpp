class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int total_ones = 0;
        int n = s.size();
        vector<pair<int, int>> Z;
        
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') {
                    j++;
                }
                Z.push_back({i, j - 1});
                i = j;
            } else {
                total_ones++;
                i++;
            }
        }
        
        vector<int> adj_sum;
        for (int i = 0; i + 1 < (int)Z.size(); i++) {
            adj_sum.push_back((Z[i].second - Z[i].first + 1) + (Z[i+1].second - Z[i+1].first + 1));
        }
        
        // Step 3: Build a Sparse Table for O(1) Range Maximum Queries (RMQ)
        int n_adj = adj_sum.size();
        int K = 0;
        if (n_adj > 0) {
            K = 32 - __builtin_clz(n_adj);
        }
        
        vector<vector<int>> st(K, vector<int>(n_adj));
        if (n_adj > 0) {
            for (int i = 0; i < n_adj; i++) {
                st[0][i] = adj_sum[i];
            }
            for (int j = 1; j < K; j++) {
                for (int i = 0; i + (1 << j) <= n_adj; i++) {
                    st[j][i] = max(st[j-1][i], st[j-1][i + (1 << (j-1))]);
                }
            }
        }
        
        auto query_rmq = [&](int L, int R) {
            if (L > R) return 0;
            int j = 31 - __builtin_clz(R - L + 1);
            return max(st[j][L], st[j][R - (1 << j) + 1]);
        };
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            auto it = lower_bound(Z.begin(), Z.end(), l, [](const pair<int, int>& p, int val) {
                return p.second < val;
            });
            int a = it - Z.begin();
            
            auto it2 = upper_bound(Z.begin(), Z.end(), r, [](int val, const pair<int, int>& p) {
                return val < p.first;
            });
            int b = it2 - Z.begin() - 1;
            
            if (a >= b) {
                ans.push_back(total_ones);
            } else {
                int len_a = min(Z[a].second, r) - max(Z[a].first, l) + 1;
                int len_b = min(Z[b].second, r) - max(Z[b].first, l) + 1;
                int max_gain = 0;
                
                if (b == a + 1) {
                    // Only two blocks are visible in this query
                    max_gain = len_a + len_b;
                } else {
                    int len_a_next = Z[a+1].second - Z[a+1].first + 1;
                    int len_b_prev = Z[b-1].second - Z[b-1].first + 1;
                    
                    max_gain = max(max_gain, len_a + len_a_next);
                    max_gain = max(max_gain, len_b_prev + len_b);
                    
                    if (b - 2 >= a + 1) {
                        max_gain = max(max_gain, query_rmq(a + 1, b - 2));
                    }
                }
                
                ans.push_back(total_ones + max_gain);
            }
        }
        
        return ans;
    }
};