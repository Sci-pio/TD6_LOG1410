///////////////////////////////////////////////////////////
//  FindDocumentVisitor.h
//  Date: 2022-11-15
//  Based on previous material (2022-04-02)
///////////////////////////////////////////////////////////

#if !defined(_FindDocumentVisitor_Header_)
#define _FindDocumentVisitor_Header_

#include <list>
#include <string>

#include "AbsInstanceVisitor.h"
#include "InstanceComponentContainer.h"

using FoundArtifactIterator = std::list<InstanceComponentIterator>::iterator;
using FoundArtifactIterator_const = std::list<InstanceComponentIterator>::const_iterator;

class FindDocumentVisitor : public AbsInstanceVisitor
{
public:
	FindDocumentVisitor(const char* documentName);
	virtual ~FindDocumentVisitor() = default;

	virtual void processInstance(class Instance& instance);
	virtual void processArtifact(class Artifact& artifact);

	virtual int getNumberFound() const { return m_artifactsFound.size(); }
	virtual FoundArtifactIterator begin();
	virtual FoundArtifactIterator_const cbegin() const;
	virtual FoundArtifactIterator_const cend() const;
	virtual FoundArtifactIterator end();
	virtual void reset();

private:
	std::string m_searchedName;
	InstanceComponentIterator* m_currentIterator;
	std::list<InstanceComponentIterator> m_artifactsFound;
};
#endif // !defined(_FindDocumentVisitor_Header_)
