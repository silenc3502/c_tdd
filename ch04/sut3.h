#include "doc3.h"

template <typename T>
class SUT {
public:
	SUT(T& param) : doc(param) {};
	void foo() {
		cout << doc.foo(2, 3) << endl;
		cout << doc.foo(2, 3.0) << endl;
		cout << doc.foo(2, '3') << endl;
	}

private:
	T& doc;
};
