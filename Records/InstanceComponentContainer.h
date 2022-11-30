///////////////////////////////////////////////////////////
//  InstanceComponentContainer.h
//  Implementation of the Class InstanceComponentContainer
//  Created on:      2022-10-12
//  Based on previous material (2019-10-26)
///////////////////////////////////////////////////////////

#if !defined(__InstanceComponentCONTAINER_HEADER_)
#define __InstanceComponentCONTAINER_HEADER_

#include <memory>
#include <vector>

// Configuration du stockage des enfants des objets composites
using InstanceComponentPtr = std::unique_ptr<class AbsInstanceComponent>;
using InstanceComponentContainer = std::vector<InstanceComponentPtr>;
using InstanceComponentBaseIterator = InstanceComponentContainer::iterator;
using InstanceComponentBaseIterator_const = InstanceComponentContainer::const_iterator;

class InstanceComponentIterator : public InstanceComponentBaseIterator
{
public:
	InstanceComponentIterator(const InstanceComponentContainer::iterator& it) : InstanceComponentBaseIterator(it) {}

	// Operators to simplify access to InstanceComponents refered to by the iterator
	// for InstanceComponentIterator it;
	//    *it is the InstanceComponent
	//    it-> allows invoquing a method on the InstanceComponent
	class AbsInstanceComponent& operator*() { return *((*(InstanceComponentBaseIterator(*this))).get()); }
	class AbsInstanceComponent* operator->() { return (*(InstanceComponentBaseIterator(*this))).get(); }
};

class InstanceComponentIterator_const : public InstanceComponentBaseIterator_const
{
public:
	InstanceComponentIterator_const(const InstanceComponentContainer::const_iterator& it) : InstanceComponentBaseIterator_const(it) {}

	// Operators to simplify access to InstanceComponents refered to by the iterator
	// for InstanceComponentIterator it;
	//    *it is the InstanceComponent
	//    it-> allows invoquing a method on the InstanceComponent
	const class AbsInstanceComponent& operator*() { return *((*(InstanceComponentBaseIterator_const(*this))).get()); }
	const class AbsInstanceComponent* operator->() { return (*(InstanceComponentBaseIterator_const(*this))).get(); }
};

#endif // !defined(__InstanceComponentCONTAINER_HEADER_)
