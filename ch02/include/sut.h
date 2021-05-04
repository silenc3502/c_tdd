#include "doc.h"

class SUT {
public:
	SUT(DOC& param) : doc(param) {}
	int foo();

private:
	DOC& doc;
};
