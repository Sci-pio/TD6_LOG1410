#include "Register.h"
#include "Agenda.h"
#include "Minutes.h"
#include "GenericDocument.h"

Register::Register()
	: m_RegisterRoot("Top of tree structure")
{
	AbsDirectoryComponent& sept2022 = m_RegisterRoot.addDirectoryComponent(Directory("Reunion du 28 septembre 2022"));
	AbsDirectoryComponent& sept2022_OJ = sept2022.addDirectoryComponent(Agenda("OJ 2022-09-28", "Quebec", 1, 0.79f));
	AbsDirectoryComponent& sept2022_PV = sept2022.addDirectoryComponent(Minutes("PV 2022-09-28", "Quebec", 1, 0.79f));
	AbsDirectoryComponent& sept2022_liasse = sept2022.addDirectoryComponent(GenericDocument("Liasse 2022-09-28", "Quebec", 1, 0.79f));

	AbsDirectoryComponent& oct2022 = m_RegisterRoot.addDirectoryComponent(Directory("Diner d'automne 2022"));
	AbsDirectoryComponent& oct2022_invitation = oct2022.addDirectoryComponent(GenericDocument("Invitation au diner d'automne 2022", "Quebec", 1, 2.99f));

	AbsDirectoryComponent& nov2022 = m_RegisterRoot.addDirectoryComponent(Directory("Reunion du 2 novembre 2022"));
	AbsDirectoryComponent& nov2022_OJ = nov2022.addDirectoryComponent(Agenda("OJ 2022-11-02", "USA", 1, 1.49f));
	AbsDirectoryComponent& nov2022_PV = nov2022.addDirectoryComponent(Minutes("PV 2022-11-02", "Mexique", 170, 1.99f));
}


Register::~Register()
{
}

const AbsDocument* Register::findDocument(std::string documentName) const
{
	return m_RegisterRoot.findDocument(documentName);

}

std::ostream& operator<<(std::ostream& o, const Register& c)
{
	return o << c.m_RegisterRoot;
}