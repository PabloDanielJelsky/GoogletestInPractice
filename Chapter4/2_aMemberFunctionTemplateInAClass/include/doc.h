//	include/doc.h

#ifndef _DOC_H_
#define _DOC_H_

//	DOC - Depended-On Component (Code which is used by SUT)

#include <string>

class	TestClass_1 {};
class	TestClass_2 {};

class DOC
{
public:
	template<typename T>
	std::string foo(T param) { return "I'm foo"; }
};

#endif
