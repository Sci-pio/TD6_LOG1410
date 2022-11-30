///////////////////////////////////////////////////////////
//  CountArtifactsVisitor.h
//  Date: 2022-11-15
//  Based on previous material (2022-04-02)
///////////////////////////////////////////////////////////

#if !defined(_CountArtifactsVisitor_Header_)
#define _CountArtifactsVisitor_Header_

#include "AbsInstanceVisitor.h"

class CountArtifactsVisitor : public AbsInstanceVisitor
{

public:
	CountArtifactsVisitor();
	virtual ~CountArtifactsVisitor() = default;

	virtual void processInstance(class Instance& instance);
	virtual void processArtifact(class Artifact& artifact);

	virtual int getNbArtifacts() const { return m_nbArtifacts; };

private:
	int m_nbArtifacts;
};
#endif // !defined(_CountArtifactsVisitor_Header_)