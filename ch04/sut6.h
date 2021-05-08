#include <unistd.h>

class SUT {
public:
	SUT() {}
	int foo(useconds_t param) { return usleep(param); }
};
