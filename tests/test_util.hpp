#pragma once

// Minimal harness for the shared-utility regression tests. Every test both
// checks the problem's documented examples and prints the results it computes
// for a deterministic set of random inputs, so the printed output of two
// revisions of a solution can be compared directly.

#include <random>

#include "../common/leetcode.hpp"

namespace test {

inline int failures = 0;

template <typename T>
void print(const T& value) {
    cout << value;
}

inline void print(const string& value) {
    cout << '"' << value << '"';
}

template <typename T>
void print(const vector<T>& values) {
    cout << '[';
    for (size_t i = 0; i < values.size(); i++) {
        if (i) cout << ',';
        print(values[i]);
    }
    cout << ']';
}

template <typename T>
void emit(const string& label, const T& value) {
    cout << label << " = ";
    print(value);
    cout << '\n';
}

template <typename T>
void expectEq(const T& actual, const T& expected, const string& what) {
    if (actual == expected) {
        return;
    }

    failures++;
    cout << "FAIL " << what << ": got ";
    print(actual);
    cout << ", want ";
    print(expected);
    cout << '\n';
}

inline mt19937& rng() {
    static mt19937 generator(12345);
    return generator;
}

inline int randomInt(int low, int high) {
    return uniform_int_distribution<int>(low, high)(rng());
}

inline string randomLowercase(int length, int alphabet = 26) {
    string s;
    for (int i = 0; i < length; i++) {
        s.push_back(static_cast<char>('a' + randomInt(0, alphabet - 1)));
    }
    return s;
}

inline vector<vector<int>> randomGrid(int rows, int cols, int low, int high) {
    vector<vector<int>> grid(rows, vector<int>(cols));
    for (auto& row : grid) {
        for (int& cell : row) {
            cell = randomInt(low, high);
        }
    }
    return grid;
}

inline int report() {
    cout << (failures == 0 ? "OK\n" : "FAILURES\n");
    return failures == 0 ? 0 : 1;
}

}  // namespace test
