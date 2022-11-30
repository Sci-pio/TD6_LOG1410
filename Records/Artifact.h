///////////////////////////////////////////////////////////
//  Artifact.h
//  Implementation of the Class Artifact
//  Created on:      2022-10-12
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#if !defined(_Artifact_Header_)
#define _Artifact_Header_

#include "AbsInstanceComponent.h"
#include "AbsDocument.h"

class Artifact : public AbsInstanceComponent
{

public:
	Artifact(std::string name, const AbsDirectoryComponent& document);
	virtual ~Artifact() = default;
	Artifact* clone() const override;

	virtual void accept(class AbsInstanceVisitor& v);

	virtual const AbsDirectoryComponent& getDocument() const;
	
protected:
	const AbsDirectoryComponent& m_document;

	std::ostream& printToStream(std::ostream& o) const;

};
#endif // !defined(_Artifact_Header_)
