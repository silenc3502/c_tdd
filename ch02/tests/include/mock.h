#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockDOC : public DOC {
public:
	MOCK_METHOD0(foo, int());
};
