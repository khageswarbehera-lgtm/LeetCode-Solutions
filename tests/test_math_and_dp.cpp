#include "lc_test.h"

namespace lc0009 {
#include "../0009-palindrome-number/0009-palindrome-number.cpp"
}
namespace lc0029 {
#include "../0029-divide-two-integers/0029-divide-two-integers.cpp"
}
namespace lc0050 {
#include "../0050-powx-n/0050-powx-n.cpp"
}
namespace lc0204 {
#include "../0204-count-primes/0204-count-primes.cpp"
}
namespace lc0231 {
#include "../0231-power-of-two/0231-power-of-two.cpp"
}
namespace lc0486 {
#include "../0486-predict-the-winner/0486-predict-the-winner.cpp"
}
namespace lc0909 {
#include "../0909-stone-game/0909-stone-game.cpp"
}
namespace lc1212 {
#include "../1212-sequential-digits/1212-sequential-digits.cpp"
}
namespace lc1240 {
#include "../1240-stone-game-ii/1240-stone-game-ii.cpp"
}
namespace lc1522 {
#include "../1522-stone-game-iii/1522-stone-game-iii.cpp"
}
namespace lc2050 {
#include "../2050-count-good-numbers/2050-count-good-numbers.cpp"
}
namespace lc2106 {
#include "../2106-find-greatest-common-divisor-of-array/2106-find-greatest-common-divisor-of-array.cpp"
}
namespace lc2323 {
#include "../2323-minimum-bit-flips-to-convert-number/2323-minimum-bit-flips-to-convert-number.cpp"
}
namespace lc3299 {
#include "../3299-find-the-maximum-number-of-elements-in-subset/3299-find-the-maximum-number-of-elements-in-subset.cpp"
}
namespace lc3583 {
#include "../3583-sorted-gcd-pair-queries/3583-sorted-gcd-pair-queries.cpp"
}
namespace lc3608 {
#include "../3608-find-the-number-of-subsequences-with-equal-gcd/3608-find-the-number-of-subsequences-with-equal-gcd.cpp"
}
namespace lc3820 {
#include "../3820-number-of-unique-xor-triplets-ii/3820-number-of-unique-xor-triplets-ii.cpp"
}
namespace lc3824 {
#include "../3824-number-of-unique-xor-triplets-i/3824-number-of-unique-xor-triplets-i.cpp"
}
namespace lc3995 {
#include "../3995-gcd-of-odd-and-even-sums/3995-gcd-of-odd-and-even-sums.cpp"
}
namespace lc4242 {
#include "../4242-sum-of-gcd-of-formed-pairs/4242-sum-of-gcd-of-formed-pairs.cpp"
}

TEST(PalindromeNumber, PositivePalindrome) {
    EXPECT_TRUE(lc0009::Solution().isPalindrome(121));
    EXPECT_TRUE(lc0009::Solution().isPalindrome(0));
}

TEST(PalindromeNumber, NegativeNumbersAreNeverPalindromes) {
    EXPECT_FALSE(lc0009::Solution().isPalindrome(-121));
}

TEST(PalindromeNumber, TrailingZeroBreaksSymmetry) {
    EXPECT_FALSE(lc0009::Solution().isPalindrome(10));
}

TEST(DivideTwoIntegers, TruncatesTowardZero) {
    EXPECT_EQ(lc0029::Solution().divide(10, 3), 3);
    EXPECT_EQ(lc0029::Solution().divide(7, -3), -2);
}

TEST(DivideTwoIntegers, OverflowIsClamped) {
    EXPECT_EQ(lc0029::Solution().divide(INT_MIN, -1), INT_MAX);
}

TEST(DivideTwoIntegers, DividendSmallerThanDivisor) {
    EXPECT_EQ(lc0029::Solution().divide(1, 2), 0);
    EXPECT_EQ(lc0029::Solution().divide(INT_MIN, 1), INT_MIN);
}

TEST(PowXN, PositiveExponent) {
    EXPECT_NEAR(lc0050::Solution().myPow(2.0, 10), 1024.0, 1e-9);
    EXPECT_NEAR(lc0050::Solution().myPow(2.1, 3), 9.261, 1e-9);
}

TEST(PowXN, NegativeExponentAndIntMin) {
    EXPECT_NEAR(lc0050::Solution().myPow(2.0, -2), 0.25, 1e-9);
    EXPECT_NEAR(lc0050::Solution().myPow(1.0, INT_MIN), 1.0, 1e-9);
}

TEST(PowXN, ZeroExponent) {
    EXPECT_NEAR(lc0050::Solution().myPow(5.5, 0), 1.0, 1e-9);
}

TEST(CountPrimes, BelowTen) {
    EXPECT_EQ(lc0204::Solution().countPrimes(10), 4);
}

TEST(CountPrimes, NoPrimesBelowThree) {
    EXPECT_EQ(lc0204::Solution().countPrimes(0), 0);
    EXPECT_EQ(lc0204::Solution().countPrimes(1), 0);
    EXPECT_EQ(lc0204::Solution().countPrimes(2), 0);
}

TEST(CountPrimes, LargerBound) {
    EXPECT_EQ(lc0204::Solution().countPrimes(100), 25);
}

TEST(PowerOfTwo, PowersAreAccepted) {
    EXPECT_TRUE(lc0231::Solution().isPowerOfTwo(1));
    EXPECT_TRUE(lc0231::Solution().isPowerOfTwo(16));
    EXPECT_TRUE(lc0231::Solution().isPowerOfTwo(1 << 30));
}

TEST(PowerOfTwo, NonPositiveAndOddValuesRejected) {
    EXPECT_FALSE(lc0231::Solution().isPowerOfTwo(0));
    EXPECT_FALSE(lc0231::Solution().isPowerOfTwo(3));
    EXPECT_FALSE(lc0231::Solution().isPowerOfTwo(-16));
}

TEST(PredictTheWinner, FirstPlayerLoses) {
    vector<int> nums = {1, 5, 2};
    EXPECT_FALSE(lc0486::Solution().predictTheWinner(nums));
}

TEST(PredictTheWinner, FirstPlayerWins) {
    vector<int> nums = {1, 5, 233, 7};
    EXPECT_TRUE(lc0486::Solution().predictTheWinner(nums));
}

TEST(PredictTheWinner, SingleNumberAlwaysWins) {
    vector<int> nums = {1};
    EXPECT_TRUE(lc0486::Solution().predictTheWinner(nums));
}

TEST(StoneGame, AliceAlwaysWins) {
    vector<int> piles = {5, 3, 4, 5};
    EXPECT_TRUE(lc0909::Solution().stoneGame(piles));
    vector<int> two = {3, 7};
    EXPECT_TRUE(lc0909::Solution().stoneGame(two));
}

TEST(StoneGameII, SmallPileSequence) {
    vector<int> piles = {2, 7, 9, 4, 4};
    EXPECT_EQ(lc1240::Solution().stoneGameII(piles), 10);
}

TEST(StoneGameII, LargeFinalPile) {
    vector<int> piles = {1, 2, 3, 4, 5, 100};
    EXPECT_EQ(lc1240::Solution().stoneGameII(piles), 104);
}

TEST(StoneGameIII, BobWins) {
    vector<int> values = {1, 2, 3, 7};
    EXPECT_EQ(lc1522::Solution().stoneGameIII(values), "Bob");
}

TEST(StoneGameIII, AliceWins) {
    vector<int> values = {1, 2, 3, -9};
    EXPECT_EQ(lc1522::Solution().stoneGameIII(values), "Alice");
}

TEST(StoneGameIII, TieGame) {
    vector<int> values = {1, 2, 3, 6};
    EXPECT_EQ(lc1522::Solution().stoneGameIII(values), "Tie");
}

TEST(SequentialDigits, SmallRange) {
    EXPECT_EQ(lc1212::Solution().sequentialDigits(100, 300), (vector<int>{123, 234}));
}

TEST(SequentialDigits, WideRange) {
    EXPECT_EQ(lc1212::Solution().sequentialDigits(1000, 13000),
              (vector<int>{1234, 2345, 3456, 4567, 5678, 6789, 12345}));
}

TEST(SequentialDigits, EmptyRange) {
    EXPECT_TRUE(lc1212::Solution().sequentialDigits(140, 150).empty());
}

TEST(CountGoodNumbers, SmallLengths) {
    EXPECT_EQ(lc2050::Solution().countGoodNumbers(1), 5);
    EXPECT_EQ(lc2050::Solution().countGoodNumbers(4), 400);
}

TEST(CountGoodNumbers, ModuloIsApplied) {
    EXPECT_EQ(lc2050::Solution().countGoodNumbers(50), 564908303);
}

TEST(FindGCDOfArray, SmallestAndLargestShareFactor) {
    vector<int> nums = {2, 5, 6, 9, 10};
    EXPECT_EQ(lc2106::Solution().findGCD(nums), 2);
}

TEST(FindGCDOfArray, CoprimeExtremes) {
    vector<int> nums = {7, 5, 6, 8, 3};
    EXPECT_EQ(lc2106::Solution().findGCD(nums), 1);
}

TEST(FindGCDOfArray, IdenticalValues) {
    vector<int> nums = {3, 3};
    EXPECT_EQ(lc2106::Solution().findGCD(nums), 3);
}

TEST(MinimumBitFlips, DifferingBitsAreCounted) {
    EXPECT_EQ(lc2323::Solution().minBitFlips(10, 7), 3);
    EXPECT_EQ(lc2323::Solution().minBitFlips(3, 4), 3);
}

TEST(MinimumBitFlips, IdenticalNumbersNeedNoFlips) {
    EXPECT_EQ(lc2323::Solution().minBitFlips(0, 0), 0);
    EXPECT_EQ(lc2323::Solution().minBitFlips(9, 9), 0);
}

TEST(MaximumNumberOfElementsInSubset, PatternOfSquares) {
    vector<int> nums = {5, 4, 1, 2, 2};
    EXPECT_EQ(lc3299::Solution().maximumLength(nums), 3);
}

TEST(MaximumNumberOfElementsInSubset, NoRepeatedValues) {
    vector<int> nums = {1, 3, 2, 4};
    EXPECT_EQ(lc3299::Solution().maximumLength(nums), 1);
}

TEST(SortedGcdPairQueries, ThreeElementArray) {
    vector<int> nums = {2, 3, 4};
    vector<long long> queries = {0, 2, 2};
    EXPECT_EQ(lc3583::Solution().gcdValues(nums, queries), (vector<int>{1, 2, 2}));
}

TEST(SortedGcdPairQueries, RepeatedValuesGiveLargeGcds) {
    vector<int> nums = {4, 4, 2, 1};
    vector<long long> queries = {5, 3, 1, 0};
    EXPECT_EQ(lc3583::Solution().gcdValues(nums, queries), (vector<int>{4, 2, 1, 1}));
}

TEST(SortedGcdPairQueries, SinglePair) {
    vector<int> nums = {2, 2};
    vector<long long> queries = {0, 0};
    EXPECT_EQ(lc3583::Solution().gcdValues(nums, queries), (vector<int>{2, 2}));
}

TEST(SubsequencePairCount, DistinctValues) {
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(lc3608::Solution().subsequencePairCount(nums), 10);
}

TEST(SubsequencePairCount, ThreeMultiplesOfTen) {
    vector<int> nums = {10, 20, 30};
    EXPECT_EQ(lc3608::Solution().subsequencePairCount(nums), 2);
}

TEST(SubsequencePairCount, IdenticalValues) {
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(lc3608::Solution().subsequencePairCount(nums), 50);
}

TEST(UniqueXorTripletsII, ShortArray) {
    vector<int> nums = {1, 3};
    EXPECT_EQ(lc3820::Solution().uniqueXorTriplets(nums), 2);
}

TEST(UniqueXorTripletsII, FourValues) {
    vector<int> nums = {6, 7, 8, 9};
    EXPECT_EQ(lc3820::Solution().uniqueXorTriplets(nums), 4);
}

TEST(UniqueXorTripletsI, TwoValues) {
    vector<int> nums = {1, 2};
    EXPECT_EQ(lc3824::Solution().uniqueXorTriplets(nums), 2);
}

TEST(UniqueXorTripletsI, ThreeValues) {
    vector<int> nums = {3, 1, 2};
    EXPECT_EQ(lc3824::Solution().uniqueXorTriplets(nums), 4);
}

TEST(GcdOfOddAndEvenSums, EvenAndOddN) {
    EXPECT_EQ(lc3995::Solution().gcdOfOddEvenSums(4), 4);
    EXPECT_EQ(lc3995::Solution().gcdOfOddEvenSums(5), 5);
    EXPECT_EQ(lc3995::Solution().gcdOfOddEvenSums(1), 1);
}

TEST(SumOfGcdOfFormedPairs, ThreeElements) {
    vector<int> nums = {2, 6, 4};
    EXPECT_EQ(lc4242::Solution().gcdSum(nums), 2);
}

TEST(SumOfGcdOfFormedPairs, FourElements) {
    vector<int> nums = {3, 6, 2, 8};
    EXPECT_EQ(lc4242::Solution().gcdSum(nums), 5);
}
