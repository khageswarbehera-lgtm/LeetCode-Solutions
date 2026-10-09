class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;

                // If the next character is '(',
                // the current ')' pair cannot be completed
                // before this new opening parenthesis.
            }
            else {
                // We need two consecutive ')' for each '('.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                if (open > 0) {
                    open--;
                }
                else {
                    // No '(' available: insert one '('.
                    ans++;
                }
            }
        }

        // Each remaining '(' needs two ')'.
        return ans + open * 2;
    }
};