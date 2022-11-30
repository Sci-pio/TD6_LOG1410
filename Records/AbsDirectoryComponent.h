/****************************************************************************
**
** Classe AbsDirectoryComponent
** Date: 2022-10-11
** Based on previous material (25-oct-2019)
**
****************************************************************************/

#ifndef _AbsDirectoryComponent_Header_
#define _AbsDirectoryComponent_Header_

#include <iostream>

#include "DirectoryComponentContainer.h"

class AbsDirectoryComponent
{
public:
	AbsDirectoryComponent(std::string name) : m_name(name) {};
	virtual AbsDirectoryComponent* clone(void) const = 0;
	virtual AbsDirectoryComponent& accept(class AddAnnotationVisitor& v) const = 0;

	virtual std::string getName(void) const { return m_name; };
	virtual void setName(std::string name) { m_name = name; };
	
	virtual AbsDirectoryComponent& addDirectoryComponent(const AbsDirectoryComponent& member) = 0;
	virtual DirectoryComponentIterator begin() = 0;
	virtual DirectoryComponentIterator_const cbegin() const = 0;
	virtual DirectoryComponentIterator_const cend() const = 0;
	virtual DirectoryComponentIterator end() = 0;
	virtual void deleteDirectoryComponent( DirectoryComponentIterator_const child ) = 0;

	virtual const class AbsDocument* findDocument(std::string documentName) const = 0;


protected:
	friend std::ostream& operator<<(std::ostream & o, const AbsDirectoryComponent & dc);
	virtual std::ostream& printToStream(std::ostream& o) const = 0;

	std::string m_name;
};

#endif
