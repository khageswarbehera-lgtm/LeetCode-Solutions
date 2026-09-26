class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store knowledge in hash map
        for (auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {

                int j = i + 1;

                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Find value
                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

                // Skip everything until ')'
                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};