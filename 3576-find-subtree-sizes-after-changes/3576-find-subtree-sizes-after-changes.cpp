class Solution {
public:
    vector<vector<int>> tree;
    vector<int> newParent;
    string s;

    void dfs(int u, vector<int>& last, vector<int>& parent) {
        int ch = s[u] - 'a';

        int prev = last[ch];
        if (u != 0 && prev != -1)
            newParent[u] = prev;
        else
            newParent[u] = parent[u];

        last[ch] = u;

        for (int v : tree[u]) {
            dfs(v, last, parent);
        }

        last[ch] = prev;
    }

    int calc(int u, vector<vector<int>>& g, vector<int>& ans) {
        ans[u] = 1;
        for (int v : g[u]) {
            ans[u] += calc(v, g, ans);
        }
        return ans[u];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        this->s = s;

        tree.assign(n, {});
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        newParent.assign(n, -1);
        vector<int> last(26, -1);

        dfs(0, last, parent);

        vector<vector<int>> newTree(n);
        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

        vector<int> ans(n);
        calc(0, newTree, ans);

        return ans;
    }
};