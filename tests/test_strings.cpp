#include "lc_test.h"

namespace lc0008 {
#include "../0008-string-to-integer-atoi/0008-string-to-integer-atoi.cpp"
}
namespace lc0020 {
#include "../0020-valid-parentheses/0020-valid-parentheses.cpp"
}
namespace lc1159 {
#include "../1159-smallest-subsequence-of-distinct-characters/1159-smallest-subsequence-of-distinct-characters.cpp"
}
namespace lc1297 {
#include "../1297-maximum-number-of-balloons/1297-maximum-number-of-balloons.cpp"
}
namespace lc1460 {
#include "../1460-number-of-substrings-containing-all-three-characters/1460-number-of-substrings-containing-all-three-characters.cpp"
}
namespace lc2099 {
#include "../2099-number-of-strings-that-appear-as-substrings-in-word/2099-number-of-strings-that-appear-as-substrings-in-word.cpp"
}
namespace lc2319 {
#include "../2319-longest-substring-of-one-repeating-character/2319-longest-substring-of-one-repeating-character.cpp"
}
namespace lc3235 {
#include "../3235-minimum-cost-to-convert-string-i/3235-minimum-cost-to-convert-string-i.cpp"
}
namespace lc3275 {
#include "../3275-minimum-number-of-pushes-to-type-word-i/3275-minimum-number-of-pushes-to-type-word-i.cpp"
}
namespace lc3276 {
#include "../3276-minimum-number-of-pushes-to-type-word-ii/3276-minimum-number-of-pushes-to-type-word-ii.cpp"
}
namespace lc3349 {
#include "../3349-maximum-length-substring-with-two-occurrences/3349-maximum-length-substring-with-two-occurrences.cpp"
}
namespace lc3584 {
#include "../3584-find-the-lexicographically-smallest-valid-sequence/3584-find-the-lexicographically-smallest-valid-sequence.cpp"
}
namespace lc3635 {
#include "../3635-smallest-divisible-digit-product-ii/3635-smallest-divisible-digit-product-ii.cpp"
}
namespace lc3804 {
#include "../3804-maximize-active-section-with-trade-ii/3804-maximize-active-section-with-trade-ii.cpp"
}
namespace lc3805 {
#include "../3805-maximize-active-section-with-trade-i/3805-maximize-active-section-with-trade-i.cpp"
}
namespace lc3812 {
#include "../3812-smallest-palindromic-rearrangement-i/3812-smallest-palindromic-rearrangement-i.cpp"
}
namespace lc3813 {
#include "../3813-smallest-palindromic-rearrangement-ii/3813-smallest-palindromic-rearrangement-ii.cpp"
}
namespace lc4136 {
#include "../4136-concatenate-non-zero-digits-and-multiply-by-sum-ii/4136-concatenate-non-zero-digits-and-multiply-by-sum-ii.cpp"
}

TEST(StringToIntegerAtoi, ParsesLeadingDigits) {
    EXPECT_EQ(lc0008::Solution().myAtoi("42"), 42);
    EXPECT_EQ(lc0008::Solution().myAtoi("1337c0d3"), 1337);
}

TEST(StringToIntegerAtoi, HandlesSignAndWhitespace) {
    EXPECT_EQ(lc0008::Solution().myAtoi("   -042"), -42);
    EXPECT_EQ(lc0008::Solution().myAtoi("  +413"), 413);
}

TEST(StringToIntegerAtoi, NonNumericPrefixReturnsZero) {
    EXPECT_EQ(lc0008::Solution().myAtoi("words and 987"), 0);
    EXPECT_EQ(lc0008::Solution().myAtoi("0-1"), 0);
    EXPECT_EQ(lc0008::Solution().myAtoi(""), 0);
}

TEST(StringToIntegerAtoi, ClampsToIntRange) {
    EXPECT_EQ(lc0008::Solution().myAtoi("-91283472332"), INT_MIN);
    EXPECT_EQ(lc0008::Solution().myAtoi("91283472332"), INT_MAX);
}

TEST(ValidParentheses, MatchedPairs) {
    EXPECT_TRUE(lc0020::Solution().isValid("()"));
    EXPECT_TRUE(lc0020::Solution().isValid("()[]{}"));
    EXPECT_TRUE(lc0020::Solution().isValid("{[()]}"));
}

TEST(ValidParentheses, MismatchedOrUnbalanced) {
    EXPECT_FALSE(lc0020::Solution().isValid("(]"));
    EXPECT_FALSE(lc0020::Solution().isValid("([)]"));
    EXPECT_FALSE(lc0020::Solution().isValid("]"));
    EXPECT_FALSE(lc0020::Solution().isValid("("));
}

TEST(SmallestSubsequenceOfDistinctCharacters, AlreadySmallest) {
    EXPECT_EQ(lc1159::Solution().smallestSubsequence("bcabc"), "abc");
}

TEST(SmallestSubsequenceOfDistinctCharacters, DropsLaterDuplicates) {
    EXPECT_EQ(lc1159::Solution().smallestSubsequence("cbacdcbc"), "acdb");
}

TEST(MaximumNumberOfBalloons, ExactlyOneInstance) {
    EXPECT_EQ(lc1297::Solution().maxNumberOfBalloons("nlaebolko"), 1);
}

TEST(MaximumNumberOfBalloons, RepeatedLettersAllowTwo) {
    EXPECT_EQ(lc1297::Solution().maxNumberOfBalloons("loonbalxballpoon"), 2);
}

TEST(MaximumNumberOfBalloons, MissingLetters) {
    EXPECT_EQ(lc1297::Solution().maxNumberOfBalloons("leetcode"), 0);
}

TEST(NumberOfSubstringsContainingAllThree, CountsAllWindows) {
    EXPECT_EQ(lc1460::Solution().numberOfSubstrings("abcabc"), 10);
}

TEST(NumberOfSubstringsContainingAllThree, ShortestWindow) {
    EXPECT_EQ(lc1460::Solution().numberOfSubstrings("abc"), 1);
    EXPECT_EQ(lc1460::Solution().numberOfSubstrings("aaacb"), 3);
}

TEST(NumberOfStringsThatAppearAsSubstrings, CountsMatchingPatterns) {
    vector<string> patterns = {"a", "abc", "bc", "d"};
    EXPECT_EQ(lc2099::Solution().numOfStrings(patterns, "abc"), 3);
}

TEST(NumberOfStringsThatAppearAsSubstrings, CountsDuplicatePatterns) {
    vector<string> patterns = {"a", "a", "a"};
    EXPECT_EQ(lc2099::Solution().numOfStrings(patterns, "ab"), 3);
}

TEST(LongestSubstringOfOneRepeatingCharacter, TracksLongestRunPerQuery) {
    vector<int> indices = {1, 3, 3};
    EXPECT_EQ(lc2319::Solution().longestRepeating("babacc", "bcb", indices),
              (vector<int>{3, 3, 4}));
}

TEST(LongestSubstringOfOneRepeatingCharacter, ShortString) {
    vector<int> indices = {2, 1};
    EXPECT_EQ(lc2319::Solution().longestRepeating("abyzz", "aa", indices), (vector<int>{2, 3}));
}

TEST(MinimumCostToConvertString, UsesCheapestChains) {
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    EXPECT_EQ(lc3235::Solution().minimumCost("abcd", "acbe", original, changed, cost), 28);
}

TEST(MinimumCostToConvertString, IndirectConversion) {
    vector<char> original = {'a', 'c'};
    vector<char> changed = {'c', 'b'};
    vector<int> cost = {1, 2};
    EXPECT_EQ(lc3235::Solution().minimumCost("aaaa", "bbbb", original, changed, cost), 12);
}

TEST(MinimumCostToConvertString, ImpossibleConversion) {
    vector<char> original = {'a'};
    vector<char> changed = {'e'};
    vector<int> cost = {10000};
    EXPECT_EQ(lc3235::Solution().minimumCost("abcd", "abce", original, changed, cost), -1);
}

TEST(MinimumPushesToTypeWordI, DistinctLettersFitOnFirstRow) {
    EXPECT_EQ(lc3275::Solution().minimumPushes("abcde"), 5);
}

TEST(MinimumPushesToTypeWordI, SpillsToSecondPress) {
    EXPECT_EQ(lc3275::Solution().minimumPushes("xycdefghij"), 12);
}

TEST(MinimumPushesToTypeWordII, WeightsByFrequency) {
    EXPECT_EQ(lc3276::Solution().minimumPushes("abcde"), 5);
    EXPECT_EQ(lc3276::Solution().minimumPushes("xyzxyzxyzxyz"), 12);
}

TEST(MinimumPushesToTypeWordII, ManyDistinctLetters) {
    EXPECT_EQ(lc3276::Solution().minimumPushes("aabbccddeeffgghhiiiiii"), 24);
}

TEST(MaximumLengthSubstringWithTwoOccurrences, LimitsRepeats) {
    EXPECT_EQ(lc3349::Solution().maximumLengthSubstring("bcbbbcba"), 4);
}

TEST(MaximumLengthSubstringWithTwoOccurrences, SingleRepeatedCharacter) {
    EXPECT_EQ(lc3349::Solution().maximumLengthSubstring("aaaa"), 2);
}

TEST(LexicographicallySmallestValidSequence, NoChangeNeeded) {
    EXPECT_EQ(lc3584::Solution().validSequence("vbcca", "abc"), (vector<int>{0, 1, 2}));
}

TEST(LexicographicallySmallestValidSequence, SpendsTheSingleEdit) {
    EXPECT_EQ(lc3584::Solution().validSequence("bacdc", "abc"), (vector<int>{1, 2, 4}));
}

TEST(LexicographicallySmallestValidSequence, ImpossibleReturnsEmpty) {
    EXPECT_TRUE(lc3584::Solution().validSequence("aaaaaa", "aaabc").empty());
}

TEST(SmallestDivisibleDigitProduct, RaisesToNextValidNumber) {
    EXPECT_EQ(lc3635::Solution().smallestNumber("1234", 256), "1488");
}

TEST(SmallestDivisibleDigitProduct, InputAlreadyValid) {
    EXPECT_EQ(lc3635::Solution().smallestNumber("12355", 50), "12355");
}

TEST(SmallestDivisibleDigitProduct, TargetWithPrimeFactorAboveNine) {
    EXPECT_EQ(lc3635::Solution().smallestNumber("11111", 26), "-1");
}

TEST(MaximizeActiveSectionWithTradeI, SingleTradeGain) {
    EXPECT_EQ(lc3805::Solution().maxActiveSectionsAfterTrade("01"), 1);
    EXPECT_EQ(lc3805::Solution().maxActiveSectionsAfterTrade("0100"), 4);
}

TEST(MaximizeActiveSectionWithTradeI, MergesSeparatedBlocks) {
    EXPECT_EQ(lc3805::Solution().maxActiveSectionsAfterTrade("1000100"), 7);
    EXPECT_EQ(lc3805::Solution().maxActiveSectionsAfterTrade("01010"), 4);
}

TEST(MaximizeActiveSectionWithTradeII, AnswersPerQueryRange) {
    vector<vector<int>> queries = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};
    EXPECT_EQ(lc3804::Solution().maxActiveSectionsAfterTrade("0100", queries),
              (vector<int>{4, 3, 1, 1}));
}

TEST(MaximizeActiveSectionWithTradeII, OverlappingRanges) {
    vector<vector<int>> queries = {{1, 5}, {0, 6}, {0, 4}};
    EXPECT_EQ(lc3804::Solution().maxActiveSectionsAfterTrade("1000100", queries),
              (vector<int>{6, 7, 2}));
}

TEST(SmallestPalindromicRearrangementI, SingleCharacter) {
    EXPECT_EQ(lc3812::Solution().smallestPalindrome("z"), "z");
}

TEST(SmallestPalindromicRearrangementI, OddCharacterInMiddle) {
    EXPECT_EQ(lc3812::Solution().smallestPalindrome("babab"), "abbba");
}

TEST(SmallestPalindromicRearrangementI, EvenLength) {
    EXPECT_EQ(lc3812::Solution().smallestPalindrome("daccad"), "acddca");
}

TEST(SmallestPalindromicRearrangementII, SecondSmallest) {
    EXPECT_EQ(lc3813::Solution().smallestPalindrome("abba", 2), "baab");
}

TEST(SmallestPalindromicRearrangementII, FewerPermutationsThanK) {
    EXPECT_EQ(lc3813::Solution().smallestPalindrome("aa", 2), "");
}

TEST(SmallestPalindromicRearrangementII, FirstSmallest) {
    EXPECT_EQ(lc3813::Solution().smallestPalindrome("bacab", 1), "abcba");
}

TEST(ConcatenateNonZeroDigitsAndMultiplyBySum, MixedRanges) {
    vector<vector<int>> queries = {{0, 7}, {1, 3}, {4, 6}};
    EXPECT_EQ(lc4136::Solution().sumAndMultiply("10203004", queries), (vector<int>{12340, 4, 9}));
}

TEST(ConcatenateNonZeroDigitsAndMultiplyBySum, RangesWithoutNonZeroDigits) {
    vector<vector<int>> queries = {{0, 3}, {1, 1}};
    EXPECT_EQ(lc4136::Solution().sumAndMultiply("1000", queries), (vector<int>{1, 0}));
}

TEST(ConcatenateNonZeroDigitsAndMultiplyBySum, ResultIsTakenModulo) {
    vector<vector<int>> queries = {{0, 9}};
    EXPECT_EQ(lc4136::Solution().sumAndMultiply("9876543210", queries), (vector<int>{444444137}));
}
