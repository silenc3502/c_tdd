PWD = $(shell pwd)

GTEST_LIBS = -lgtest -lpthread
BASIC_LIBS =

TEST_MODULE = add_test.cpp
SUB_MODULE = add.c

TEST_SRCS = $(wildcard $(TEST_MODULE))
TEST_OBJECT = $(TEST_SRCS:%.cpp=%.o)
TEST_TARGET = $(TEST_SRCS:%.cpp=%)

SUB_SRCS = $(wildcard $(SUB_MODULE))
SUB_OBJECT = $(SUB_SRCS:%.c=%.o)

OBJECTS += $(SUB_OBJECT)
OBJECTS += $(TEST_OBJECT)

all: $(TEST_TARGET) $(SUB_OBJ)
	@echo $(TEST_TARGET) $(SUB_TARGET)

$(TEST_TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(GTEST_LIBS)

$(TEST_OBJECT): %.o: %.cpp
	$(CXX) -c $< $(GTEST_LIBS)

$(SUB_OBJECT): %.o: %.c
	$(CC) -c $< $(BASIC_LIBS)

clean:
	rm -rf $(TEST_OBJECT) $(TEST_TARGET) $(SUB_OBJECT)
