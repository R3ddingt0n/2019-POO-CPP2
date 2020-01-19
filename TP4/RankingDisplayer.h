/*************************************************************************
                           RankingDisplayer  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <RankingDisplayer> (fichier RankingDisplayer.h) ----------------
#if ! defined ( RANKINGDISPLAYER_H )
#define RANKINGDISPLAYER_H

//--------------------------------------------------- Interfaces utilisées
#include "Catalog.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Catalog;

//------------------------------------------------------------------------
// Rôle de la classe <RankingDisplayer>
//
//
//------------------------------------------------------------------------

class RankingDisplayer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void DisplayTopHits (Catalog & catalog, unsigned top);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    RankingDisplayer ( const RankingDisplayer & unRankingDisplayer );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    RankingDisplayer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~RankingDisplayer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <RankingDisplayer>

#endif // RANKINGDISPLAYER_H

