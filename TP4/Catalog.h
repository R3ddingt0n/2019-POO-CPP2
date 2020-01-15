/*************************************************************************
                           Catalog  -  description
                             -------------------
    début                : 15/01/2020
    copyright            : (C) 2020 par Nicolas TROUIN & Ghali ElAlaoui ElAbdellaoui
    e-mail               : nicolas.trouin@insa-lyon.fr & ghali.el-allaoui-el-abdellaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalog> (fichier Catalog.h) ----------------
#if ! defined ( CATALOG_H )
#define CATALOG_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalog>
//
//
//------------------------------------------------------------------------

class Catalog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Catalog & operator = ( const Catalog & unCatalog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Catalog ( const Catalog & unCatalog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalog>

#endif // CATALOG_H

