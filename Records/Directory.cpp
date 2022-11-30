#include <string>

#include "Directory.h"
#include "AbsDocument.h"
#include "AddAnnotationVisitor.h"

int Directory::m_indent = 0;

Directory::Directory(std::string name)
	: AbsDirectoryComponent(name)
{
}

Directory::Directory(const Directory& mdd)
	: AbsDirectoryComponent(mdd.m_name)
{
	// À compléter pour copier tous les éléments contenus dans le répertoire
	for (auto& element : mdd.m_documents)
		addDirectoryComponent(*element);
}

Directory* Directory::clone(void) const
{
	// À compléter pour construire un nouvel objet Directory en appelant le constructeur de copie
	return new Directory(*this); // À remplacer
}

AbsDirectoryComponent& Directory::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur de documents. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
	AbsDirectoryComponent* memberCopy = member.clone();
	m_documents.push_back(DirectoryComponentPtr(memberCopy));
	return *memberCopy; // À remplacer 
}

DirectoryComponentIterator Directory::begin()
{
	return m_documents.begin();
}

DirectoryComponentIterator_const Directory::cbegin() const
{
	return m_documents.cbegin();
}

DirectoryComponentIterator_const Directory::cend() const
{
	return m_documents.cend();
}

DirectoryComponentIterator Directory::end()
{
	return m_documents.end();
}

void Directory::deleteDirectoryComponent(DirectoryComponentIterator_const child)
{
	// À compléter pour éliminer du répertoire l'élément auquel réfère l'itérateur
	m_documents.erase(child);
}

void Directory::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments du répertoire
	for (auto it = m_documents.begin(); it != m_documents.end(); ++it)
		deleteDirectoryComponent(it);
}

const AbsDocument* Directory::findDocument(std::string productName) const
{
	// À compléter pour itérer sur les éléments contenus dans le répertoire à la recherche d'un document
	// portant le nom reçu en argument. Si aucun document n'est trouvé, on retourne nullptr
	//const AbsDocument* foundDocument = nullptr;
	for (auto& document : m_documents)
		if (auto element = dynamic_cast<AbsDocument*>(document.get())) {
			if (productName == element->getName())
				return element;
		} else {
			if (auto element = document->findDocument(productName))
				return element;
		}
	// À compléter
	return nullptr;
}

std::ostream& Directory::printToStream(std::ostream& o) const
{
	// À compléter pour imprimer sur un stream une catégorie et son contenu
	o << "Directory: " << getName() << std::endl; 
	m_indent++;
	for (auto& element : m_documents) {
		indent(o);
		o << *element << std::endl;
	}
	m_indent--;
	return o;
}

std::ostream& Directory::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}

// kamil
AbsDirectoryComponent& Directory::accept(AddAnnotationVisitor& v) const {
	return (v.processDirectory(*this));
}