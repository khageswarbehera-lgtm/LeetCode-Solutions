#include "lc_test.h"

namespace lctest {

bool current_test_failed = false;

vector<TestCase>& registry() {
    static vector<TestCase> tests;
    return tests;
}

int registerTest(const string& suite, const string& name, TestBody body) {
    registry().push_back(TestCase{suite, name, body});
    return 0;
}

void fail(const string& file, int line, const string& message) {
    current_test_failed = true;
    cout << "    " << file << ":" << line << ": " << message << "\n";
}

int runAll(const string& filter) {
    vector<TestCase>& tests = registry();
    sort(tests.begin(), tests.end(), [](const TestCase& a, const TestCase& b) {
        return a.suite != b.suite ? a.suite < b.suite : a.name < b.name;
    });

    int passed = 0;
    vector<string> failed;
    for (const TestCase& test : tests) {
        string full_name = test.suite + "." + test.name;
        if (!filter.empty() && full_name.find(filter) == string::npos) continue;
        cout << "[ RUN      ] " << full_name << "\n";
        current_test_failed = false;
        test.body();
        if (current_test_failed) {
            failed.push_back(full_name);
            cout << "[   FAILED ] " << full_name << "\n";
        } else {
            passed++;
            cout << "[       OK ] " << full_name << "\n";
        }
    }

    cout << "\n" << passed << " passed, " << failed.size() << " failed\n";
    for (const string& name : failed) cout << "[   FAILED ] " << name << "\n";
    return failed.empty() ? 0 : 1;
}

}  // namespace lctest
