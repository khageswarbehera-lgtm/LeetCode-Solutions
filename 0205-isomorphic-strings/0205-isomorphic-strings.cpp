class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length())
            return false;

        unordered_map<char, char> st;
        unordered_map<char, char> ts;

        for (int i = 0; i < s.length(); i++) {

            char a = s[i];
            char b = t[i];

            // s -> t mapping
            if (st.count(a) && st[a] != b)
                return false;

            // t -> s mapping
            if (ts.count(b) && ts[b] != a)
                return false;

            st[a] = b;
            ts[b] = a;
        }

        return true;
    }
};