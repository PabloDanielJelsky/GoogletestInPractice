//	include/doc.h

#ifndef _DOC_H_
#define _DOC_H_

//	DOC - Depended-On Component (Code which is used by SUT)

#include <string>
template<typename T>

class DOC
{
public:
	virtual std::string foo(T param) { return "I'm foo"; }
};

#endif
