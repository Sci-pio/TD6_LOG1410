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
	// À compléter pour copier toutes les instances de niveau inférieur contenues dans l'instance}
	for (auto& element : mdd.m_instanceContainer)
		addInstanceComponent(*element);
}

Instance* Instance::clone() const
{
	// À compléter pour construire un nouvel objet Instance en appelant le constructeur de copie
	return new Instance(*this); // À remplacer
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
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur des instances. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
	AbsInstanceComponent* memberCopyPtr = member.clone();
	m_instanceContainer.push_back(InstanceComponentPtr(memberCopyPtr));
	return *memberCopyPtr; // À remplacer 
}

void Instance::deleteInstanceComponent(InstanceComponentIterator_const child)
{
	// À compléter pour éliminer des instances l'élément auquel réfère l'itérateur
	m_instanceContainer.erase(child);
}

void Instance::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de l'instance
	for (auto it = m_instanceContainer.begin(); it != m_instanceContainer.end(); ++it)
		deleteInstanceComponent(it);
}

std::ostream& Instance::printToStream(std::ostream& o) const
{
	// À compléter pour imprimer sur un stream une instance et ses éléments
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
