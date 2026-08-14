#include "lc_test.h"

namespace lc0094 {
#include "../0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp"
}
namespace lc0098 {
#include "../0098-validate-binary-search-tree/0098-validate-binary-search-tree.cpp"
}
namespace lc0100 {
#include "../0100-same-tree/0100-same-tree.cpp"
}
namespace lc0101 {
#include "../0101-symmetric-tree/0101-symmetric-tree.cpp"
}
namespace lc0102 {
#include "../0102-binary-tree-level-order-traversal/0102-binary-tree-level-order-traversal.cpp"
}
namespace lc0104 {
#include "../0104-maximum-depth-of-binary-tree/0104-maximum-depth-of-binary-tree.cpp"
}
namespace lc0110 {
#include "../0110-balanced-binary-tree/0110-balanced-binary-tree.cpp"
}
namespace lc0124 {
#include "../0124-binary-tree-maximum-path-sum/0124-binary-tree-maximum-path-sum.cpp"
}
namespace lc0144 {
#include "../0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp"
}
namespace lc0145 {
#include "../0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp"
}
namespace lc0199 {
#include "../0199-binary-tree-right-side-view/0199-binary-tree-right-side-view.cpp"
}
namespace lc0222 {
#include "../0222-count-complete-tree-nodes/0222-count-complete-tree-nodes.cpp"
}
namespace lc0230 {
#include "../0230-kth-smallest-element-in-a-bst/0230-kth-smallest-element-in-a-bst.cpp"
}
namespace lc0235 {
#include "../0235-lowest-common-ancestor-of-a-binary-search-tree/0235-lowest-common-ancestor-of-a-binary-search-tree.cpp"
}
namespace lc0450 {
#include "../0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp"
}
namespace lc0543 {
#include "../0543-diameter-of-binary-tree/0543-diameter-of-binary-tree.cpp"
}
namespace lc0572 {
#include "../0572-subtree-of-another-tree/0572-subtree-of-another-tree.cpp"
}
namespace lc0783 {
#include "../0783-search-in-a-binary-search-tree/0783-search-in-a-binary-search-tree.cpp"
}
namespace lc0784 {
#include "../0784-insert-into-a-binary-search-tree/0784-insert-into-a-binary-search-tree.cpp"
}
namespace lc1029 {
#include "../1029-vertical-order-traversal-of-a-binary-tree/1029-vertical-order-traversal-of-a-binary-tree.cpp"
}
namespace lc1475 {
#include "../1475-maximum-sum-bst-in-binary-tree/1475-maximum-sum-bst-in-binary-tree.cpp"
}

using lctest::buildTree;
using lctest::findNode;
using lctest::freeTree;
using lctest::inorderValues;
using lctest::treeToSpec;
using lctest::TreeSpec;

TEST(BinaryTreeInorderTraversal, RightSkewedTree) {
    TreeNode* root = buildTree({1, nullopt, 2, 3});
    EXPECT_EQ(lc0094::Solution().inorderTraversal(root), (vector<int>{1, 3, 2}));
    freeTree(root);
}

TEST(BinaryTreeInorderTraversal, EmptyTree) {
    EXPECT_TRUE(lc0094::Solution().inorderTraversal(nullptr).empty());
}

TEST(ValidateBinarySearchTree, ValidTree) {
    TreeNode* root = buildTree({2, 1, 3});
    EXPECT_TRUE(lc0098::Solution().isValidBST(root));
    freeTree(root);
}

TEST(ValidateBinarySearchTree, ViolationDeeperInTree) {
    TreeNode* root = buildTree({5, 1, 4, nullopt, nullopt, 3, 6});
    EXPECT_FALSE(lc0098::Solution().isValidBST(root));
    freeTree(root);
}

TEST(ValidateBinarySearchTree, DuplicateValueIsInvalid) {
    TreeNode* root = buildTree({2, 2, 3});
    EXPECT_FALSE(lc0098::Solution().isValidBST(root));
    freeTree(root);
}

TEST(SameTree, IdenticalTrees) {
    TreeNode* left = buildTree({1, 2, 3});
    TreeNode* right = buildTree({1, 2, 3});
    EXPECT_TRUE(lc0100::Solution().isSameTree(left, right));
    freeTree(left);
    freeTree(right);
}

TEST(SameTree, DifferentShape) {
    TreeNode* left = buildTree({1, 2});
    TreeNode* right = buildTree({1, nullopt, 2});
    EXPECT_FALSE(lc0100::Solution().isSameTree(left, right));
    freeTree(left);
    freeTree(right);
}

TEST(SameTree, BothEmpty) {
    EXPECT_TRUE(lc0100::Solution().isSameTree(nullptr, nullptr));
}

TEST(SymmetricTree, MirroredTree) {
    TreeNode* root = buildTree({1, 2, 2, 3, 4, 4, 3});
    EXPECT_TRUE(lc0101::Solution().isSymmetric(root));
    freeTree(root);
}

TEST(SymmetricTree, AsymmetricTree) {
    TreeNode* root = buildTree({1, 2, 2, nullopt, 3, nullopt, 3});
    EXPECT_FALSE(lc0101::Solution().isSymmetric(root));
    freeTree(root);
}

TEST(BinaryTreeLevelOrderTraversal, GroupsByDepth) {
    TreeNode* root = buildTree({3, 9, 20, nullopt, nullopt, 15, 7});
    EXPECT_EQ(lc0102::Solution().levelOrder(root),
              (vector<vector<int>>{{3}, {9, 20}, {15, 7}}));
    freeTree(root);
}

TEST(BinaryTreeLevelOrderTraversal, EmptyTree) {
    EXPECT_TRUE(lc0102::Solution().levelOrder(nullptr).empty());
}

TEST(MaximumDepthOfBinaryTree, CountsLevels) {
    TreeNode* root = buildTree({3, 9, 20, nullopt, nullopt, 15, 7});
    EXPECT_EQ(lc0104::Solution().maxDepth(root), 3);
    freeTree(root);
}

TEST(MaximumDepthOfBinaryTree, EmptyTree) {
    EXPECT_EQ(lc0104::Solution().maxDepth(nullptr), 0);
}

TEST(BalancedBinaryTree, BalancedTree) {
    TreeNode* root = buildTree({3, 9, 20, nullopt, nullopt, 15, 7});
    EXPECT_TRUE(lc0110::Solution().isBalanced(root));
    freeTree(root);
}

TEST(BalancedBinaryTree, UnbalancedTree) {
    TreeNode* root = buildTree({1, 2, 2, 3, 3, nullopt, nullopt, 4, 4});
    EXPECT_FALSE(lc0110::Solution().isBalanced(root));
    freeTree(root);
}

TEST(BinaryTreeMaximumPathSum, PathThroughRoot) {
    TreeNode* root = buildTree({1, 2, 3});
    EXPECT_EQ(lc0124::Solution().maxPathSum(root), 6);
    freeTree(root);
}

TEST(BinaryTreeMaximumPathSum, SkipsNegativeRoot) {
    TreeNode* root = buildTree({-10, 9, 20, nullopt, nullopt, 15, 7});
    EXPECT_EQ(lc0124::Solution().maxPathSum(root), 42);
    freeTree(root);
}

TEST(BinaryTreeMaximumPathSum, AllNegative) {
    TreeNode* root = buildTree({-3});
    EXPECT_EQ(lc0124::Solution().maxPathSum(root), -3);
    freeTree(root);
}

TEST(BinaryTreePreorderTraversal, RootFirst) {
    TreeNode* root = buildTree({1, nullopt, 2, 3});
    EXPECT_EQ(lc0144::Solution().preorderTraversal(root), (vector<int>{1, 2, 3}));
    freeTree(root);
}

TEST(BinaryTreePreorderTraversal, EmptyTree) {
    EXPECT_TRUE(lc0144::Solution().preorderTraversal(nullptr).empty());
}

TEST(BinaryTreePostorderTraversal, RootLast) {
    TreeNode* root = buildTree({1, nullopt, 2, 3});
    EXPECT_EQ(lc0145::Solution().postorderTraversal(root), (vector<int>{3, 2, 1}));
    freeTree(root);
}

TEST(BinaryTreePostorderTraversal, EmptyTree) {
    EXPECT_TRUE(lc0145::Solution().postorderTraversal(nullptr).empty());
}

TEST(BinaryTreeRightSideView, RightmostPerLevel) {
    TreeNode* root = buildTree({1, 2, 3, nullopt, 5, nullopt, 4});
    EXPECT_EQ(lc0199::Solution().rightSideView(root), (vector<int>{1, 3, 4}));
    freeTree(root);
}

TEST(BinaryTreeRightSideView, EmptyTree) {
    EXPECT_TRUE(lc0199::Solution().rightSideView(nullptr).empty());
}

TEST(CountCompleteTreeNodes, CountsEveryNode) {
    TreeNode* root = buildTree({1, 2, 3, 4, 5, 6});
    EXPECT_EQ(lc0222::Solution().countNodes(root), 6);
    freeTree(root);
}

TEST(CountCompleteTreeNodes, EmptyTree) {
    EXPECT_EQ(lc0222::Solution().countNodes(nullptr), 0);
}

TEST(KthSmallestElementInABst, SmallestValue) {
    TreeNode* root = buildTree({3, 1, 4, nullopt, 2});
    EXPECT_EQ(lc0230::Solution().kthSmallest(root, 1), 1);
    freeTree(root);
}

TEST(KthSmallestElementInABst, ThirdSmallestValue) {
    TreeNode* root = buildTree({5, 3, 6, 2, 4, nullopt, nullopt, 1});
    EXPECT_EQ(lc0230::Solution().kthSmallest(root, 3), 3);
    freeTree(root);
}

TEST(LowestCommonAncestorOfABst, AncestorIsRoot) {
    TreeNode* root = buildTree({6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5});
    TreeNode* found =
        lc0235::Solution().lowestCommonAncestor(root, findNode(root, 2), findNode(root, 8));
    EXPECT_EQ(found, root);
    freeTree(root);
}

TEST(LowestCommonAncestorOfABst, AncestorIsOneOfTheNodes) {
    TreeNode* root = buildTree({6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5});
    TreeNode* found =
        lc0235::Solution().lowestCommonAncestor(root, findNode(root, 2), findNode(root, 4));
    EXPECT_EQ(found, findNode(root, 2));
    freeTree(root);
}

TEST(DeleteNodeInABst, DeletesNodeWithTwoChildren) {
    TreeNode* root = buildTree({5, 3, 6, 2, 4, nullopt, 7});
    root = lc0450::Solution().deleteNode(root, 3);
    EXPECT_EQ(inorderValues(root), (vector<int>{2, 4, 5, 6, 7}));
    freeTree(root);
}

TEST(DeleteNodeInABst, DeletesLeaf) {
    TreeNode* root = buildTree({5, 3, 6, 2, 4, nullopt, 7});
    root = lc0450::Solution().deleteNode(root, 2);
    EXPECT_EQ(inorderValues(root), (vector<int>{3, 4, 5, 6, 7}));
    freeTree(root);
}

TEST(DeleteNodeInABst, MissingKeyLeavesTreeUnchanged) {
    TreeNode* root = buildTree({5, 3, 6, 2, 4, nullopt, 7});
    root = lc0450::Solution().deleteNode(root, 42);
    EXPECT_EQ(inorderValues(root), (vector<int>{2, 3, 4, 5, 6, 7}));
    freeTree(root);
}

TEST(DiameterOfBinaryTree, LongestPathBetweenLeaves) {
    TreeNode* root = buildTree({1, 2, 3, 4, 5});
    EXPECT_EQ(lc0543::Solution().diameterOfBinaryTree(root), 3);
    freeTree(root);
}

TEST(DiameterOfBinaryTree, SingleNode) {
    TreeNode* root = buildTree({1});
    EXPECT_EQ(lc0543::Solution().diameterOfBinaryTree(root), 0);
    freeTree(root);
}

TEST(SubtreeOfAnotherTree, MatchingSubtree) {
    TreeNode* root = buildTree({3, 4, 5, 1, 2});
    TreeNode* sub = buildTree({4, 1, 2});
    EXPECT_TRUE(lc0572::Solution().isSubtree(root, sub));
    freeTree(root);
    freeTree(sub);
}

TEST(SubtreeOfAnotherTree, ExtraChildBreaksMatch) {
    TreeNode* root = buildTree({3, 4, 5, 1, 2, nullopt, nullopt, nullopt, nullopt, 0});
    TreeNode* sub = buildTree({4, 1, 2});
    EXPECT_FALSE(lc0572::Solution().isSubtree(root, sub));
    freeTree(root);
    freeTree(sub);
}

TEST(SearchInABinarySearchTree, FindsSubtree) {
    TreeNode* root = buildTree({4, 2, 7, 1, 3});
    EXPECT_EQ(treeToSpec(lc0783::Solution().searchBST(root, 2)), (TreeSpec{2, 1, 3}));
    freeTree(root);
}

TEST(SearchInABinarySearchTree, MissingValue) {
    TreeNode* root = buildTree({4, 2, 7, 1, 3});
    EXPECT_EQ(lc0783::Solution().searchBST(root, 5), nullptr);
    freeTree(root);
}

TEST(InsertIntoABinarySearchTree, InsertsAsLeaf) {
    TreeNode* root = lc0784::Solution().insertIntoBST(buildTree({4, 2, 7, 1, 3}), 5);
    EXPECT_EQ(inorderValues(root), (vector<int>{1, 2, 3, 4, 5, 7}));
    freeTree(root);
}

TEST(InsertIntoABinarySearchTree, InsertsIntoEmptyTree) {
    TreeNode* root = lc0784::Solution().insertIntoBST(nullptr, 5);
    EXPECT_EQ(inorderValues(root), (vector<int>{5}));
    freeTree(root);
}

TEST(VerticalOrderTraversal, GroupsByColumn) {
    TreeNode* root = buildTree({3, 9, 20, nullopt, nullopt, 15, 7});
    EXPECT_EQ(lc1029::Solution().verticalTraversal(root),
              (vector<vector<int>>{{9}, {3, 15}, {20}, {7}}));
    freeTree(root);
}

TEST(VerticalOrderTraversal, TiesAreSortedByValue) {
    TreeNode* root = buildTree({1, 2, 3, 4, 6, 5, 7});
    EXPECT_EQ(lc1029::Solution().verticalTraversal(root),
              (vector<vector<int>>{{4}, {2}, {1, 5, 6}, {3}, {7}}));
    freeTree(root);
}

TEST(MaximumSumBstInBinaryTree, BestSubtreeIsNotTheRoot) {
    TreeNode* root = buildTree({1, 4, 3, 2, 4, 2, 5, nullopt, nullopt, nullopt, nullopt, nullopt,
                                nullopt, 4, 6});
    EXPECT_EQ(lc1475::Solution().maxSumBST(root), 20);
    freeTree(root);
}

TEST(MaximumSumBstInBinaryTree, SingleNodeSubtree) {
    TreeNode* root = buildTree({4, 3, nullopt, 1, 2});
    EXPECT_EQ(lc1475::Solution().maxSumBST(root), 2);
    freeTree(root);
}

TEST(MaximumSumBstInBinaryTree, AllNegativeSumsAreIgnored) {
    TreeNode* root = buildTree({-4, -2, -5});
    EXPECT_EQ(lc1475::Solution().maxSumBST(root), 0);
    freeTree(root);
}
