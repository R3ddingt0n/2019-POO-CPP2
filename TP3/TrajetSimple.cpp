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
// Algorithme :
//
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


//-------------------------------------------- Constructeurs - destructeur
//Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Xxx>" << endl;
//#endif
//} //----- Fin de Xxx (constructeur de copie)


TrajetSimple::TrajetSimple (const char* uneVilleDep, const char* uneVilleArr, const MoyenTransport unMoyenTransport)
  :Trajet(uneVilleDep,uneVilleArr,1),moyenTransport(unMoyenTransport)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

void TrajetSimple::EcrireTrajet(ofstream & fichier) const{
  fichier << "S\n" << villeDep << '\n' << villeArr << '\n' << moyenTransport << '\n';
}


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

