//	src/main1.cpp

#include "doc1.h"
#include "sut1.h"

int main()
{
	DOC<int>	doc;
	SUT			sut(doc);

	sut.foo();

	return 0;
}
