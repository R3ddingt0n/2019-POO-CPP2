/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : 27/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetComplexe> (fichier TrajetComplexe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool TrajetComplexe::listeCorrect(Trajet* ppListeTrajets[],const unsigned nbElem,const char* vDep,const char*vArr)
// Algorithme : 1) vérification: vDep est bien la ville de départ du premier trajet de ppListeTrajets
//              2) chaque ville de départ d'un trajet doit correspondre à la ville d'arrivée du trajet précédent
//              3) vérification: vArr est bien la ville de départ du dernier trajet de ppListeTrajets
{
  const char* villeDepart;
  const char* villeArrivee;
  villeDepart = ppListeTrajets[0]->getVilleDep();
  if(strcmp(villeDepart,vDep) != 0)
  {
      return false;
  }
  villeArrivee = ppListeTrajets[0]->getVilleArr();
  if(nbElem<2 && strcmp(villeArrivee,vArr) == 0)
  {
      return true;
  }
  else if(nbElem < 2 && strcmp(villeArrivee, vArr) != 0)
  {
      return false;
  }
  for(unsigned i = 1; i<nbElem; ++i)
    {
      if(strcmp(ppListeTrajets[i]->getVilleDep(),villeArrivee) != 0)
      {
          return false;
      }
      villeArrivee = ppListeTrajets[i]->getVilleArr();
    }
  if(strcmp(villeArrivee,vArr) != 0)
  {
      return false;
  }
  return true;
} //----- Fin de Méthode

void TrajetComplexe::Afficher() const
// Algorithme : affiche les trajet complexe en faisant appel à la méthode Afficher de chacun de ses sous-trajets
//
{
    cout << " --- Trajet Complexe --- " << endl;
    cout << "Départ : " << villeDep << " et destination : " << villeArr << endl;
    cout << "Étapes :" << endl;
    for(unsigned i = 0; i<nbElem; ++i)
    {
        m_ppTrajet[i]->Afficher();
    }
    cout << endl << "--------------------------------" << endl;
} //------Fin de Méthode

void TrajetComplexe::EcrireTrajet(ofstream & fichier) const
{
#ifdef MAP
    cout << "Appel à la méthode EcrireTrajet de <TrajetComplexe>" << endl;
#endif
    fichier << "C" << endl
            << villeDep << endl
            << villeArr << endl
            << nbElem << endl;
    for(unsigned i(0); i < nbElem; ++i)
    {
        m_ppTrajet[i]->EcrireTrajet(fichier);
    }
    return;
}


//-------------------------------------------- Constructeurs - destructeur


TrajetComplexe::TrajetComplexe (Trajet* pplisteTrajets[], const unsigned fnbElem,const char* uneVilleDep,const char*uneVilleArr)
  :Trajet(uneVilleDep,uneVilleArr,2)
// Algorithme : rempli le tableau de pointeurs m_ppTrajet avec les valeurs du tableau pplisteTrajets
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComplexe>" << endl;
#endif
    m_ppTrajet = pplisteTrajets;
    for(unsigned i = 0; i<fnbElem ; ++i)
    {
        m_ppTrajet[i] = pplisteTrajets[i];
    }
    nbElem = fnbElem;
} //----- Fin de TrajetComplexe


TrajetComplexe::~TrajetComplexe ( )
// Algorithme : détruit tout les trajets composant le trajet complexe puis le tableau lui-même
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComplexe>" << endl;
#endif
    for(unsigned i = 0; i<nbElem; ++i)
      {
        delete m_ppTrajet[i];
      }
    delete [] m_ppTrajet;
} //----- Fin de ~TrajetComplexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

