class Solution {
public:
    unordered_set<string> ans;

    void solve(string& s, int index, int leftRem, int rightRem,
               int open, int close, string& cur) {

        if (index == s.size()) {
            if (leftRem == 0 && rightRem == 0 && open == close) {
                ans.insert(cur);
            }
            return;
        }

        char c = s[index];

        // Remove current '('
        if (c == '(' && leftRem > 0) {
            solve(s, index + 1, leftRem - 1, rightRem,
                  open, close, cur);
        }

        // Remove current ')'
        if (c == ')' && rightRem > 0) {
            solve(s, index + 1, leftRem, rightRem - 1,
                  open, close, cur);
        }

        // Keep current character
        cur.push_back(c);

        if (c != '(' && c != ')') {
            solve(s, index + 1, leftRem, rightRem,
                  open, close, cur);
        }
        else if (c == '(') {
            solve(s, index + 1, leftRem, rightRem,
                  open + 1, close, cur);
        }
        else if (close < open) {
            solve(s, index + 1, leftRem, rightRem,
                  open, close + 1, cur);
        }

        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum removals
        for (char c : s) {

            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {

                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string cur;

        solve(s, 0, leftRem, rightRem, 0, 0, cur);

        return vector<string>(ans.begin(), ans.end());
    }
};