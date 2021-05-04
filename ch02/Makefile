PWD = $(shell pwd)

INCLUDE := -Iinclude
SOURCES := $(wildcard src/*.cpp)

GTEST_INCLUDE := -Itests/include
GTEST_SOURCES := $(filter-out src/main.cpp, $(SOURCES)) $(wildcard tests/src/*.cpp)
GTEST_LIBRARY := -lgtest -lgmock

.PHONY: clean
#.SILENT: product test clean

all: product test

product: $(SOURCES)
	g++ -o product $^ ${INCLUDE}

test: $(GTEST_SOURCES)
	g++ -o gtest $^ ${INCLUDE} ${GTEST_INCLUDE} ${GTEST_LIBRARY} -lpthread

clean:
	rm product gtest
