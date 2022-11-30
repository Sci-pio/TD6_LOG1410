///////////////////////////////////////////////////////////
//  Artifact.cpp
//  Implementation of the Class Artifact
//  Created on:      2022-10-12
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#include "Artifact.h"
#include "AbsInstanceVisitor.h"

Artifact::Artifact(std::string name, const AbsDirectoryComponent& document)
	: AbsInstanceComponent(name), m_document(document)
{
}

Artifact* Artifact::clone() const
{
	// À compléter pour construire un nouvel objet Artifact en appelant le constructeur de copie
	return new Artifact(*this); // À remplacer
}

const AbsDirectoryComponent& Artifact::getDocument() const
{
	return m_document;
}

std::ostream& Artifact::printToStream(std::ostream& o) const
{
	// À compléter pour imprimer sur un stream le nom de l'artefact ainsi que le nom du document qui y est reference.
	o << "Artifact: " << getName() << std::endl;
	indent(o);
	o << "    --> Document: " << getDocument() << std::endl;
	return o;
}

//kamil
void Artifact::accept(AbsInstanceVisitor& v) {
	v.processArtifact(*this);
}

