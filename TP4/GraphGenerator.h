/*************************************************************************
                           GraphGenerator  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GraphGenerator> (fichier GraphGenerator.h) ----------------
#if ! defined ( GRAPHGENERATOR_H )
#define GRAPHGENERATOR_H

//--------------------------------------------------- Interfaces utilisées
#include "Catalog.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Catalog;

//------------------------------------------------------------------------
// Rôle de la classe <GraphGenerator>
//
//
//------------------------------------------------------------------------

class GraphGenerator
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void GenerateGraph (Catalog & catalog, std::string filename);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    GraphGenerator ( const GraphGenerator & unGraphGenerator );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GraphGenerator ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GraphGenerator ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GraphGenerator>

#endif // GRAPHGENERATOR_H

