#include <string>

#include "Agenda.h"
#include "AddAnnotationVisitor.h"

Agenda::Agenda(std::string name, std::string dateTime)
	: AbsDocument(name, dateTime)
{
}

Agenda* Agenda::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Agenda en appelant le constructeur de copie
	return new Agenda(*this); // � remplacer
}

AbsDirectoryComponent& Agenda::accept(AddAnnotationVisitor& v) const {
	return(v.processAgenda(*this));
}