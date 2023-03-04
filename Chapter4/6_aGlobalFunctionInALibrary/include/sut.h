//	include/sut.h

#ifndef _SUT_H_
#define _SUT_H_

//	SUT - System Under Test (Code to be tested)

#include <unistd.h>

class SUT
{
public:
	SUT() {}
	int foo(useconds_t param);
};

#endif
