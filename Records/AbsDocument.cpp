/****************************************************************************
**
** Classe AbsDocument
** Date: 2021-10-11
** Based on previous material (2019-10-25)
**
****************************************************************************/

#include "AbsDocument.h"

// Define class static members
DirectoryComponentContainer AbsDocument::m_emptyContainer;

AbsDocument::AbsDocument(std::string name, std::string dateTime)
	: AbsDirectoryComponent(name), m_dateTime(dateTime)
{
}

AbsDirectoryComponent& AbsDocument::addDirectoryComponent(const AbsDirectoryComponent&)
{
	return *(*(m_emptyContainer.begin()));
}

DirectoryComponentIterator AbsDocument::begin()
{
	return m_emptyContainer.begin();
}

DirectoryComponentIterator_const AbsDocument::cbegin() const
{
	return m_emptyContainer.cbegin();
}

DirectoryComponentIterator_const AbsDocument::cend() const
{
	return m_emptyContainer.cend();
}

DirectoryComponentIterator AbsDocument::end()
{
	return m_emptyContainer.end();
}

void AbsDocument::deleteDirectoryComponent(DirectoryComponentIterator_const)
{
}

const AbsDocument* AbsDocument::findDocument(std::string documentName) const
{
	return (getName() == documentName) ? this : nullptr;
}

std::ostream& AbsDocument::printToStream(std::ostream& o) const
{
	return o << getName() << " (" << getDescription() << ") : " << getDateTime();
}

