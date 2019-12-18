/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher () const
{
    cout << " --- Trajet Simple --- " << endl;
    char* moyTrans = new char [20];
    if(moyenTransport == MoyenTransport::AUTO)
    {
      strcpy(moyTrans,"AUTO");
    }else if(moyenTransport == MoyenTransport::TRAIN)
    {
      strcpy(moyTrans,"TRAIN");
    }else if(moyenTransport == MoyenTransport::AVION)
    {
      strcpy(moyTrans,"AVION");
    }else if(moyenTransport == MoyenTransport::BATEAU)
    {
      strcpy(moyTrans,"BATEAU");
    }
    cout << "Ville de départ : " << villeDep << endl;
    cout << "Ville d'arrivée : " << villeArr << endl;
    cout << "Moyen de Transport : " << moyTrans << endl;
    cout << "--------------------------------" << endl;
    delete [] moyTrans;
} //----- Fin de Afficher

void TrajetSimple::EcrireTrajet(ofstream & fichier) const
{
    return;
}

//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple (const char* uneVilleDep, const char* uneVilleArr, const MoyenTransport unMoyenTransport)
  :Trajet(uneVilleDep,uneVilleArr),moyenTransport(unMoyenTransport)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

