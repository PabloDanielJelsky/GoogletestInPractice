//	include/sut.h

#ifndef _SUT_H_
#define _SUT_H_

//	SUT - System Under Test (Code to be tested)

#include <iostream>
#include "doc.h"

#if 0 // code before changes
class SUT
{
public:
	SUT() {}
	void foo();
private:
	DOC	doc;
};
#else	//	code after changes to adapt to mock style
class SUT
{
public:
	SUT(DOC& param) : doc(param) {}
	void foo();

private:
	DOC&	doc;
};
#endif

#endif
