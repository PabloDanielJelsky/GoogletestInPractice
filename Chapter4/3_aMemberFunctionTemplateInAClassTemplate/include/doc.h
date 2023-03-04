//	include/doc.h

#ifndef _DOC_H_
#define _DOC_H_

//	DOC - Depended-On Component (Code which is used by SUT)

#include <string>

template<typename T>
class DOC
{
public:
	template<typename U>
	std::string foo(T param_1, U param_2)
	{
		return "I'm foo : " + std::to_string(param_1) + ", " + std::to_string(param_2);
	}
};

#endif
