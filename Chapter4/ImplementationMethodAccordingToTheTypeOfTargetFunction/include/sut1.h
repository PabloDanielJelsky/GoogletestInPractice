//	include/sut1.h

#ifndef _SUT1_H_
#define _SUT1_H_

//	SUT - System Under Test (Code to be tested)

#include <iostream>
#include "doc1.h"

#if 0 // code before changes
class SUT
{
public:
	SUT() {}
	void foo();

private:
	DOC<int> doc;
};
#else	//	code after changes to adapt to mock style
class SUT
{
public:
	SUT(DOC<int>& param) : doc(param) {}
	void foo();

private:
	DOC<int>& doc;
};
#endif

#endif
