///////////////////////////////////////////////////////////
//  Organization.cpp
//  Implementation of the Class Organization
//  Created on:      2022-10-12
//  Based on previous material (2022-03-19)
///////////////////////////////////////////////////////////

#include "Organization.h"

Organization::Organization(std::string title)
	: m_register("Sommet de l'arborescence"), m_instances("Assemblee des membres")
{
	initialize();
}

const AbsDocument& Organization::findDocument(std::string documentName) const
{
	const AbsDocument* document = m_register.findDocument(documentName);
	if (document == nullptr)
	{
		std::string document_not_found("Document non trouve: ");
		document_not_found += documentName;
		throw(std::domain_error(document_not_found));
	}
	return *document;
}

void Organization::addInstance(const Instance& ic)
{
	m_instances.addInstanceComponent(ic);
}

const Instance* Organization::findInstance(std::string keyword) const
{
	const Instance* foundInstance = nullptr;
	for (auto it = m_instances.cbegin(); it != m_instances.cend(); ++it)
	{
		if (it->getName() == keyword)
		{
			foundInstance = dynamic_cast<const Instance*>(&(*it));
			break;
		}
	}

	return foundInstance;
}

void Organization::initialize()
{
	std::cout << "Creation du registre LOG1410\n";
	AbsDirectoryComponent& sept2022_CAF = m_register.addDirectoryComponent(Directory("Reunion du comite audit/finances du 28 septembre 2022"));
	AbsDirectoryComponent& sept2022_CAF_OJ = sept2022_CAF.addDirectoryComponent(Agenda("OJ 2022-09-28", "2022-09-28"));
	AbsDirectoryComponent& sept2022_CAF_PV = sept2022_CAF.addDirectoryComponent(Minutes("PV 2022-09-28", "2022-09-28"));
	AbsDirectoryComponent& fy2022_etats_financiers_liasse = sept2022_CAF.addDirectoryComponent(
		AnnotationDecorator(
			AnnotationDecorator(
				GenericDocument("Etats financiers 2021-2022", "2022-09-28", "Etats financiers - PDF"),
				"Premier jet",
				"2022-09-21"
			),
			"Finalisation et signature",
			"2022-09-26"
		)
	);
	
	AbsDirectoryComponent& oct2022_diner = m_register.addDirectoryComponent(Directory("Diner d'automne 2022"));
	AbsDirectoryComponent& oct2022_invitation = oct2022_diner.addDirectoryComponent(GenericDocument("Invitation au diner d'automne 2022", "2022-10-06", "PNG"));

	AbsDirectoryComponent& nov2022_CA = m_register.addDirectoryComponent(Directory("Reunion du CA du 2 novembre 2022"));
	AbsDirectoryComponent& nov2022_CA_OJ = nov2022_CA.addDirectoryComponent(Agenda("OJ 2022-11-02", "2022-11-02"));
	AbsDirectoryComponent& nov2022_CA_PV = nov2022_CA.addDirectoryComponent(Minutes("PV 2022-11-02", "2022-11-02"));

	Directory nov2022_S_preApprobation("Reunion du Senat du 15 novembre 2022");
	nov2022_S_preApprobation.addDirectoryComponent(Agenda("OJ 2022-11-15", "2022-11-15"));
	nov2022_S_preApprobation.addDirectoryComponent(GenericDocument("Proposition de charte de l'etudiant", "2022-11-11", "PDF"));
	AddAnnotationVisitor v1("Approbation par le greffier du Senat", "2022-11-14");
	AbsDirectoryComponent& nov2022_S_approbationPartielle = nov2022_S_preApprobation.accept(v1);
	AddAnnotationVisitor v2("Approbation par le president du Senat", "2022-11-15");
	AbsDirectoryComponent& nov2022_S = m_register.addDirectoryComponent(nov2022_S_approbationPartielle.accept(v2));
	const AbsDirectoryComponent& nov2022_S_OJ = *(m_register.findDocument("OJ 2022-11-15"));
	const AbsDirectoryComponent& charte_etudiant = *(m_register.findDocument("Proposition de charte de l'etudiant"));

	std::cout << std::endl << "------------------------------" << std::endl;
	std::cout << "Le registre LOG1410:\n" << m_register;
	std::cout << "------------------------------" << std::endl << std::endl;

	Instance bd("Le Conseil d'administration de la Societe LOG1410");
	Instance ac("Comite audit/finances");
	ac.addInstanceComponent(Artifact("Ordre du jour, comite audit/finances 2022-09-28", sept2022_CAF_OJ));
	ac.addInstanceComponent(Artifact("Proces-verbal, comite audit/finances 2022-09-28", sept2022_CAF_PV));
	ac.addInstanceComponent(Artifact("Etats financiers 2021-2022 pour approbation par comite audit/finances", fy2022_etats_financiers_liasse));
	bd.addInstanceComponent(ac);
	Instance hr("Comite des ressources humaines");
	bd.addInstanceComponent(hr);
	bd.addInstanceComponent(Artifact("Ordre du jour, CA 2022-11-02", nov2022_CA_OJ));
	bd.addInstanceComponent(Artifact("Proces-verbal, CA 2022-11-02", nov2022_CA_PV));
	bd.addInstanceComponent(Artifact("Etats financiers 2021-2022 pour approbation par CA", fy2022_etats_financiers_liasse));

	Instance senate("Le Senat de la societe LOG1410");
	senate.addInstanceComponent(Artifact("Ordre du jour, Senat 2022-11-15", nov2022_S_OJ));
	senate.addInstanceComponent(Artifact("Proposition de charte de l'etudiant pour adoption par le Senat", charte_etudiant));
		
	m_instances.addInstanceComponent(bd);
	m_instances.addInstanceComponent(senate);
	m_instances.addInstanceComponent(Artifact("Invitation aux membres - diner d'automne 2022", oct2022_invitation));
	m_instances.addInstanceComponent(Artifact("Etats financiers 2021-2022 pour adoption par l'Assemblee annuelle", fy2022_etats_financiers_liasse));
	m_instances.addInstanceComponent(Artifact("Charte de l'etudiant adoptee par le Senat, pour depot a l'assemblee annuelle", charte_etudiant));

	std::cout << std::endl << "------------------------------" << std::endl;
	std::cout << "Recherche: 'Proposition de charte de l\'etudiant'" << std::endl;
	std::cout << *(m_register.findDocument("Proposition de charte de l'etudiant")) << std::endl;
	std::cout << "------------------------------" << std::endl << std::endl;


}

std::ostream& operator<<(std::ostream& o, const Organization& b)
{
	return o << b.m_instances;
}