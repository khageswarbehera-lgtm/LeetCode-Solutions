#include "lc_test.h"

namespace lc0015 {
#include "../0015-3sum/0015-3sum.cpp"
}
namespace lc0016 {
#include "../0016-3sum-closest/0016-3sum-closest.cpp"
}
namespace lc0018 {
#include "../0018-4sum/0018-4sum.cpp"
}
namespace lc0026 {
#include "../0026-remove-duplicates-from-sorted-array/0026-remove-duplicates-from-sorted-array.cpp"
}
namespace lc0027 {
#include "../0027-remove-element/0027-remove-element.cpp"
}
namespace lc0035 {
#include "../0035-search-insert-position/0035-search-insert-position.cpp"
}
namespace lc0053 {
#include "../0053-maximum-subarray/0053-maximum-subarray.cpp"
}
namespace lc0075 {
#include "../0075-sort-colors/0075-sort-colors.cpp"
}
namespace lc0121 {
#include "../0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp"
}
namespace lc0136 {
#include "../0136-single-number/0136-single-number.cpp"
}
namespace lc0169 {
#include "../0169-majority-element/0169-majority-element.cpp"
}
namespace lc0283 {
#include "../0283-move-zeroes/0283-move-zeroes.cpp"
}
namespace lc0485 {
#include "../0485-max-consecutive-ones/0485-max-consecutive-ones.cpp"
}
namespace lc0496 {
#include "../0496-next-greater-element-i/0496-next-greater-element-i.cpp"
}
namespace lc0503 {
#include "../0503-next-greater-element-ii/0503-next-greater-element-ii.cpp"
}
namespace lc0628 {
#include "../0628-maximum-product-of-three-numbers/0628-maximum-product-of-three-numbers.cpp"
}
namespace lc0792 {
#include "../0792-binary-search/0792-binary-search.cpp"
}
namespace lc1222 {
#include "../1222-remove-covered-intervals/1222-remove-covered-intervals.cpp"
}
namespace lc1256 {
#include "../1256-rank-transform-of-an-array/1256-rank-transform-of-an-array.cpp"
}
namespace lc1386 {
#include "../1386-shift-2d-grid/1386-shift-2d-grid.cpp"
}
namespace lc1574 {
#include "../1574-maximum-product-of-two-elements-in-an-array/1574-maximum-product-of-two-elements-in-an-array.cpp"
}
namespace lc1956 {
#include "../1956-maximum-element-after-decreasing-and-rearranging/1956-maximum-element-after-decreasing-and-rearranging.cpp"
}
namespace lc2271 {
#include "../2271-rearrange-array-elements-by-sign/2271-rearrange-array-elements-by-sign.cpp"
}
namespace lc3225 {
#include "../3225-length-of-longest-subarray-with-at-most-k-frequency/3225-length-of-longest-subarray-with-at-most-k-frequency.cpp"
}
namespace lc4074 {
#include "../4074-count-subarrays-with-majority-element-i/4074-count-subarrays-with-majority-element-i.cpp"
}
namespace lc4107 {
#include "../4107-find-missing-elements/4107-find-missing-elements.cpp"
}

using lctest::sorted;
using lctest::sortedNested;

TEST(ThreeSum, FindsDistinctTriplets) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    EXPECT_EQ(sortedNested(lc0015::Solution().threeSum(nums)),
              (vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}));
}

TEST(ThreeSum, AllZeroesYieldsSingleTriplet) {
    vector<int> nums = {0, 0, 0, 0};
    EXPECT_EQ(lc0015::Solution().threeSum(nums), (vector<vector<int>>{{0, 0, 0}}));
}

TEST(ThreeSum, NoTripletSumsToZero) {
    vector<int> nums = {1, 2, 4};
    EXPECT_TRUE(lc0015::Solution().threeSum(nums).empty());
}

TEST(ThreeSumClosest, PicksNearestSum) {
    vector<int> nums = {-1, 2, 1, -4};
    EXPECT_EQ(lc0016::Solution().threeSumClosest(nums, 1), 2);
}

TEST(ThreeSumClosest, ExactMatch) {
    vector<int> nums = {0, 0, 0};
    EXPECT_EQ(lc0016::Solution().threeSumClosest(nums, 1), 0);
}

TEST(FourSum, FindsDistinctQuadruplets) {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    EXPECT_EQ(sortedNested(lc0018::Solution().fourSum(nums, 0)),
              (vector<vector<int>>{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}));
}

TEST(FourSum, RepeatedValues) {
    vector<int> nums = {2, 2, 2, 2, 2};
    EXPECT_EQ(lc0018::Solution().fourSum(nums, 8), (vector<vector<int>>{{2, 2, 2, 2}}));
}

TEST(RemoveDuplicatesFromSortedArray, KeepsFirstOccurrences) {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int length = lc0026::Solution().removeDuplicates(nums);
    EXPECT_EQ(length, 5);
    EXPECT_EQ(vector<int>(nums.begin(), nums.begin() + length), (vector<int>{0, 1, 2, 3, 4}));
}

TEST(RemoveDuplicatesFromSortedArray, AlreadyUnique) {
    vector<int> nums = {1, 2};
    EXPECT_EQ(lc0026::Solution().removeDuplicates(nums), 2);
}

TEST(RemoveElement, MovesRemainingValuesToFront) {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int length = lc0027::Solution().removeElement(nums, 2);
    EXPECT_EQ(length, 5);
    EXPECT_EQ(sorted(vector<int>(nums.begin(), nums.begin() + length)),
              (vector<int>{0, 0, 1, 3, 4}));
}

TEST(RemoveElement, ValueMissingKeepsEverything) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(lc0027::Solution().removeElement(nums, 9), 3);
}

TEST(SearchInsertPosition, FindsExistingValue) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(lc0035::Solution().searchInsert(nums, 5), 2);
}

TEST(SearchInsertPosition, ReturnsInsertionIndex) {
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(lc0035::Solution().searchInsert(nums, 2), 1);
    EXPECT_EQ(lc0035::Solution().searchInsert(nums, 7), 4);
}

TEST(MaximumSubarray, MixedSignsPicksBestWindow) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(lc0053::Solution().maxSubArray(nums), 6);
}

TEST(MaximumSubarray, SingleElement) {
    vector<int> nums = {1};
    EXPECT_EQ(lc0053::Solution().maxSubArray(nums), 1);
}

TEST(MaximumSubarray, AllNegativeReturnsLeastNegative) {
    vector<int> nums = {-3, -1, -7};
    EXPECT_EQ(lc0053::Solution().maxSubArray(nums), -1);
}

TEST(SortColors, PartitionsInPlace) {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    lc0075::Solution().sortColors(nums);
    EXPECT_EQ(nums, (vector<int>{0, 0, 1, 1, 2, 2}));
}

TEST(SortColors, SingleValue) {
    vector<int> nums = {2, 0, 1};
    lc0075::Solution().sortColors(nums);
    EXPECT_EQ(nums, (vector<int>{0, 1, 2}));
}

TEST(BestTimeToBuyAndSellStock, ProfitFromLaterPeak) {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(lc0121::Solution().maxProfit(prices), 5);
}

TEST(BestTimeToBuyAndSellStock, MonotonicDecreaseHasNoProfit) {
    vector<int> prices = {7, 6, 4, 3, 1};
    EXPECT_EQ(lc0121::Solution().maxProfit(prices), 0);
}

TEST(SingleNumber, FindsUnpairedValue) {
    vector<int> nums = {4, 1, 2, 1, 2};
    EXPECT_EQ(lc0136::Solution().singleNumber(nums), 4);
}

TEST(SingleNumber, SingletonArray) {
    vector<int> nums = {1};
    EXPECT_EQ(lc0136::Solution().singleNumber(nums), 1);
}

TEST(MajorityElement, StrictMajority) {
    vector<int> nums = {3, 2, 3};
    EXPECT_EQ(lc0169::Solution().majorityElement(nums), 3);
}

TEST(MajorityElement, LongerInput) {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    EXPECT_EQ(lc0169::Solution().majorityElement(nums), 2);
}

TEST(MoveZeroes, KeepsRelativeOrderOfNonZeroes) {
    vector<int> nums = {0, 1, 0, 3, 12};
    lc0283::Solution().moveZeroes(nums);
    EXPECT_EQ(nums, (vector<int>{1, 3, 12, 0, 0}));
}

TEST(MoveZeroes, AllZeroes) {
    vector<int> nums = {0, 0};
    lc0283::Solution().moveZeroes(nums);
    EXPECT_EQ(nums, (vector<int>{0, 0}));
}

TEST(MaxConsecutiveOnes, LongestRun) {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    EXPECT_EQ(lc0485::Solution().findMaxConsecutiveOnes(nums), 3);
}

TEST(MaxConsecutiveOnes, NoOnes) {
    vector<int> nums = {0, 0};
    EXPECT_EQ(lc0485::Solution().findMaxConsecutiveOnes(nums), 0);
}

TEST(NextGreaterElementI, MapsThroughSecondArray) {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    EXPECT_EQ(lc0496::Solution().nextGreaterElement(nums1, nums2), (vector<int>{-1, 3, -1}));
}

TEST(NextGreaterElementI, IncreasingSecondArray) {
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    EXPECT_EQ(lc0496::Solution().nextGreaterElement(nums1, nums2), (vector<int>{3, -1}));
}

TEST(NextGreaterElementII, WrapsAround) {
    vector<int> nums = {1, 2, 1};
    EXPECT_EQ(lc0503::Solution().nextGreaterElements(nums), (vector<int>{2, -1, 2}));
}

TEST(NextGreaterElementII, LongerCircularInput) {
    vector<int> nums = {1, 2, 3, 4, 3};
    EXPECT_EQ(lc0503::Solution().nextGreaterElements(nums), (vector<int>{2, 3, 4, -1, 4}));
}

TEST(MaximumProductOfThreeNumbers, AllPositive) {
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(lc0628::Solution().maximumProduct(nums), 24);
}

TEST(MaximumProductOfThreeNumbers, TwoNegativesBeatThreeSmallest) {
    vector<int> nums = {-100, -98, -1, 2, 3, 4};
    EXPECT_EQ(lc0628::Solution().maximumProduct(nums), 39200);
}

TEST(MaximumProductOfThreeNumbers, AllNegative) {
    vector<int> nums = {-4, -3, -2, -1};
    EXPECT_EQ(lc0628::Solution().maximumProduct(nums), -6);
}

TEST(BinarySearch, FindsTarget) {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(lc0792::Solution().search(nums, 9), 4);
}

TEST(BinarySearch, MissingTarget) {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(lc0792::Solution().search(nums, 2), -1);
}

TEST(RemoveCoveredIntervals, DropsCoveredIntervals) {
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    EXPECT_EQ(lc1222::Solution().removeCoveredIntervals(intervals), 2);
}

TEST(RemoveCoveredIntervals, NestedInterval) {
    vector<vector<int>> intervals = {{1, 4}, {2, 3}};
    EXPECT_EQ(lc1222::Solution().removeCoveredIntervals(intervals), 1);
}

TEST(RankTransformOfAnArray, RanksAreOneBased) {
    vector<int> arr = {40, 10, 20, 30};
    EXPECT_EQ(lc1256::Solution().arrayRankTransform(arr), (vector<int>{4, 1, 2, 3}));
}

TEST(RankTransformOfAnArray, EqualValuesShareRank) {
    vector<int> arr = {100, 100, 100};
    EXPECT_EQ(lc1256::Solution().arrayRankTransform(arr), (vector<int>{1, 1, 1}));
}

TEST(RankTransformOfAnArray, EmptyInput) {
    vector<int> arr = {};
    EXPECT_TRUE(lc1256::Solution().arrayRankTransform(arr).empty());
}

TEST(Shift2dGrid, ShiftsOnceWithWrapAround) {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    EXPECT_EQ(lc1386::Solution().shiftGrid(grid, 1),
              (vector<vector<int>>{{9, 1, 2}, {3, 4, 5}, {6, 7, 8}}));
}

TEST(Shift2dGrid, ShiftByGridSizeIsIdentity) {
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    EXPECT_EQ(lc1386::Solution().shiftGrid(grid, 4), grid);
}

TEST(MaximumProductOfTwoElements, PicksTwoLargest) {
    vector<int> nums = {3, 4, 5, 2};
    EXPECT_EQ(lc1574::Solution().maxProduct(nums), 12);
}

TEST(MaximumProductOfTwoElements, DuplicateMaximum) {
    vector<int> nums = {1, 5, 4, 5};
    EXPECT_EQ(lc1574::Solution().maxProduct(nums), 16);
}

TEST(MaximumElementAfterDecreasingAndRearranging, DuplicatesLimitGrowth) {
    vector<int> arr = {2, 2, 1, 2, 1};
    EXPECT_EQ(lc1956::Solution().maximumElementAfterDecrementingAndRearranging(arr), 2);
}

TEST(MaximumElementAfterDecreasingAndRearranging, LargeValuesAreCompressed) {
    vector<int> arr = {100, 1, 1000};
    EXPECT_EQ(lc1956::Solution().maximumElementAfterDecrementingAndRearranging(arr), 3);
}

TEST(RearrangeArrayElementsBySign, AlternatesStartingPositive) {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    EXPECT_EQ(lc2271::Solution().rearrangeArray(nums), (vector<int>{3, -2, 1, -5, 2, -4}));
}

TEST(RearrangeArrayElementsBySign, SinglePair) {
    vector<int> nums = {-1, 1};
    EXPECT_EQ(lc2271::Solution().rearrangeArray(nums), (vector<int>{1, -1}));
}

TEST(LongestSubarrayWithAtMostKFrequency, AllowsTwoOccurrences) {
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    EXPECT_EQ(lc3225::Solution().maxSubarrayLength(nums, 2), 6);
}

TEST(LongestSubarrayWithAtMostKFrequency, SingleOccurrenceLimit) {
    vector<int> nums = {1, 2, 1, 2, 1, 2, 1, 2};
    EXPECT_EQ(lc3225::Solution().maxSubarrayLength(nums, 1), 2);
}

TEST(CountSubarraysWithMajorityElement, CountsQualifyingWindows) {
    vector<int> nums = {1, 2, 2, 3};
    EXPECT_EQ(lc4074::Solution().countMajoritySubarrays(nums, 2), 5);
}

TEST(CountSubarraysWithMajorityElement, EveryWindowQualifies) {
    vector<int> nums = {1, 1, 1, 1};
    EXPECT_EQ(lc4074::Solution().countMajoritySubarrays(nums, 1), 10);
}

TEST(CountSubarraysWithMajorityElement, TargetAbsent) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(lc4074::Solution().countMajoritySubarrays(nums, 4), 0);
}

TEST(FindMissingElements, ReportsSingleGap) {
    vector<int> nums = {1, 4, 2, 5};
    EXPECT_EQ(lc4107::Solution().findMissingElements(nums), (vector<int>{3}));
}

TEST(FindMissingElements, ContiguousRangeHasNoGaps) {
    vector<int> nums = {7, 8, 6, 9};
    EXPECT_TRUE(lc4107::Solution().findMissingElements(nums).empty());
}

TEST(FindMissingElements, ReportsRangeOfGaps) {
    vector<int> nums = {5, 1};
    EXPECT_EQ(lc4107::Solution().findMissingElements(nums), (vector<int>{2, 3, 4}));
}
