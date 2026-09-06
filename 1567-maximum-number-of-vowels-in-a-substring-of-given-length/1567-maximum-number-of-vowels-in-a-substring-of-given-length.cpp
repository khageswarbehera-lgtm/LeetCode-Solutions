class Solution {
public:
    int maxVowels(string s, int k) {

        int count = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                count++;
        }

        int ans = count;

        // Slide the window
        for (int i = k; i < s.length(); i++) {

            // Add new character
            if (isVowel(s[i]))
                count++;

            // Remove old character
            if (isVowel(s[i - k]))
                count--;

            ans = max(ans, count);
        }

        return ans;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }
};