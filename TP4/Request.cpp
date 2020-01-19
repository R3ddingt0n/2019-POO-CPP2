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
#include <iostream>
using namespace std;

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
/*
Request & Request::operator = ( const Request & unRequest )
// Algorithme :
//
{
} //----- Fin de operator =
*/

istream & operator >>(istream & in, Request & request)
{
    string buffer;

    std::getline(in, request.ipAdress, ' ');
    std::getline(in, request.userLogName, ' ');
    std::getline(in, request.authenticatedUser, ' ');
    std::getline(in, buffer, '[');
    std::getline(in, request.date, ':');
    std::getline(in, request.time, ' ');
    std::getline(in, request.timeZone, ']');
    std::getline(in, buffer, '"');
    std::getline(in, request.httpMethod, ' ');
    std::getline(in, request.target, ' ');
    std::getline(in, request.protocol, '"');
    std::getline(in, buffer, ' ');
    in >> request.returnCode >> request.data;
    std::getline(in, buffer, '"');
    std::getline(in, request.referer, '"');
    std::getline(in, buffer, '"');
    std::getline(in, request.userAgent, '"');

    return in;
}

ostream & operator << (ostream & out, const Request & request)
{
    out << "FOR TESTING PURPOSE ONLY" << endl;
    out << request.ipAdress << endl << request.userLogName << endl << request.authenticatedUser << endl << request.date << endl << request.time << endl << request.timeZone << endl << request.httpMethod << endl << request.target << endl << request.protocol << endl << request.returnCode << endl << request.data << endl << request.referer << endl << request.userAgent;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur

/*Request::Request ( const Request & request )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Request>" << endl;
#endif
}*/ //----- Fin de Request (constructeur de copie)


Request::Request ()
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

