///////////////////////////////////////////////////////////
//  AbsInstanceVisitor.h
//  Date: 2022-11-15
//  Based on previous material (2022-04-02)
///////////////////////////////////////////////////////////

#if !defined(_AbsInstanceVisitor_Header_)
#define _AbsInstanceVisitor_Header_

class AbsInstanceVisitor
{

public:
	AbsInstanceVisitor() {};
	virtual ~AbsInstanceVisitor() = default;

	virtual void processInstance(class Instance& instance) = 0;
	virtual void processArtifact(class Artifact& artifact) = 0;
};
#endif _AbsRecipeVisitor_Header_