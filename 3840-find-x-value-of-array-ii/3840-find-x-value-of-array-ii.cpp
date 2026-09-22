class Solution {
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int k;
    int n;
    vector<Node> tree;

    Node merge(Node L, Node R) {
        Node res;

        // Product of the whole segment
        res.prod = (L.prod * R.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] = L.cnt[r];
        }

        // Prefixes that cross from left into right
        for (int r = 0; r < k; r++) {
            int newRem = (L.prod * r) % k;
            res.cnt[newRem] += R.cnt[r];
        }

        return res;
    }

    Node makeNode(int value) {
        Node node;

        int rem = value % k;

        node.prod = rem;
        node.cnt[rem] = 1;

        return node;
    }

    void build(int node, int l, int r,
               vector<int>& nums) {

        if (l == r) {
            tree[node] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r,
                int index, int value) {

        if (l == r) {
            tree[node] = makeNode(value);
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, r, index, value);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(
                node * 2,
                l,
                mid,
                ql,
                qr
            );
        }

        if (ql > mid) {
            return query(
                node * 2 + 1,
                mid + 1,
                r,
                ql,
                qr
            );
        }

        Node left = query(
            node * 2,
            l,
            mid,
            ql,
            qr
        );

        Node right = query(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr
        );

        return merge(left, right);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        k = K;
        n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // Query [start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};