#include "../common/strings.hpp"

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int> freq = lc::lowercaseFrequency(text);

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};