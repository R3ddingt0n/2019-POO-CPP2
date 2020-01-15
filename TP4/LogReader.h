/*************************************************************************
                           LogReader  -  description
                             -------------------
    début                : 15/01/2020
    copyright            : (C) 2020 par Nicolas TROUIN & Ghali ElAlaoui ElAbdellaoui
    e-mail               : nicolas.trouin@insa-lyon.fr & ghali.el-allaoui-el-abdellaoui@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LogReader> (fichier LogReader.h) ----------------
#if ! defined ( LOGREADER_H )
#define LOGREADER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogReader>
//
//
//------------------------------------------------------------------------

class LogReader
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
    LogReader & operator = ( const LogReader & unLogReader );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogReader ( const LogReader & unLogReader );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogReader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LogReader>

#endif // LOGREADER_H

