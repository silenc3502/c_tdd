#include <iostream>
#include "sut.h"

int main(int argc, char **argv) {
	DOC doc;
	SUT sut(doc);

	if (sut.foo())
		std::cout << "Product" << std::endl;
	else
		std::cout << "GoogleTest" << std::endl;

	return 0;
}
