/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr / nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Catalogue::Afficher() const
// Algorithme :
//  Appel de la méthode Afficher de chaque trajets du catalogue
{
#ifdef MAP
    cout << "Appel à la méthode Afficher de <Catalogue>" << endl;
#endif
    cout << "Affichage du Catalogue" << endl;
    for(unsigned i(0); i < tailleAct; ++i)
    {
      (*(mesTrajets)[i]).Afficher();
    }
    cout << "Fin de l'affichage du Catalogue" << endl;
} //----- Fin de Afficher

void Catalogue::AfficherResRecherche() const
// Algorithme :
//  Appel de la méthode Afficher de chaque trajets correspondant à la recherche
{
#ifdef MAP
    cout << "Appel à la méthode AfficherResRecherche de <Catalogue>" << endl;
#endif
    cout << "Affichage du résultat de la recherche" << endl;
    for(unsigned i(0); i < tailleResRecherche; ++i)
    {
        (*(resultat)[i]).Afficher();
    }
    cout << "Fin de l'affichage du résultat de la recherche" << endl;
} //----- Fin de Afficher

void Catalogue::Ajouter(Trajet* trajet)
// Algorithme :
//  Ajout d'un trajet au tableau avec réajustement u tableau si nécéssaire
{
#ifdef MAP
    cout << "Appel à la méthode Ajouter de <Catalogue>" << endl;
#endif
    if(tailleAct >= tailleMax)
    {
        this->Ajuster();
    }
    mesTrajets[tailleAct] = trajet;
    ++tailleAct;
} //----- Fin de Ajouter

void Catalogue::Rechercher(char* villeDep_, char* villeArr_)
// Algorithme :
//  Recherche tous les trajets du catalogue ayant pour ville de départ villeDep_ et ville d'arrivée villeArr_
//  et les ajoute au tableau contenant les trajets correspondant au résultat de la recherche
{
#ifdef MAP
    cout << "Appel à Rechercher() de <Catalogue>" << endl;
#endif
    tailleResRecherche = 0;
    for(unsigned i(0); i < tailleAct; ++i)
    {
        // cout << mesTrajets[i]->getVilleDep() << endl << mesTrajets[i]->getVilleArr() << endl;
        if(strcmp(mesTrajets[i]->getVilleDep(), villeDep_) == 0)
        {
            if(strcmp(mesTrajets[i]->getVilleArr(), villeArr_) == 0)
            {
                resultat[tailleResRecherche] = mesTrajets[i];
                ++tailleResRecherche;
            }
        }
    }
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur



Catalogue::Catalogue (unsigned tailleMax_)
    : tailleAct(0), tailleMax(tailleMax_)
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    mesTrajets = new Trajet*[tailleMax];
    resultat = new Trajet*[TAILLE_MAX_RECHERCHE];
    tailleResRecherche = 0;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//  Détruit les trajets du catalogue puis les tableaux mesTrajets et resultat
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    for(unsigned i(0); i < tailleAct; ++i)
    {
        delete *(mesTrajets + i);
    }
    delete [] mesTrajets;
    delete [] resultat;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Méthodes privées

void Catalogue::Ajuster()
// Algorithme :
//  Création d'un tableau 2 fois plus grand puis copie des différents pointeurs déjà présent dans le tableau de départ
//  Destruction du tableau de départ, mesTrajets correspond ensuite au nouveau tableau
{
#ifdef MAP
    cout << "Appel à la méthode Ajuster de <Catalogue>" << endl;
#endif
    tailleMax *= 2;
    Trajet** newTrajets = new Trajet*[tailleMax];
    for(unsigned i(0); i < tailleAct; ++i)
    {
        *newTrajets[i] = *mesTrajets[i];
    }
    delete [] *mesTrajets;
    *mesTrajets = *newTrajets;


} //----- Fin de Ajuster
