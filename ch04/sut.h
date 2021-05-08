#include "doc.h"

class SUT {
public:
	SUT(DOC<int>& param) : doc(param) {}
	void foo() {
		std::cout << doc.foo(1) << std::endl;
	}

private:
	DOC<int>& doc;
};
