///////////////////////////////////////////////////////////
//  AbsInstanceComponent.cpp
//  Implementation of the Class AbsInstanceComponent
//  Created on:      2022-10-12
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#include "AbsInstanceComponent.h"

int AbsInstanceComponent::m_indent = 0;
InstanceComponentContainer AbsInstanceComponent::m_emptyContainer;

AbsInstanceComponent::AbsInstanceComponent(std::string name)
	: m_name(name) {}

std::ostream& AbsInstanceComponent::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}

std::ostream& operator<<(std::ostream& o, const AbsInstanceComponent& ic)
{
	return  ic.printToStream(o);
}

AbsInstanceComponent& AbsInstanceComponent::addInstanceComponent(const AbsInstanceComponent& member)
{
	return  *(*(m_emptyContainer.begin()));
}

InstanceComponentIterator AbsInstanceComponent::begin()
{
	return m_emptyContainer.begin();
}

InstanceComponentIterator_const AbsInstanceComponent::cbegin() const
{
	return m_emptyContainer.cbegin();
}

InstanceComponentIterator AbsInstanceComponent::end()
{
	return m_emptyContainer.end();
}

void AbsInstanceComponent::deleteInstanceComponent(InstanceComponentIterator_const child)
{
}

InstanceComponentIterator_const AbsInstanceComponent::cend() const
{
	return m_emptyContainer.cend();
}
