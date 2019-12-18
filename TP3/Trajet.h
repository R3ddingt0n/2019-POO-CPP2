/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//  Classe mère de TrajetSimple et TrajetComplexe, utilisée pour le polymorphisme
//
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const = 0;
    // Contrat :
    //    Permet d'afficher le trajet, doit être redéfinie par les classes filles

    virtual void EcrireTrajet(ofstream & fichier) const = 0;

    const char* getVilleDep() const;
    // Contrat :
    //    Renvoie la valeur de l'attribut villeDep

    const char *getVilleArr() const;
    // Contrat :
    //    Renvoie la valeur de l'attribut villeArr

    //------------------------------------------------- Surcharge d'opérateurs


    //-------------------------------------------- Constructeurs - destructeur
    // Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet (const char *uneVilleDep, const char *uneVilleArr);
    // Contrat :
    //    Affecte à villeDep la valeur uneVilleDep et à villeArr la valeur uneVilleArr

    virtual ~Trajet ( );
    // Contrat :
    //    Détruit l'objet Trajet , doit être redéfnie par les classes filles

    //------------------------------------------------------------------ PRIVE

public:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    const char * villeDep; // Ville de départ du trajet
    const char * villeArr; // Ville d'arrivé du trajet
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
