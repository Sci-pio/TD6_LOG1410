///////////////////////////////////////////////////////////
//  DirectoryComponentContainer.h
//  Implementation of the Class DirectoryComponentContainer
//  Created on:      11-oct.-2022
//  Based on previous material (26-oct.-2019)
///////////////////////////////////////////////////////////

#if !defined(_DirectoryComponentContainer_Header_)
#define _DirectoryComponentContainer_Header_

#include <memory>
#include <list>

// Configuration du stockage des enfants des objets composites
using DirectoryComponentPtr = std::unique_ptr<class AbsDirectoryComponent>;
using DirectoryComponentContainer = std::list<DirectoryComponentPtr>;
using DirectoryComponentBaseIterator = DirectoryComponentContainer::iterator;
using DirectoryComponentBaseIterator_const = DirectoryComponentContainer::const_iterator;

class DirectoryComponentIterator : public DirectoryComponentBaseIterator
{
public:
	DirectoryComponentIterator(const DirectoryComponentContainer::iterator& it) : DirectoryComponentBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour DirectoryComponentIterator it;
	//    *it est l'objet 3D
	//    it-> permet d'invoquer une methode sur l'objet 3D
	class AbsDirectoryComponent& operator*() { return *((*(DirectoryComponentBaseIterator(*this))).get()); }
	class AbsDirectoryComponent* operator->() { return (*(DirectoryComponentBaseIterator(*this))).get(); }
};

class DirectoryComponentIterator_const : public DirectoryComponentBaseIterator_const
{
public:
	DirectoryComponentIterator_const(const DirectoryComponentContainer::const_iterator& it) : DirectoryComponentBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour DirectoryComponentIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 3D
	const class AbsDirectoryComponent& operator*() { return *((*(DirectoryComponentBaseIterator_const(*this))).get()); }
	const class AbsDirectoryComponent* operator->() { return (*(DirectoryComponentBaseIterator_const(*this))).get(); }
};

#endif // !defined(_DirectoryComponentContainer_Header_)
