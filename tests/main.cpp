#include "lc_test.h"

// Usage: run_tests [substring filter, matched against "Suite.TestName"]
int main(int argc, char** argv) {
    string filter = argc > 1 ? argv[1] : "";
    return lctest::runAll(filter);
}
