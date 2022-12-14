///////////////////////////////////////////////////////////
//  Instance.cpp
//  Implementation of the Class Instance
//  Created on:      2022-10-14
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#include "AbsInstanceVisitor.h"
#include "Instance.h"

Instance::Instance(std::string name)
    : AbsInstanceComponent(name)
{
}

Instance::Instance(const Instance& mdd)
	: AbsInstanceComponent(mdd.getName())
{
	// ? compl?ter pour copier toutes les instances de niveau inf?rieur contenues dans l'instance}
	for (auto& element : mdd.m_instanceContainer)
		addInstanceComponent(*element);
}

Instance* Instance::clone() const
{
	// ? compl?ter pour construire un nouvel objet Instance en appelant le constructeur de copie
	return new Instance(*this); // ? remplacer
}


InstanceComponentIterator Instance::begin() {

	return m_instanceContainer.begin();
}


InstanceComponentIterator_const Instance::cbegin() const {

	return m_instanceContainer.cbegin();
}


InstanceComponentIterator_const Instance::cend() const
{
	return m_instanceContainer.cend();
}

InstanceComponentIterator Instance::end()
{
	return  m_instanceContainer.end();
}

AbsInstanceComponent& Instance::addInstanceComponent(const AbsInstanceComponent& member)
{
	// ? compl?ter pour construire par clonage une copie de l'objet re?u en param?tre
	// et l'ins?rer dans le conteneur des instances. On retourne une r?f?rence ? l'objet
	// qui vient d'?tre ins?r? dans le conteneur.
	AbsInstanceComponent* memberCopyPtr = member.clone();
	m_instanceContainer.push_back(InstanceComponentPtr(memberCopyPtr));
	return *memberCopyPtr; // ? remplacer 
}

void Instance::deleteInstanceComponent(InstanceComponentIterator_const child)
{
	// ? compl?ter pour ?liminer des instances l'?l?ment auquel r?f?re l'it?rateur
	m_instanceContainer.erase(child);
}

void Instance::deleteAllComponents(void)
{
	// ? compl?ter pour ?liminer tous les ?l?ments de l'instance
	for (auto it = m_instanceContainer.begin(); it != m_instanceContainer.end(); ++it)
		deleteInstanceComponent(it);
}

std::ostream& Instance::printToStream(std::ostream& o) const
{
	// ? compl?ter pour imprimer sur un stream une instance et ses ?l?ments
	o << getName() << std::endl;
	int i = 0;
	m_indent++;
	for (auto& instance : m_instanceContainer) {
		indent(o);
		o << ++i << " " << *instance;
	}
	m_indent--;
	return o;
}

//kamil
void Instance::accept(class AbsInstanceVisitor& v) {
	v.processInstance(*this);
}
