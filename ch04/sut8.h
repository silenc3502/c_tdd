#include "doc8.h"

template <class T>
class SUT {
public:
	SUT(T& param) : doc(param) {}
	void foo() { cout << doc.foo() << endl; }

private:
	T& doc;
};
