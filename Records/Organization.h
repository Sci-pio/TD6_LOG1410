///////////////////////////////////////////////////////////
//  Organization.h
//  Implementation of the Class Organization
//  Created on:      2022-10-12
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#if !defined(_Organization_Header_)
#define _Organization_Header_

#include "Instance.h"
#include "Directory.h"
#include "Artifact.h"
#include "Agenda.h"
#include "Minutes.h"
#include "GenericDocument.h"
#include "Artifact.h"
#include "AddAnnotationVisitor.h"
#include "AnnotationDecorator.h"

class Organization
{

public:
	Organization(std::string title);
	virtual ~Organization() = default;

	const AbsDocument& findDocument(std::string documentName) const;

	virtual void addInstance(const Instance& ic);
	const Instance* findInstance(std::string keyword) const;

private:
	void initialize();

	Directory m_register;
	Instance m_instances;

	friend std::ostream& operator<<(std::ostream& o, const Organization& b);
};
#endif // !defined(_Organization_Header_)
