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
}//----- Fin de ConvertMapToMultimap


void Catalog::FillGraphEdges(std::vector<Request> & requests)
{
    for(unsigned i (0); i < requests.size(); ++i)
    {
        pair<string,string> req = make_pair(requests[i].referer, requests[i].target);
        if(graphEdges.count(req) == 0)
        {
            graphEdges.insert(make_pair(req, 1));
        }
        else
        {
            ++graphEdges[req];
        }
    }
    map<pair<string,string>, unsigned>::const_iterator it = graphEdges.cbegin();
    while(it != graphEdges.cend())
    {
        cout << it->first.first << " -> " << it->first.second << " (" << it->second << " hits)" << endl;
        ++it;
    }
}//----- Fin de FillGraphEdges

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

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

