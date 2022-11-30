/****************************************************************************
**
** Classe Agenda
** Date: 2022-10-11
** Based on previous material (2021-11-08)
**
****************************************************************************/

#ifndef _Agenda_Header_
#define _Agenda_Header_

#include "AbsDocument.h"

static const std::string descriptionAgenda = "Agenda";

class Agenda : public AbsDocument
{
public:
	Agenda(std::string name, std::string dateTime);
	virtual ~Agenda() {}
	virtual Agenda* clone(void) const;
	AbsDirectoryComponent& accept(AddAnnotationVisitor& v) const;

	std::string getDescription() const { return descriptionAgenda; }
};

#endif
