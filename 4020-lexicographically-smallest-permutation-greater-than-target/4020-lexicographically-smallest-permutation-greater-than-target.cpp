class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> cnt(26, 0);

        for(char c : s)
            cnt[c - 'a']++;

        // Remove the characters of target one by one.
        // cnt may become negative if target prefix is impossible.
        for(int i = 0; i < s.size(); i++)
        {
            cnt[target[i] - 'a']--;
        }

        // Backtrack from right to left.
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int x = target[i] - 'a';

            // Restore target[i]
            cnt[x]++;

            // If any count is negative, target[0...i-1]
            // cannot be formed, so this position is invalid.
            bool valid = true;

            for(int j = 0; j < 26; j++)
            {
                if(cnt[j] < 0)
                {
                    valid = false;
                    break;
                }
            }

            if(!valid)
                continue;

            // Find the smallest available character
            // greater than target[i].
            for(int c = x + 1; c < 26; c++)
            {
                if(cnt[c] > 0)
                {
                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    cnt[c]--;

                    // Smallest possible suffix
                    for(int j = 0; j < 26; j++)
                    {
                        while(cnt[j] > 0)
                        {
                            ans += char('a' + j);
                            cnt[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};