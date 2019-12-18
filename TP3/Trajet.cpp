/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


const char *Trajet::getVilleDep() const
{
    return villeDep;
}//----- Fin de getVilleDep

const char *Trajet::getVilleArr() const
{
    return villeArr;
}//----- Fin de getVilleDep


//-------------------------------------------- Constructeurs - destructeur


Trajet::Trajet (const char* uneVilleDep, const char* uneVilleArr )
    :villeDep(uneVilleDep),villeArr(uneVilleArr)
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme : détruit la ville de départ et la ville d'arrivée
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete [] villeDep;
    delete [] villeArr;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
