#include "doc4.h"

class MyDOC {
public:
	template <typename T>
	string Foo(T param) { return ::foo<T>(param); }
};

template <typename T>
class SUT {
public:
	SUT(T& param) : doc(param) {};
	void foo() {
		cout << doc.Foo(3) << endl;
		cout << doc.Foo(3.0) << endl;
		cout << doc.Foo('3') << endl;
	}

private:
	T& doc;
};
