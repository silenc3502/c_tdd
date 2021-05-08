#include "doc2.h"

template <typename T>
class SUT {
public:
	SUT(T& param) : doc(param) {};
	void foo() {
		TestClass_1 ts1;
		TestClass_2 ts2;

		std::cout << doc.foo(ts1) << std::endl;
		std::cout << doc.foo(ts2) << std::endl;
	}

private:
	T& doc;
};
