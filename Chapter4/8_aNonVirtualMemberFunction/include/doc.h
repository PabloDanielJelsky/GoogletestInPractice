//	include/doc.h

#ifndef _DOC_H_
#define _DOC_H_

//	DOC - Depended-On Component (Code which is used by SUT)

#include <string>

class DOC final
{
public:
	std::string foo() { return "I'm foo"; }
};

#endif
