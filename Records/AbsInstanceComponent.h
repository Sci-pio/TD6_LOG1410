///////////////////////////////////////////////////////////
//  AbsInstanceComponent.h
//  Implementation of the Class AbsInstanceComponent
//  Created on:      2022-10-12
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#if !defined(_AbsInstanceComponent_Header_)
#define _AbsInstanceComponent_Header_

#include <iostream>
#include <string>

#include "InstanceComponentContainer.h"

class AbsInstanceComponent
{

public:

	AbsInstanceComponent(std::string name);
	virtual ~AbsInstanceComponent() = default;
	virtual AbsInstanceComponent* clone() const = 0;

	virtual void accept(class AbsInstanceVisitor& v) = 0;

	virtual AbsInstanceComponent& addInstanceComponent(const AbsInstanceComponent& member);
	virtual InstanceComponentIterator begin();
	virtual InstanceComponentIterator_const cbegin() const;
	virtual InstanceComponentIterator_const cend() const;
	virtual InstanceComponentIterator end();
	virtual void deleteInstanceComponent(InstanceComponentIterator_const child);

	virtual std::string getName() const { return m_name; }

protected:
	static int m_indent;
	std::ostream& indent(std::ostream& o) const;

	friend std::ostream& operator<<(std::ostream& o, const AbsInstanceComponent& ic);
	virtual std::ostream& printToStream(std::ostream& o) const = 0;

private:
	static InstanceComponentContainer m_emptyContainer;
	std::string m_name;
};
#endif // !defined(_AbsInstanceComponent_Header_)
