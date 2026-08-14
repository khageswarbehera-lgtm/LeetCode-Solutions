#include "lc_test.h"

namespace lc0225 {
#include "../0225-implement-stack-using-queues/0225-implement-stack-using-queues.cpp"
}
namespace lc3859 {
#include "../3859-maximum-product-of-two-digits/3859-maximum-product-of-two-digits.cpp"
}

TEST(MyStack, PushPopIsLastInFirstOut) {
    lc0225::MyStack stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.empty());
}

TEST(MyStack, EmptyStackReturnsSentinel) {
    lc0225::MyStack stack;
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.pop(), -1);
    EXPECT_EQ(stack.top(), -1);
}

TEST(MyStack, InterleavedPushAndPop) {
    lc0225::MyStack stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.pop(), 2);
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.empty());
}

TEST(MaximumProductOfTwoDigits, LargestTwoDigits) {
    EXPECT_EQ(lc3859::Solution().maxProduct(31), 3);
    EXPECT_EQ(lc3859::Solution().maxProduct(124), 8);
}

TEST(MaximumProductOfTwoDigits, RepeatedLargestDigit) {
    EXPECT_EQ(lc3859::Solution().maxProduct(4321), 12);
    EXPECT_EQ(lc3859::Solution().maxProduct(99), 81);
}

TEST(MaximumProductOfTwoDigits, ZeroDigitsGiveZero) {
    EXPECT_EQ(lc3859::Solution().maxProduct(10), 0);
}
