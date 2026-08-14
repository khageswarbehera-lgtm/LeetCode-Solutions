#include "lc_test.h"

namespace lc0019 {
#include "../0019-remove-nth-node-from-end-of-list/0019-remove-nth-node-from-end-of-list.cpp"
}
namespace lc0023 {
#include "../0023-merge-k-sorted-lists/0023-merge-k-sorted-lists.cpp"
}
namespace lc0141 {
#include "../0141-linked-list-cycle/0141-linked-list-cycle.cpp"
}
namespace lc0142 {
#include "../0142-linked-list-cycle-ii/0142-linked-list-cycle-ii.cpp"
}
namespace lc0206 {
#include "../0206-reverse-linked-list/0206-reverse-linked-list.cpp"
}
namespace lc0234 {
#include "../0234-palindrome-linked-list/0234-palindrome-linked-list.cpp"
}
namespace lc0237 {
#include "../0237-delete-node-in-a-linked-list/0237-delete-node-in-a-linked-list.cpp"
}
namespace lc0908 {
#include "../0908-middle-of-the-linked-list/0908-middle-of-the-linked-list.cpp"
}

using lctest::buildList;
using lctest::freeList;
using lctest::listToVector;
using lctest::nodeAt;

TEST(RemoveNthNodeFromEndOfList, RemovesFromMiddle) {
    ListNode* head = lc0019::Solution().removeNthFromEnd(buildList({1, 2, 3, 4, 5}), 2);
    EXPECT_EQ(listToVector(head), (vector<int>{1, 2, 3, 5}));
    freeList(head);
}

TEST(RemoveNthNodeFromEndOfList, RemovesOnlyNode) {
    ListNode* head = lc0019::Solution().removeNthFromEnd(buildList({1}), 1);
    EXPECT_EQ(head, nullptr);
}

TEST(RemoveNthNodeFromEndOfList, RemovesTail) {
    ListNode* head = lc0019::Solution().removeNthFromEnd(buildList({1, 2}), 1);
    EXPECT_EQ(listToVector(head), (vector<int>{1}));
    freeList(head);
}

TEST(MergeKSortedLists, MergesThreeLists) {
    vector<ListNode*> lists = {buildList({1, 4, 5}), buildList({1, 3, 4}), buildList({2, 6})};
    ListNode* merged = lc0023::Solution().mergeKLists(lists);
    EXPECT_EQ(listToVector(merged), (vector<int>{1, 1, 2, 3, 4, 4, 5, 6}));
    for (ListNode* list : lists) freeList(list);
    freeList(merged);
}

TEST(MergeKSortedLists, NoListsReturnsEmpty) {
    vector<ListNode*> lists = {};
    EXPECT_EQ(lc0023::Solution().mergeKLists(lists), nullptr);
}

TEST(MergeKSortedLists, IgnoresEmptyLists) {
    vector<ListNode*> lists = {nullptr, buildList({2}), nullptr};
    ListNode* merged = lc0023::Solution().mergeKLists(lists);
    EXPECT_EQ(listToVector(merged), (vector<int>{2}));
    for (ListNode* list : lists) freeList(list);
    freeList(merged);
}

TEST(LinkedListCycle, DetectsCycle) {
    ListNode* head = buildList({3, 2, 0, -4});
    nodeAt(head, 3)->next = nodeAt(head, 1);
    EXPECT_TRUE(lc0141::Solution().hasCycle(head));
    nodeAt(head, 3)->next = nullptr;
    freeList(head);
}

TEST(LinkedListCycle, AcyclicListAndEmptyList) {
    ListNode* head = buildList({1, 2});
    EXPECT_FALSE(lc0141::Solution().hasCycle(head));
    EXPECT_FALSE(lc0141::Solution().hasCycle(nullptr));
    freeList(head);
}

TEST(LinkedListCycleII, ReturnsCycleEntry) {
    ListNode* head = buildList({3, 2, 0, -4});
    ListNode* entry = nodeAt(head, 1);
    nodeAt(head, 3)->next = entry;
    EXPECT_EQ(lc0142::Solution().detectCycle(head), entry);
    nodeAt(head, 3)->next = nullptr;
    freeList(head);
}

TEST(LinkedListCycleII, NoCycleReturnsNull) {
    ListNode* head = buildList({1, 2});
    EXPECT_EQ(lc0142::Solution().detectCycle(head), nullptr);
    freeList(head);
}

TEST(ReverseLinkedList, ReversesInPlace) {
    ListNode* head = lc0206::Solution().reverseList(buildList({1, 2, 3, 4, 5}));
    EXPECT_EQ(listToVector(head), (vector<int>{5, 4, 3, 2, 1}));
    freeList(head);
}

TEST(ReverseLinkedList, EmptyList) {
    EXPECT_EQ(lc0206::Solution().reverseList(nullptr), nullptr);
}

TEST(PalindromeLinkedList, EvenLengthPalindrome) {
    ListNode* head = buildList({1, 2, 2, 1});
    EXPECT_TRUE(lc0234::Solution().isPalindrome(head));
}

TEST(PalindromeLinkedList, NotPalindrome) {
    ListNode* head = buildList({1, 2});
    EXPECT_FALSE(lc0234::Solution().isPalindrome(head));
}

TEST(PalindromeLinkedList, OddLengthPalindrome) {
    ListNode* head = buildList({1, 2, 3, 2, 1});
    EXPECT_TRUE(lc0234::Solution().isPalindrome(head));
}

TEST(DeleteNodeInALinkedList, RemovesGivenNode) {
    ListNode* head = buildList({4, 5, 1, 9});
    lc0237::Solution().deleteNode(nodeAt(head, 1));
    EXPECT_EQ(listToVector(head), (vector<int>{4, 1, 9}));
    freeList(head);
}

TEST(MiddleOfTheLinkedList, OddLength) {
    ListNode* head = buildList({1, 2, 3, 4, 5});
    EXPECT_EQ(listToVector(lc0908::Solution().middleNode(head)), (vector<int>{3, 4, 5}));
    freeList(head);
}

TEST(MiddleOfTheLinkedList, EvenLengthReturnsSecondMiddle) {
    ListNode* head = buildList({1, 2, 3, 4, 5, 6});
    EXPECT_EQ(listToVector(lc0908::Solution().middleNode(head)), (vector<int>{4, 5, 6}));
    freeList(head);
}
