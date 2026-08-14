#include "lc_test.h"

namespace lc0017 {
#include "../0017-letter-combinations-of-a-phone-number/0017-letter-combinations-of-a-phone-number.cpp"
}
namespace lc0022 {
#include "../0022-generate-parentheses/0022-generate-parentheses.cpp"
}
namespace lc0037 {
#include "../0037-sudoku-solver/0037-sudoku-solver.cpp"
}
namespace lc0039 {
#include "../0039-combination-sum/0039-combination-sum.cpp"
}
namespace lc0040 {
#include "../0040-combination-sum-ii/0040-combination-sum-ii.cpp"
}
namespace lc0046 {
#include "../0046-permutations/0046-permutations.cpp"
}
namespace lc0051 {
#include "../0051-n-queens/0051-n-queens.cpp"
}
namespace lc0078 {
#include "../0078-subsets/0078-subsets.cpp"
}
namespace lc0079 {
#include "../0079-word-search/0079-word-search.cpp"
}
namespace lc0090 {
#include "../0090-subsets-ii/0090-subsets-ii.cpp"
}
namespace lc0131 {
#include "../0131-palindrome-partitioning/0131-palindrome-partitioning.cpp"
}
namespace lc0216 {
#include "../0216-combination-sum-iii/0216-combination-sum-iii.cpp"
}
namespace lc0282 {
#include "../0282-expression-add-operators/0282-expression-add-operators.cpp"
}
namespace lc3453 {
#include "../3453-generate-binary-strings-without-adjacent-zeros/3453-generate-binary-strings-without-adjacent-zeros.cpp"
}

using lctest::sorted;
using lctest::sortedNested;

TEST(LetterCombinations, TwoDigits) {
    EXPECT_EQ(sorted(lc0017::Solution().letterCombinations("23")),
              (vector<string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
}

TEST(LetterCombinations, EmptyInput) {
    EXPECT_TRUE(lc0017::Solution().letterCombinations("").empty());
}

TEST(LetterCombinations, SevenAndNineHaveFourLetters) {
    EXPECT_EQ(sorted(lc0017::Solution().letterCombinations("79")).size(), 16u);
}

TEST(GenerateParentheses, ThreePairs) {
    EXPECT_EQ(sorted(lc0022::Solution().generateParenthesis(3)),
              (vector<string>{"((()))", "(()())", "(())()", "()(())", "()()()"}));
}

TEST(GenerateParentheses, SinglePair) {
    EXPECT_EQ(lc0022::Solution().generateParenthesis(1), (vector<string>{"()"}));
}

TEST(SudokuSolver, SolvesClassicPuzzle) {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    lc0037::Solution().solveSudoku(board);
    EXPECT_EQ(board, (vector<vector<char>>{{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                                           {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                                           {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                                           {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                                           {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                                           {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                                           {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                                           {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                                           {'3', '4', '5', '2', '8', '6', '1', '7', '9'}}));
}

TEST(CombinationSum, ReusesCandidates) {
    vector<int> candidates = {2, 3, 6, 7};
    EXPECT_EQ(sortedNested(lc0039::Solution().combinationSum(candidates, 7)),
              (vector<vector<int>>{{2, 2, 3}, {7}}));
}

TEST(CombinationSum, NoCombinationReachesTarget) {
    vector<int> candidates = {2};
    EXPECT_TRUE(lc0039::Solution().combinationSum(candidates, 1).empty());
}

TEST(CombinationSumII, EachNumberUsedOnce) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    EXPECT_EQ(sortedNested(lc0040::Solution().combinationSum2(candidates, 8)),
              (vector<vector<int>>{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}));
}

TEST(CombinationSumII, DuplicateCandidatesAreDeduplicated) {
    vector<int> candidates = {2, 5, 2, 1, 2};
    EXPECT_EQ(sortedNested(lc0040::Solution().combinationSum2(candidates, 5)),
              (vector<vector<int>>{{1, 2, 2}, {5}}));
}

TEST(Permutations, ThreeDistinctValues) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(sorted(lc0046::Solution().permute(nums)),
              (vector<vector<int>>{
                  {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}));
}

TEST(Permutations, SingleValue) {
    vector<int> nums = {7};
    EXPECT_EQ(lc0046::Solution().permute(nums), (vector<vector<int>>{{7}}));
}

TEST(NQueens, FourQueensHasTwoSolutions) {
    EXPECT_EQ(sorted(lc0051::Solution().solveNQueens(4)),
              (vector<vector<string>>{{"..Q.", "Q...", "...Q", ".Q.."},
                                      {".Q..", "...Q", "Q...", "..Q."}}));
}

TEST(NQueens, ThreeQueensIsImpossible) {
    EXPECT_TRUE(lc0051::Solution().solveNQueens(3).empty());
}

TEST(NQueens, SingleQueen) {
    EXPECT_EQ(lc0051::Solution().solveNQueens(1), (vector<vector<string>>{{"Q"}}));
}

TEST(Subsets, PowerSetOfThree) {
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(sortedNested(lc0078::Solution().subsets(nums)),
              (vector<vector<int>>{{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}}));
}

TEST(Subsets, SingleElementHasEmptyAndSelf) {
    vector<int> nums = {0};
    EXPECT_EQ(sortedNested(lc0078::Solution().subsets(nums)), (vector<vector<int>>{{}, {0}}));
}

TEST(WordSearch, FindsWordAlongPath) {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    EXPECT_TRUE(lc0079::Solution().exist(board, "ABCCED"));
    EXPECT_TRUE(lc0079::Solution().exist(board, "SEE"));
}

TEST(WordSearch, RejectsWordNeedingCellReuse) {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    EXPECT_FALSE(lc0079::Solution().exist(board, "ABCB"));
}

TEST(WordSearch, SingleCellBoard) {
    vector<vector<char>> board = {{'a'}};
    EXPECT_TRUE(lc0079::Solution().exist(board, "a"));
    EXPECT_FALSE(lc0079::Solution().exist(board, "b"));
}

TEST(SubsetsII, DuplicateValuesProduceUniqueSubsets) {
    vector<int> nums = {1, 2, 2};
    EXPECT_EQ(sortedNested(lc0090::Solution().subsetsWithDup(nums)),
              (vector<vector<int>>{{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}}));
}

TEST(SubsetsII, AllElementsIdentical) {
    vector<int> nums = {3, 3, 3};
    EXPECT_EQ(sortedNested(lc0090::Solution().subsetsWithDup(nums)),
              (vector<vector<int>>{{}, {3}, {3, 3}, {3, 3, 3}}));
}

TEST(PalindromePartitioning, TwoPartitions) {
    EXPECT_EQ(sorted(lc0131::Solution().partition("aab")),
              (vector<vector<string>>{{"a", "a", "b"}, {"aa", "b"}}));
}

TEST(PalindromePartitioning, SingleCharacter) {
    EXPECT_EQ(lc0131::Solution().partition("a"), (vector<vector<string>>{{"a"}}));
}

TEST(CombinationSumIII, SingleValidTriple) {
    EXPECT_EQ(sortedNested(lc0216::Solution().combinationSum3(3, 7)),
              (vector<vector<int>>{{1, 2, 4}}));
}

TEST(CombinationSumIII, ThreeValidTriples) {
    EXPECT_EQ(sortedNested(lc0216::Solution().combinationSum3(3, 9)),
              (vector<vector<int>>{{1, 2, 6}, {1, 3, 5}, {2, 3, 4}}));
}

TEST(CombinationSumIII, TargetTooSmall) {
    EXPECT_TRUE(lc0216::Solution().combinationSum3(4, 1).empty());
}

TEST(ExpressionAddOperators, TwoExpressionsReachTarget) {
    EXPECT_EQ(sorted(lc0282::Solution().addOperators("123", 6)),
              (vector<string>{"1*2*3", "1+2+3"}));
}

TEST(ExpressionAddOperators, RespectsOperatorPrecedence) {
    EXPECT_EQ(sorted(lc0282::Solution().addOperators("232", 8)),
              (vector<string>{"2*3+2", "2+3*2"}));
}

TEST(ExpressionAddOperators, NoLeadingZeroOperands) {
    EXPECT_EQ(sorted(lc0282::Solution().addOperators("105", 5)),
              (vector<string>{"1*0+5", "10-5"}));
}

TEST(GenerateBinaryStrings, LengthThree) {
    EXPECT_EQ(sorted(lc3453::Solution().validStrings(3)),
              (vector<string>{"010", "011", "101", "110", "111"}));
}

TEST(GenerateBinaryStrings, LengthOne) {
    EXPECT_EQ(sorted(lc3453::Solution().validStrings(1)), (vector<string>{"0", "1"}));
}
