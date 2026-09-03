class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // Count frequency
        for (int x : nums) {
            mp[x]++;
        }

        // Min heap: {frequency, number}
        for (auto x : mp) {
            pq.push({x.second, x.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract numbers
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};