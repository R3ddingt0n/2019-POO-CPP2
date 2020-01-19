/*************************************************************************
                           RankingDisplayer  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <RankingDisplayer> (fichier RankingDisplayer.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "RankingDisplayer.h"
#include "Catalog.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void RankingDisplayer::DisplayTopHits(Catalog & catalog, unsigned top)
// Algorithme :
//
{
    multimap<unsigned, string>::const_reverse_iterator it = catalog.targetsPerHits.crbegin();
    while(it != catalog.targetsPerHits.crend() and --top)
    {
        cout << it->second << " (" << it->first << " hits)" << endl;
        ++it;
    }
    //Ici on a affiché (au max) les 9 premiers
    unsigned nb10e = 0;
    if(it != catalog.targetsPerHits.crend())
    {
         nb10e = it->first;
    }
    while(it != catalog.targetsPerHits.crend() and it->first == nb10e)
    {
        cout << it->second << " (" << it->first << " hits)" << endl;
        ++it;
    }
}//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

RankingDisplayer::RankingDisplayer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <RankingDisplayer>" << endl;
#endif
} //----- Fin de RankingDisplayer


RankingDisplayer::~RankingDisplayer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <RankingDisplayer>" << endl;
#endif
} //----- Fin de ~RankingDisplayer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

