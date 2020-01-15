/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 15/01/2020
    copyright            : (C) 2020 par Nicolas TROUIN & Ghali ElAlaoui ElAbdellaoui
    e-mail               : nicolas.trouin@insa-lyon.fr & ghali.el-allaoui-el-abdellaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Request> (fichier Request.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Request.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Request::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Request & Request::operator = ( const Request & unRequest )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Request::Request ( const Request & unRequest )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Request>" << endl;
#endif
} //----- Fin de Request (constructeur de copie)


Request::Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Request>" << endl;
#endif
} //----- Fin de Request


Request::~Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Request>" << endl;
#endif
} //----- Fin de ~Request


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

