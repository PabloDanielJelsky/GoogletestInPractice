//	src/sut.cpp

#include "sut.h"

int SUT::foo(useconds_t param)
{
	return usleep(param);
}
