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

#include <fstream>

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum MoyenTransport { AUTO, TRAIN, AVION, BATEAU };

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const;
    // Contrat :
    //    Permet d'afficher le trajet simple, doit être redéfinie par les classes filles

    virtual void EcrireTrajet(ofstream & fichier) const;

    //------------------------------------------------- Surcharge d'opérateurs


    //-------------------------------------------- Constructeurs - destructeur
    // TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetSimple (const char* uneVilleDep, const char* uneVilleArr, const MoyenTransport unMoyenTransport);
    // Mode d'emploi :
    //
    // Contrat :
    //    Affecte à villeDep la valeur uneVilleDep et à villeArr la valeur uneVilleArr

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //    Détruit l'objet TrajetSimple, doit être redéfnie par les classes filles

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    const MoyenTransport moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

