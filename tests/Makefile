CXX ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall

SOURCES := $(sort $(wildcard *.test.cpp))
BINARIES := $(patsubst %.test.cpp,build/%,$(SOURCES))

.PHONY: test clean
test: $(BINARIES)
	@status=0; \
	for binary in $(BINARIES); do \
		echo "== $$binary"; \
		./$$binary > /dev/null || status=1; \
		./$$binary | tail -n 1; \
	done; \
	exit $$status

build/%: %.test.cpp $(wildcard ../common/*.hpp) test_util.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf build
