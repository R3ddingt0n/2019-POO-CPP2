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
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LogReader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void LogReader::ReadFile(string filename, std::vector<Request> & requests)
// Algorithme :
//
{
    ifstream file(filename);
    while(file.good())
    {
        Request req;
        file >> req;
        if(!file.good()) break;
        requests.push_back(req);
    }

}//----- Fin de ReadFile


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

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

