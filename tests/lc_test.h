// Minimal dependency-free unit test framework and LeetCode support types.
//
// Solution files in this repository are LeetCode submissions: they assume
// <bits/stdc++.h>, `using namespace std;` and the ListNode / TreeNode
// definitions provided by the judge. This header supplies all of that, so a
// solution can be pulled into a test translation unit with:
//
//     #include "lc_test.h"
//     namespace lc0053 {
//     #include "../0053-maximum-subarray/0053-maximum-subarray.cpp"
//     }
//
// The enclosing namespace keeps `Solution` from clashing between solutions
// linked into the same test binary.
#pragma once

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

namespace lctest {

// ---------------------------------------------------------------- formatting

inline string describe(const string& value) { return "\"" + value + "\""; }
inline string describe(const char* value) { return describe(string(value)); }
inline string describe(char value) { return "'" + string(1, value) + "'"; }
inline string describe(bool value) { return value ? "true" : "false"; }
inline string describe(int value) { return to_string(value); }
inline string describe(unsigned value) { return to_string(value); }
inline string describe(long value) { return to_string(value); }
inline string describe(unsigned long value) { return to_string(value); }
inline string describe(long long value) { return to_string(value); }
inline string describe(unsigned long long value) { return to_string(value); }
inline string describe(double value) { return to_string(value); }
inline string describe(const optional<int>& value) {
    return value.has_value() ? to_string(*value) : "null";
}

template <typename T>
string describe(const vector<T>& values);
template <typename A, typename B>
string describe(const pair<A, B>& value);

template <typename T>
string describe(const vector<T>& values) {
    string out = "[";
    for (size_t i = 0; i < values.size(); i++) {
        if (i) out += ",";
        out += describe(values[i]);
    }
    return out + "]";
}

template <typename A, typename B>
string describe(const pair<A, B>& value) {
    return "(" + describe(value.first) + "," + describe(value.second) + ")";
}

// ------------------------------------------------------------------ registry

using TestBody = void (*)();

struct TestCase {
    string suite;
    string name;
    TestBody body;
};

vector<TestCase>& registry();
int registerTest(const string& suite, const string& name, TestBody body);
int runAll(const string& filter);

// Set while a test body runs; failures mark it so the runner can report.
extern bool current_test_failed;

void fail(const string& file, int line, const string& message);

template <typename Actual, typename Expected>
void expectEq(const Actual& actual, const Expected& expected, const char* actual_expr,
              const char* expected_expr, const string& file, int line) {
    if (actual == expected) return;
    fail(file, line, string("expected ") + expected_expr + " == " + describe(expected) +
                         ", but " + actual_expr + " == " + describe(actual));
}

inline void expectTrue(bool value, const char* expr, const string& file, int line) {
    if (value) return;
    fail(file, line, string("expected ") + expr + " to be true");
}

inline void expectFalse(bool value, const char* expr, const string& file, int line) {
    if (!value) return;
    fail(file, line, string("expected ") + expr + " to be false");
}

inline void expectNear(double actual, double expected, double tolerance, const char* actual_expr,
                       const string& file, int line) {
    if (fabs(actual - expected) <= tolerance) return;
    fail(file, line, string("expected ") + actual_expr + " == " + describe(actual) +
                         " to be within " + describe(tolerance) + " of " + describe(expected));
}

// ------------------------------------------------------- LeetCode structures

// Builds a singly linked list; the caller owns it (see freeList).
inline ListNode* buildList(const vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

inline vector<int> listToVector(ListNode* head) {
    vector<int> values;
    for (ListNode* node = head; node != nullptr; node = node->next) values.push_back(node->val);
    return values;
}

inline ListNode* nodeAt(ListNode* head, int index) {
    for (int i = 0; i < index && head != nullptr; i++) head = head->next;
    return head;
}

inline void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

// Level-order description of a tree, using nullopt for missing children, the
// same way LeetCode prints trees (e.g. {3,9,20,nullopt,nullopt,15,7}).
using TreeSpec = vector<optional<int>>;

inline TreeNode* buildTree(const TreeSpec& spec) {
    if (spec.empty() || !spec[0].has_value()) return nullptr;
    TreeNode* root = new TreeNode(*spec[0]);
    queue<TreeNode*> pending;
    pending.push(root);
    size_t index = 1;
    while (!pending.empty() && index < spec.size()) {
        TreeNode* node = pending.front();
        pending.pop();
        if (index < spec.size()) {
            if (spec[index].has_value()) {
                node->left = new TreeNode(*spec[index]);
                pending.push(node->left);
            }
            index++;
        }
        if (index < spec.size()) {
            if (spec[index].has_value()) {
                node->right = new TreeNode(*spec[index]);
                pending.push(node->right);
            }
            index++;
        }
    }
    return root;
}

inline TreeSpec treeToSpec(TreeNode* root) {
    TreeSpec spec;
    if (root == nullptr) return spec;
    queue<TreeNode*> pending;
    pending.push(root);
    while (!pending.empty()) {
        TreeNode* node = pending.front();
        pending.pop();
        if (node == nullptr) {
            spec.push_back(nullopt);
            continue;
        }
        spec.push_back(node->val);
        pending.push(node->left);
        pending.push(node->right);
    }
    while (!spec.empty() && !spec.back().has_value()) spec.pop_back();
    return spec;
}

inline vector<int> inorderValues(TreeNode* root) {
    vector<int> values;
    if (root == nullptr) return values;
    vector<int> left = inorderValues(root->left);
    vector<int> right = inorderValues(root->right);
    values.insert(values.end(), left.begin(), left.end());
    values.push_back(root->val);
    values.insert(values.end(), right.begin(), right.end());
    return values;
}

inline TreeNode* findNode(TreeNode* root, int value) {
    if (root == nullptr || root->val == value) return root;
    if (TreeNode* found = findNode(root->left, value)) return found;
    return findNode(root->right, value);
}

inline void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// --------------------------------------------------------------- comparisons

// Many solutions return combinations/subsets in an unspecified order; sorting
// makes the expectation independent of traversal order.
template <typename T>
vector<T> sorted(vector<T> values) {
    sort(values.begin(), values.end());
    return values;
}

template <typename T>
vector<vector<T>> sortedNested(vector<vector<T>> values) {
    for (vector<T>& inner : values) sort(inner.begin(), inner.end());
    sort(values.begin(), values.end());
    return values;
}

}  // namespace lctest

#define TEST(suite, name)                                                             \
    static void suite##_##name##_body();                                              \
    [[maybe_unused]] static const int suite##_##name##_registration =                                \
        lctest::registerTest(#suite, #name, &suite##_##name##_body);                   \
    static void suite##_##name##_body()

#define EXPECT_EQ(actual, expected) \
    lctest::expectEq((actual), (expected), #actual, #expected, __FILE__, __LINE__)
#define EXPECT_TRUE(value) lctest::expectTrue((value), #value, __FILE__, __LINE__)
#define EXPECT_FALSE(value) lctest::expectFalse((value), #value, __FILE__, __LINE__)
#define EXPECT_NEAR(actual, expected, tolerance) \
    lctest::expectNear((actual), (expected), (tolerance), #actual, __FILE__, __LINE__)
