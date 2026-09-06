class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<int> common(26, INT_MAX);

        for (string word : words) {

            vector<int> freq(26, 0);

            // Count characters of current word
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            // Keep minimum frequency
            for (int i = 0; i < 26; i++) {
                common[i] = min(common[i], freq[i]);
            }
        }

        vector<string> ans;

        // Build answer
        for (int i = 0; i < 26; i++) {

            for (int j = 0; j < common[i]; j++) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};