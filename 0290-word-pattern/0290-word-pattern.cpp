class Solution {
public:
    bool wordPattern(string pattern, string s) {

        stringstream ss(s);
        vector<string> words;

        string word;

        while(ss >> word) {
            words.push_back(word);
        }

        // Number of characters and words must be same
        if(pattern.length() != words.size())
            return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for(int i = 0; i < pattern.length(); i++) {

            char ch = pattern[i];
            string w = words[i];

            // character -> word
            if(mp1.count(ch) && mp1[ch] != w)
                return false;

            // word -> character
            if(mp2.count(w) && mp2[w] != ch)
                return false;

            mp1[ch] = w;
            mp2[w] = ch;
        }

        return true;
    }
};