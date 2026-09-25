class Solution {
public:

    set<string> solve(string& s, int& i) {

        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++;  // skip '{'

                set<string> inside = solve(s, i);

                i++;  // skip '}'

                current = multiply(current, inside);
            }

            else if (s[i] == ',') {

                // union current into result
                result.insert(current.begin(), current.end());

                current = {""};

                i++;
            }

            else {

                // normal character
                set<string> letter = {string(1, s[i])};

                current = multiply(current, letter);

                i++;
            }
        }

        // Add the final part
        result.insert(current.begin(), current.end());

        return result;
    }

    set<string> multiply(set<string>& A, set<string>& B) {

        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = solve(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};