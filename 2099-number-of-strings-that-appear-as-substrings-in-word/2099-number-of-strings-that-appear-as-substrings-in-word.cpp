class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int ans = 0;

        for (string &pat : patterns) {

            bool found = false;

            for (int i = 0; i + pat.size() <= word.size(); i++) {

                if (word.substr(i, pat.size()) == pat) {
                    found = true;
                    break;
                }
            }

            if (found)
                ans++;
        }

        return ans;
    }
};