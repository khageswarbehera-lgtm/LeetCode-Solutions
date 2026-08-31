class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(char ch : t)
        {
            need[ch]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;
        int right = 0;

        int minLength = INT_MAX;
        int start = 0;

        while(right < s.size())
        {
            char ch = s[right];
            window[ch]++;

            if(need.count(ch) && window[ch] == need[ch])
            {
                formed++;
            }

            while(left <= right && formed == required)
            {
                if(right - left + 1 < minLength)
                {
                    minLength = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if(need.count(leftChar) &&
                   window[leftChar] < need[leftChar])
                {
                    formed--;
                }

                left++;
            }

            right++;
        }

        if(minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};