/****************************************************************************
**
** Classe AddAnnotationVisitor
** Author: p482457
** Date: 21-nov-2021
**
****************************************************************************/

#ifndef _AddAnnotationVisitor_Header_
#define _AddAnnotationVisitor_Header_

#include <string>
#include "AbsDirectoryComponent.h"

class AddAnnotationVisitor
{
public:
	AddAnnotationVisitor(std::string annotation, std::string dateTime);

	virtual AbsDirectoryComponent& processDirectory(const class Directory& directory);
	virtual AbsDirectoryComponent& processAgenda(const class Agenda& agenda);
	virtual AbsDirectoryComponent& processMinutes(const class Minutes& minutes);
	virtual AbsDirectoryComponent& processGenericDocument(const class GenericDocument& genericDocument);
	virtual AbsDirectoryComponent& processAnnotationDecorator(const class AnnotationDecorator& annotationDecorator);

protected:
//	class AbsDirectoryComponent& m_itemsAnnotated;
	std::string m_annotation;
	std::string m_dateTime;
};

#endif
