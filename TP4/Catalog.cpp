/*************************************************************************
                           Catalog  -  description
                             -------------------
    début                : 15/01/2020
    copyright            : (C) 2020 par Nicolas TROUIN & Ghali ElAlaoui ElAbdellaoui
    e-mail               : nicolas.trouin@insa-lyon.fr & ghali.el-allaoui-el-abdellaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalog> (fichier Catalog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Catalog & Catalog::operator = ( const Catalog & unCatalog )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalog::Catalog ( const Catalog & unCatalog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalog>" << endl;
#endif
} //----- Fin de Catalog (constructeur de copie)


Catalog::Catalog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalog>" << endl;
#endif
} //----- Fin de Catalog


Catalog::~Catalog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalog>" << endl;
#endif
} //----- Fin de ~Catalog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

