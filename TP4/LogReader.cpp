/*************************************************************************
                           LogReader  -  description
                             -------------------
    début                : 15/01/2020
    copyright            : (C) 2020 par Nicolas TROUIN & Ghali ElAlaoui ElAbdellaoui
    e-mail               : nicolas.trouin@insa-lyon.fr & ghali.el-allaoui-el-abdellaoui@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LogReader> (fichier LogReader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogReader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogReader::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
LogReader & LogReader::operator = ( const LogReader & unLogReader )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogReader::LogReader ( const LogReader & unLogReader )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogReader>" << endl;
#endif
} //----- Fin de LogReader (constructeur de copie)


LogReader::LogReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogReader>" << endl;
#endif
} //----- Fin de LogReader


LogReader::~LogReader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogReader>" << endl;
#endif
} //----- Fin de ~LogReader


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

