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
	void foo()
	{
		std::cout << doc.foo(3) << std::endl;
		std::cout << doc.foo(3.0) << std::endl;
		std::cout << doc.foo('3') << std::endl;
	}
};
#else	//	code after changes to adapt to mock style
class MyDOC
{
public:
	template<typename T>
	std::string Foo(T param) { return ::foo<T>(param); }
};

template<typename T>
class SUT
{
public:
	SUT(T& param) : doc(param) {}
	void foo()
	{
		std::cout << doc.Foo(3) << std::endl;
		std::cout << doc.Foo(3.0) << std::endl;
		std::cout << doc.Foo('3') << std::endl;
	}

private:
	T&	doc;
};
#endif

#endif
