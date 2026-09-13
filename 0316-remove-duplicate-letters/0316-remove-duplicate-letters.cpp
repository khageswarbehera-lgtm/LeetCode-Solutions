class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        // Count frequency
        for(char c : s) {
            freq[c - 'a']++;
        }

        string st;

        for(char c : s) {
            int idx = c - 'a';

            // Current character is no longer remaining
            freq[idx]--;

            // Already present in answer
            if(visited[idx])
                continue;

            // Remove larger characters if they occur again later
            while(!st.empty() &&
                  st.back() > c &&
                  freq[st.back() - 'a'] > 0) {
                
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[idx] = true;
        }

        return st;
    }
};