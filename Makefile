CXX ?= g++
# The solution files are LeetCode submissions, so warnings about their
# formatting habits (indentation, signed/unsigned comparisons) are just noise.
CXXFLAGS ?= -std=c++17 -O1 -g -Wall -Wno-sign-compare -Wno-unused-variable \
            -Wno-misleading-indentation -Itests
BUILD_DIR ?= build
SOURCES := tests/lc_test.cpp tests/main.cpp $(sort $(wildcard tests/test_*.cpp))
OBJECTS := $(patsubst tests/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
BINARY := $(BUILD_DIR)/run_tests

.PHONY: all test coverage clean

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: tests/%.cpp tests/lc_test.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run the whole suite, or a subset: make test FILTER=MaximumSubarray
test: $(BINARY)
	./$(BINARY) $(FILTER)

# Line coverage of the solution files exercised by the suite. Instrumented
# objects live in their own directory so they never get linked into the
# regular `make test` binary.
coverage:
	rm -rf build-coverage
	$(MAKE) test BUILD_DIR=build-coverage CXXFLAGS="$(CXXFLAGS) -O0 --coverage" LDFLAGS="--coverage"
	@gcov -r -o build-coverage $(SOURCES) >/dev/null 2>&1 || true
	@mkdir -p build-coverage/gcov && mv -f *.gcov build-coverage/gcov/ 2>/dev/null || true
	@python3 tests/coverage_report.py build-coverage/gcov

clean:
	rm -rf build build-coverage *.gcov
