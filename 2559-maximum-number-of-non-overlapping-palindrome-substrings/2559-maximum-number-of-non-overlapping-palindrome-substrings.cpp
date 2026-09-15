class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // palindrome[i][j] = whether s[i...j] is palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // best[i] = maximum palindromes in s[0...i-1]
        vector<int> best(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't select a palindrome ending here
            best[i] = best[i - 1];

            // Try every palindrome ending at i-1
            for (int j = 0; j < i; j++) {

                if (i - j >= k && palindrome[j][i - 1]) {
                    best[i] = max(best[i], best[j] + 1);
                }
            }
        }

        return best[n];
    }
};