#include "AddAnnotationVisitor.h"
#include "Directory.h"
#include "Agenda.h"
#include "Minutes.h"
#include "GenericDocument.h"
#include "AnnotationDecorator.h"

AddAnnotationVisitor::AddAnnotationVisitor(std::string annotation, std::string dateTime)
	: m_annotation(annotation), m_dateTime(dateTime)
{
}

AbsDirectoryComponent& AddAnnotationVisitor::processDirectory(const Directory& directory)
{
	Directory * ptr_collectionDirectory = new Directory(directory.getName());
	for (auto it = directory.cbegin(); it != directory.cend(); ++it)
		ptr_collectionDirectory->addDirectoryComponent(it->accept(*this));
	return *ptr_collectionDirectory;
}

AbsDirectoryComponent& AddAnnotationVisitor::processAgenda(const Agenda& agenda)
{
	AnnotationDecorator * ptr_decorator = new AnnotationDecorator(agenda, m_annotation, m_dateTime);
	return *ptr_decorator;
}

AbsDirectoryComponent& AddAnnotationVisitor::processMinutes(const Minutes& minutes)
{
	AnnotationDecorator* ptr_decorator = new AnnotationDecorator(minutes, m_annotation, m_dateTime);
	return *ptr_decorator;
}

AbsDirectoryComponent& AddAnnotationVisitor::processGenericDocument(const GenericDocument& genericDocument)
{
	AnnotationDecorator* ptr_decorator = new AnnotationDecorator(genericDocument, m_annotation, m_dateTime);
	return *ptr_decorator;
}

AbsDirectoryComponent& AddAnnotationVisitor::processAnnotationDecorator(const AnnotationDecorator& td)
{
	AnnotationDecorator* ptr_decorator = new AnnotationDecorator(td, m_annotation, m_dateTime);
	return *ptr_decorator;
}
