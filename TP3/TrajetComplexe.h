/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetComplexe> (fichier TrajetComplexe.h) ----------------
#if ! defined ( TRAJETCOMPLEXE_H )
#define TRAJETCOMPLEXE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include <fstream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetComplexe>
// Un trajet complexe permet de relier deux villes par le biais de plusieurs étapes/trajets
//
//------------------------------------------------------------------------

class TrajetComplexe : public Trajet
{
    //----------------------------------------------------------------- PUBLIC


public:
    //----------------------------------------------------- Méthodes publiques
    static bool listeCorrect(Trajet* ppListeTrajets[],const unsigned nbElem,const char* vDep,const char*vArr);
    // Mode d'emploi :
    //    Methode à appeler avant d'appeler le constructeur de TrajetComplexe pour vérifier si la liste de trajets (ppListeTrajets) est correct
    // Contrat :
    //    Retourne true si la liste de trajet est correctement ordonnée (on peut appeler le constructeur avec cette liste), false sinon

    virtual void EcrireTrajet(ofstream & fichier) const;

    virtual void Afficher() const;
    // Contrat :
    //    Permet d'afficher le trajet complexe

    //------------------------------------------------- Surcharge d'opérateurs


    //-------------------------------------------- Constructeurs - destructeur

    TrajetComplexe (Trajet* pplisteTrajets[], const unsigned fnbElem,const char* uneVilleDep,const char*uneVilleArr);
    // Mode d'emploi :
    //    Avant il faut appeler la methode listeCorrect et que la méthode est retournée TRUE
    // Contrat :
    //    Affecte à m_ppTrajet une liste de pointeurs de trajets (pplisteTrajets), à nbElem la valeur fnbElem, à villeDep la valeur uneVilleDep et à villeArr la valeur uneVilleArr
    virtual ~TrajetComplexe ( );
    // Contrat :
    //    Détruit l'objet TrajetComplexe

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    unsigned nbElem = 0; // nombre de Trajets composant le trajet complexe
    Trajet** m_ppTrajet; // liste de pointeurs pointant sur les trajets composant le trajet complexe
};

//-------------------------------- Autres définitions dépendantes de <TrajetComplexe>

#endif // TRAJETCOMPLEXE_H

