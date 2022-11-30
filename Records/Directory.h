/****************************************************************************
**
** Classe Directory
** Author: p482457
** Date: 8-nov-2021
**
****************************************************************************/

#ifndef _Directory_Header_
#define _Directory_Header_

#include "AbsDocument.h"

class Directory : public AbsDirectoryComponent
{
public:
	Directory(std::string name);
	Directory(const Directory& mdd);
	virtual Directory* clone(void) const;
	AbsDirectoryComponent& accept(AddAnnotationVisitor& v) const;

	virtual AbsDirectoryComponent& addDirectoryComponent(const AbsDirectoryComponent& member);
	virtual DirectoryComponentIterator begin();
	virtual DirectoryComponentIterator_const cbegin() const;
	virtual DirectoryComponentIterator_const cend() const;
	virtual DirectoryComponentIterator end();
	virtual void deleteDirectoryComponent(DirectoryComponentIterator_const child);
	virtual void deleteAllComponents(void);

	const AbsDocument* findDocument(std::string documentName) const;

private:
	virtual std::ostream& printToStream(std::ostream& o) const;
	std::ostream& indent(std::ostream& o) const;

	DirectoryComponentContainer m_documents;
	static int m_indent;
};

#endif