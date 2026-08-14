#pragma once

#include "leetcode.hpp"

namespace lc {

inline constexpr int kAlphabet = 26;

// Occurrences of each lowercase letter, indexed by `letter - 'a'`.
inline vector<int> lowercaseFrequency(const string& s) {
    vector<int> freq(kAlphabet, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    return freq;
}

// Letters described by `counts` concatenated in alphabetical order.
inline string stringFromCounts(const vector<int>& counts) {
    string result;

    for (int i = 0; i < kAlphabet; i++) {
        result.append(counts[i], static_cast<char>('a' + i));
    }

    return result;
}

// Splits letter counts into the counts of one palindrome half and the
// middle character (empty when every count is even).
inline pair<vector<int>, string> palindromeHalfCounts(const vector<int>& counts) {
    vector<int> half(kAlphabet, 0);
    string middle;

    for (int i = 0; i < kAlphabet; i++) {
        half[i] = counts[i] / 2;

        if (counts[i] % 2 == 1) {
            middle = string(1, static_cast<char>('a' + i));
        }
    }

    return {half, middle};
}

inline string mirrorPalindrome(const string& left, const string& middle) {
    string right = left;
    reverse(right.begin(), right.end());

    return left + middle + right;
}

}  // namespace lc
