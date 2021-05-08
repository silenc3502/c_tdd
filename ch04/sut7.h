#include "doc7.h"

class SUT {
public:
	SUT(DOC &param) : doc(param) {}
	void foo() { cout << doc.foo() << endl; }

private:
	DOC& doc;
};
