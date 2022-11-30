/****************************************************************************
**
** Classe AnnotationDecorator
** Date: 2022-11-15
** Based on existing material (2021-11-22)
** 
****************************************************************************/

#ifndef _AnnotationDecorator_Header_
#define _AnnotationDecorator_Header_

#include <iostream>
#include "AbsDirectoryComponent.h"

class AnnotationDecorator : public AbsDirectoryComponent
{
public:
	AnnotationDecorator(const AbsDirectoryComponent& component, std::string annotation, std::string dateTime);
	AnnotationDecorator(const AnnotationDecorator& mdd);

	const AbsDirectoryComponent& getComponent() const { return *m_component; }
	AbsDirectoryComponent& getComponent() { return *m_component; }

	virtual AnnotationDecorator* clone(void) const;
	virtual AbsDirectoryComponent& accept(class AddAnnotationVisitor& v) const;

	virtual AbsDirectoryComponent& addDirectoryComponent(const AbsDirectoryComponent& member);
	virtual DirectoryComponentIterator begin();
	virtual DirectoryComponentIterator_const cbegin() const;
	virtual DirectoryComponentIterator_const cend() const;
	virtual DirectoryComponentIterator end();
	virtual void deleteDirectoryComponent(DirectoryComponentIterator_const child);

	virtual std::string getAnnotation() const { return m_annotation; }
	virtual std::string getDateTime() const { return m_dateTime; }
	virtual void setAnnotation(std::string annotation) { m_annotation = annotation; }
	virtual void setDateTime(std::string dateTime) { m_dateTime = dateTime; }

	virtual const class AbsDocument* findDocument(std::string documentName) const override;
	virtual std::ostream& printToStream(std::ostream& o) const;


protected:
	DirectoryComponentPtr m_component;
	std::string m_annotation;
	std::string m_dateTime;
};

#endif
