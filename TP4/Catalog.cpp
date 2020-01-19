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
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalog::FillHitsPerTarget(std::vector<Request> & requests)
// Algorithme :
//
{
    for(unsigned i (0); i < requests.size(); ++i)
    {
        if(hitsPerTarget.count(requests[i].target) == 0)
        {
            hitsPerTarget.insert(make_pair(requests[i].target, 1));
        }
        else
        {
            ++hitsPerTarget[requests[i].target];
        }
    }
    unordered_map<string, unsigned>::const_iterator it = hitsPerTarget.begin();
    while(it != hitsPerTarget.end())
    {
        cout << it->first << " -- " << it->second << endl;
        ++it;
    }
}//----- Fin de FillHitsPerTarget


void Catalog::ConvertMapToMultimap()
// Algorithme :
//
{
    unordered_map<string, unsigned>::const_iterator it = hitsPerTarget.begin();
    targetsPerHits.clear();
    while(it != hitsPerTarget.end())
    {
        targetsPerHits.insert(make_pair(it->second, it->first));
        ++it;
    }
    multimap<unsigned, string>::const_iterator it2 = targetsPerHits.begin();
    while(it2 != targetsPerHits.end())
    {
        cout << it2->first << " -- " << it2->second << endl;
        ++it2;
    }
}//----- Fin de ConvertMapToMultimap


//------------------------------------------------- Surcharge d'opérateurs
/*
Catalog & Catalog::operator = ( const Catalog & unCatalog )
// Algorithme :
//
{
} //----- Fin de operator =
*/

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

