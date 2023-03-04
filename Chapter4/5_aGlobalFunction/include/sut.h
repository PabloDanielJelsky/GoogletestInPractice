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
};
#else	//	code after changes to adapt to mock style
class MyDOC
{
public:
	virtual std::string Foo(int param) { return ::foo(param); }
};

class SUT
{
public:
	SUT(MyDOC& param) : doc(param) {}
	void foo();

private:
	MyDOC&	doc;
};
#endif

#endif
