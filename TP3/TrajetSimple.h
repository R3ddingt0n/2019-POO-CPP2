/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum MoyenTransport { AUTO, TRAIN, AVION, BATEAU };

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Un trajet simple permet de relier deux villes par un moyen de transport unique
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const;
    // Contrat :
    //    Permet d'afficher le trajet simple

    virtual void EcrireTrajet(ofstream & fichier) const;

    //------------------------------------------------- Surcharge d'opérateurs


    //-------------------------------------------- Constructeurs - destructeur

    TrajetSimple (const char* uneVilleDep, const char* uneVilleArr, const MoyenTransport unMoyenTransport);
    // Contrat :
    //    Affecte à villeDep la valeur uneVilleDep, à villeArr la valeur uneVilleArr et à moyenTransport la valeur unMoyenTransport

    virtual ~TrajetSimple ( );
    // Contrat :
    //    Détruit l'objet TrajetSimple

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    const MoyenTransport moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

