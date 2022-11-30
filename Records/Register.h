/****************************************************************************
**
** Classe Register
** Author: p482457
** Date: 2022-10-12
** Based on previous material (2021-11-08)
**
****************************************************************************/

#ifndef _Register_Header_
#define _Register_Header_

#include "Directory.h"
#include "AbsDocument.h"

std::ostream& operator << (std::ostream& o, const class Register& c);

class Register
{
public:
	Register();
	virtual ~Register();

	const AbsDocument* findDocument(std::string documentName) const;

private:
	friend std::ostream& operator<<(std::ostream & o, const Register& c);
	Directory m_RegisterRoot;
};

#endif

