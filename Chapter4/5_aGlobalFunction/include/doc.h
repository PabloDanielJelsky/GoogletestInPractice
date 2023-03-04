//	include/doc.h

#ifndef _DOC_H_
#define _DOC_H_

//	DOC - Depended-On Component (Code which is used by SUT)

#include <string>

static std::string foo(int param) { return "I'm foo : " + std::to_string(param); }

#endif
