// Record.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Organization.h"

int main()
{
    try {
        std::cout << "Creation de la Societe LOG1410\n";
        Organization log1410Instances("La Societe LOG1410");

        std::cout << "Recherche du Conseil d'administration de la Societe LOG1410\n";
        const Instance* boardPtr = log1410Instances.findInstance("Le Conseil d'administration de la Societe LOG1410");

        if (boardPtr != nullptr)
            std::cout << "Instance du CA trouvee!" << std::endl << "Voici l'instance: " << std::endl << *boardPtr << std::endl;
        else
            std::cout << "Pas d'instance du CA trouvee, veuillez verifier votre recherche." << std::endl;

        
        std::cout << "------------------------------" << std::endl;
        std::cout << "Impression de la structure des instances et des documents qui y sont references: " << std::endl << log1410Instances << std::endl;
    }

    catch (std::exception& e)
    {
        std::cerr << "Exception trouvee: " << e.what() << std::endl;
    }
}
