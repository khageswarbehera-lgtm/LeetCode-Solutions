#pragma once

#include "leetcode.hpp"

namespace lc {

inline constexpr long long kMod = 1'000'000'007LL;

// Euclid's algorithm, iterative so large inputs cannot blow the stack.
inline long long gcdOf(long long a, long long b) {
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

// base^exponent modulo `mod`, by binary exponentiation.
inline long long powMod(long long base, long long exponent, long long mod = kMod) {
    long long result = 1 % mod;
    base %= mod;

    if (base < 0) {
        base += mod;
    }

    while (exponent > 0) {
        if (exponent & 1) {
            result = result * base % mod;
        }

        base = base * base % mod;
        exponent >>= 1;
    }

    return result;
}

}  // namespace lc
