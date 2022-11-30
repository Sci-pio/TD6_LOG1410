///////////////////////////////////////////////////////////
//  Instance.h
//  Implementation of the Class Instance
//  Created on:      2022-10-14
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#if !defined(_INSTANCE__INCLUDED_)
#define _INSTANCE__INCLUDED_

#include "Artifact.h"

class Instance : public AbsInstanceComponent
{

public:
	Instance(std::string name);
	virtual ~Instance() = default;
	Instance(const Instance& mdd);

	virtual Instance* clone() const;

	virtual void accept(class AbsInstanceVisitor& v);

	virtual InstanceComponentIterator begin() override;
	virtual InstanceComponentIterator_const cbegin() const override;
	virtual InstanceComponentIterator_const cend() const override;
	virtual InstanceComponentIterator end() override;

	virtual AbsInstanceComponent& addInstanceComponent(const AbsInstanceComponent& member) override;
	virtual void deleteInstanceComponent(InstanceComponentIterator_const child) override;
	virtual void deleteAllComponents(void);

	std::ostream& printToStream(std::ostream& o) const;

private:
	InstanceComponentContainer m_instanceContainer;

};
#endif // !defined(_INSTANCE__INCLUDED_)
