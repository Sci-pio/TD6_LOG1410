/****************************************************************************
**
** Classe AnnotationDecorator
** Date: 2022-11-15
** Based on existing material (2021-11-22)
**
****************************************************************************/

#include "AnnotationDecorator.h"
#include "AddAnnotationVisitor.h"


AnnotationDecorator::AnnotationDecorator(const AbsDirectoryComponent& component, std::string annotation, std::string dateTime)
	: AbsDirectoryComponent(component.getName()), m_component(component.clone()), m_annotation(annotation), m_dateTime(dateTime)
{
}

AnnotationDecorator::AnnotationDecorator(const AnnotationDecorator& mdd)
	: AbsDirectoryComponent(mdd.getName()), m_component(DirectoryComponentPtr(mdd.m_component->clone())), m_annotation(mdd.getAnnotation()), m_dateTime(mdd.getDateTime())
{
}

AnnotationDecorator* AnnotationDecorator::clone(void) const
{
	// À COMPLÉTER
	return new AnnotationDecorator(*this);
}

AbsDirectoryComponent& AnnotationDecorator::accept(AddAnnotationVisitor& v) const
{
	// À COMPLÉTER;
	return v.processAnnotationDecorator(*this);
}


AbsDirectoryComponent& AnnotationDecorator::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	return m_component->addDirectoryComponent(member);
}

DirectoryComponentIterator AnnotationDecorator::begin()
{
	return m_component->begin();
}

DirectoryComponentIterator_const AnnotationDecorator::cbegin() const
{
	return m_component->cbegin();
}

DirectoryComponentIterator_const AnnotationDecorator::cend() const
{
	return m_component->cend();
}

DirectoryComponentIterator AnnotationDecorator::end()
{
	return m_component->end();
}

void AnnotationDecorator::deleteDirectoryComponent(DirectoryComponentIterator_const child)
{
	m_component->deleteDirectoryComponent(child);
}

const class AbsDocument* AnnotationDecorator::findDocument(std::string documentName) const
{
	return m_component->findDocument(documentName);
}

std::ostream& AnnotationDecorator::printToStream(std::ostream& o) const
{
	return o
		<< *m_component
		<< " --> ["
		<< getDateTime()
		<< " : " << getAnnotation()
		<< "]";
}

