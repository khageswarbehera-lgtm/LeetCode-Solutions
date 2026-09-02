class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> ans;
        unordered_map<int, int> mp;

        for (int x : arr1) {
            mp[x]++;
        }

        for (int i = 0; i < arr2.size(); i++) {

            int p = arr2[i];

            while (mp[p] > 0) {
                ans.push_back(p);
                mp[p]--;
            }
        }

        vector<int> remaining;

        for (auto x : mp) {
            while (x.second > 0) {
                remaining.push_back(x.first);
                x.second--;
            }
        }

        sort(remaining.begin(), remaining.end());

        for (int x : remaining) {
            ans.push_back(x);
        }

        return ans;
    }
};