//	include/doc.h

#ifndef _DOC_H_
#define _DOC_H_

//	DOC - Depended-On Component (Code which is used by SUT)

#include <string>

template<typename T>
std::string foo(T param) { return "I'm foo : " + std::to_string(param); }

#endif
