//	src/main.cpp

#include "doc.h"
#include "sut.h"

int main()
{
	MyDOC		obj;
	SUT<MyDOC>	sut(obj);

	sut.foo();

	return 0;
}
