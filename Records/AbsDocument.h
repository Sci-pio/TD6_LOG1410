/****************************************************************************
**
** Classe AbsDocument
** Date: 2022-10-11
** Based on previous material (2021-11-08)
**
****************************************************************************/

#ifndef _AbsDocument_Header_
#define _AbsDocument_Header_

#include "AbsDirectoryComponent.h"

class AbsDocument : public AbsDirectoryComponent
{
public:
	AbsDocument(std::string name, std::string dateTime);

	std::string getDateTime() const { return m_dateTime; }
	void setDateTime( std::string dateTime ) { m_dateTime = dateTime;  }
	virtual std::string getDescription() const = 0;

	virtual AbsDirectoryComponent& addDirectoryComponent(const AbsDirectoryComponent& member);
	virtual DirectoryComponentIterator begin();
	virtual DirectoryComponentIterator_const cbegin() const;
	virtual DirectoryComponentIterator_const cend() const;
	virtual DirectoryComponentIterator end();
	virtual void deleteDirectoryComponent(DirectoryComponentIterator_const child);

	virtual const class AbsDocument* findDocument(std::string documentName) const override;
	virtual std::ostream& printToStream(std::ostream& o) const;

private:
	std::string m_dateTime;

	static DirectoryComponentContainer m_emptyContainer;
};

#endif
