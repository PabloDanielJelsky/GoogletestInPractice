//	src/main.cpp

#include "doc.h"
#include "sut.h"

int main()
{
	DOC<int>		doc;
	SUT<DOC<int>>	sut(doc);

	sut.foo();

	return 0;
}
