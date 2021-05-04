PWD = $(shell pwd)

SOURCES := $(wildcard *.cpp)
TEST_TARGET = $(SOURCES:%.cpp=%)

GTEST_LIBRARY := -lgtest

.PHONY: clean
#.SILENT: product test clean

all: $(TEST_TARGET)

$(TEST_TARGET): %: %.cpp
	g++ -o $@ $< ${GTEST_LIBRARY} -lpthread

clean:
	rm $(TEST_TARGET)
