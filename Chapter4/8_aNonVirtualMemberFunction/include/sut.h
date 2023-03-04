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
template<class T>
class SUT
{
public:
	SUT(T& param) : doc(param) {}
	void foo() { std::cout << doc.foo() << std::endl; }

private:
	T&	doc;
};
#endif

#endif
