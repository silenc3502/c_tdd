#include "doc5.h"

class MyDOC {
public:
	virtual string Foo(int param) { return ::foo(param); }
};

class SUT {
public:
	SUT(MyDOC& param) : doc(param) {}
	void foo() { cout << doc.Foo(10) << endl; }

private:
	MyDOC& doc;
};
