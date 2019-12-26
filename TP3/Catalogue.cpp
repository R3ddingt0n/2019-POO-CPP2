/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr / nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Catalogue::Afficher() const
// Algorithme :
//  Appel de la méthode Afficher de chaque trajets du catalogue
{
#ifdef MAP
    cout << "Appel à la méthode Afficher de <Catalogue>" << endl;
#endif
    cout << "Affichage du Catalogue" << endl;
    for(unsigned i(0); i < tailleAct; ++i)
    {
        (*(mesTrajets)[i]).Afficher();
        cout << endl;
    }
    cout << "Fin de l'affichage du Catalogue" << endl;
} //----- Fin de Afficher

void Catalogue::AfficherResRecherche() const
// Algorithme :
//  Appel de la méthode Afficher de chaque trajets correspondant à la recherche
{
#ifdef MAP
    cout << "Appel à la méthode AfficherResRecherche de <Catalogue>" << endl;
#endif
    cout << "Affichage du résultat de la recherche" << endl;
    for(unsigned i(0); i < tailleResRecherche; ++i)
    {
        (*(resultat)[i]).Afficher();
    }
    cout << "Fin de l'affichage du résultat de la recherche" << endl;
} //----- Fin de Afficher

void Catalogue::Ajouter(Trajet* trajet)
// Algorithme :
//  Ajout d'un trajet au tableau avec réajustement u tableau si nécéssaire
{
#ifdef MAP
    cout << "Appel à la méthode Ajouter de <Catalogue>" << endl;
#endif
    if(tailleAct >= tailleMax)
    {
        this->Ajuster();
    }
    mesTrajets[tailleAct] = trajet;
    ++tailleAct;
} //----- Fin de Ajouter

void Catalogue::Rechercher(char* villeDep_, char* villeArr_)
// Algorithme :
//  Recherche tous les trajets du catalogue ayant pour ville de départ villeDep_ et ville d'arrivée villeArr_
//  et les ajoute au tableau contenant les trajets correspondant au résultat de la recherche
{
#ifdef MAP
    cout << "Appel à Rechercher() de <Catalogue>" << endl;
#endif
    tailleResRecherche = 0;
    for(unsigned i(0); i < tailleAct; ++i)
    {
        // cout << mesTrajets[i]->getVilleDep() << endl << mesTrajets[i]->getVilleArr() << endl;
        if(strcmp(mesTrajets[i]->getVilleDep(), villeDep_) == 0)
        {
            if(strcmp(mesTrajets[i]->getVilleArr(), villeArr_) == 0)
            {
                resultat[tailleResRecherche] = mesTrajets[i];
                ++tailleResRecherche;
            }
        }
    }
}

void Catalogue::SauvegardeComplete(string nomFich) const
{
#ifdef MAP
    cout << "Appel à SauvegardeComplete() de <Catalogue>" << endl;
#endif
    ofstream fich (nomFich.c_str());
    for(unsigned i(0); i<tailleAct;++i){
        mesTrajets[i]->EcrireTrajet(fich);
    }
}

void Catalogue::SauvegardeSelonType(string nomFich) const
{
#ifdef MAP
    cout << "Appel à SauvegardeSelonType() de <Catalogue>" << endl;
#endif
    cout << "Choisir les trajets à conserver :" << endl
         << "-- (1) Les trajets simples" << endl
         << "-- (2) Les trajets complexes" << endl;
    unsigned commande;
    cin >> commande;
    if(commande != 1 && commande != 2)
    {
        cout << "Commande invalide" << endl;
        return;
    }
    ofstream fich (nomFich.c_str());
    for(unsigned i(0); i<tailleAct;++i){
        if(mesTrajets[i]->typeTrajet == commande)
            mesTrajets[i]->EcrireTrajet(fich);
    }
}

void Catalogue::SauvegardeSelonVille(string nomFich) const
{
#ifdef MAP
    cout << "Appel à SauvegardeSelonVille() de <Catalogue>" << endl;
#endif
    ofstream fich (nomFich.c_str());
    cout << "Bienvenue dans le menu de sauvegarde selon ville:" << endl
         << "-- (1) Sauvegarde selon la ville de départ" << endl
         << "-- (2) Sauvegarde selon la ville d'arrivée" << endl
         << "-- (3) Sauvegarde selon la ville de départ et d'arrivée" << endl;
    string villeDep;
    string villeArr;
    unsigned choix;
    cin >> choix;
    unsigned i;
    switch (choix)
    {
    case 1:
        for(i=0; i<tailleAct;++i){
            if(!strcmp(mesTrajets[i]->getVilleDep(), villeDep.c_str()))
                mesTrajets[i]->EcrireTrajet(fich);
        }
        break;
    case 2:
        for(i=0; i<tailleAct;++i){
            if(!strcmp(mesTrajets[i]->getVilleArr(), villeArr.c_str()))
                mesTrajets[i]->EcrireTrajet(fich);
        }
        break;
    case 3:
        for(i=0; i<tailleAct;++i){
            if(!strcmp(mesTrajets[i]->getVilleDep(), villeDep.c_str()) && !strcmp(mesTrajets[i]->getVilleArr(), villeArr.c_str()))
                mesTrajets[i]->EcrireTrajet(fich);
        }
        break;
    default:
        cout << "Commande non reconnue" << endl;
    }
}

void Catalogue::SauvegarderSelonIntervalle(string nomFich) const
{
#ifdef MAP
    cout << "Appel à SauvegardeSelonIntervalle() de <Catalogue>" << endl;
#endif
    unsigned min, max;
    cout << "Borne min de l'intervalle :" << endl;
    cin >> min;
    cout << "Borne min de l'intervalle :" << endl;
    cin >> max;
    if(min > max || min > tailleAct || max > tailleAct)
    {
        cout << "Erreur dans le choix de l'intervalle" << endl;
        return;
    }
    ofstream fich (nomFich.c_str());
    for(unsigned i(min); i<max; ++i){
        mesTrajets[i]->EcrireTrajet(fich);
    }
}

void Catalogue::ChargerFichierComplet(string nomFich)
{
#ifdef MAP
    cout << "Appel à ChargerFichierComplet() de <Catalogue>" << endl;
#endif
    int nbTrajets;
    ifstream fichier(nomFich.c_str());
    string buffer;
    getline(fichier, buffer);
    nbTrajets = atoi(buffer.c_str());
    vector<Trajet*> listeTrajets;
    while(fichier.good() && nbTrajets > 0)
    {
        LireTrajet(fichier, listeTrajets);
        --nbTrajets;
    }
    for(unsigned i(0); i < listeTrajets.size(); ++i)
    {
        Ajouter(listeTrajets[i]);
    }
}

void Catalogue::LireTrajet(ifstream & fichier, vector<Trajet*> & listeTrajets)
{
#ifdef MAP
    cout << "Appel à LireTrajet() de <Catalogue>" << endl;
#endif
    string buffer;
    getline(fichier, buffer);
    if(buffer.at(0) == 'S')
    {
        LireTrajetSimple(fichier, listeTrajets);
    }
    else if(buffer.at(0) == 'C')
    {
        LireTrajetComplexe(fichier, listeTrajets);
    }
}

void Catalogue::LireTrajetSimple(ifstream & fichier, vector<Trajet*> &listeTrajets)
{
#ifdef MAP
    cout << "Appel à LireTrajetSimple() de <Catalogue>" << endl;
#endif
    string villeDep;
    string villeArr;
    getline(fichier, villeDep);
    getline(fichier, villeArr);
    int moyenTransport;
    string buffer;
    getline(fichier, buffer);
    moyenTransport = atoi(buffer.c_str());
    char *villeDep_ = new char[40];
    char *villeArr_ = new char[40];
    strcpy(villeDep_, villeDep.c_str());
    strcpy(villeArr_, villeArr.c_str());
    TrajetSimple* trajet = new TrajetSimple(villeDep_,villeArr_,static_cast<MoyenTransport>(moyenTransport));
    listeTrajets.push_back(trajet);
}

void Catalogue::LireTrajetComplexe(ifstream & fichier, vector<Trajet*> & listeTrajets)
{
#ifdef MAP
    cout << "Appel à LireTrajetComplexe() de <Catalogue>" << endl;
#endif
    string villeDepGlob;
    string villeArrGlob;
    getline(fichier, villeDepGlob);
    getline(fichier, villeArrGlob);
    unsigned nbSousTrajets;
    string buffer;
    getline(fichier, buffer);
    nbSousTrajets = atoi(buffer.c_str());
    Trajet** liste = new Trajet*[nbSousTrajets];
    vector<Trajet*> listeSousTrajets;
    for(unsigned i(0); i < nbSousTrajets; ++i)
    {
        LireTrajetSimple(fichier,listeSousTrajets);
        liste[i] = listeSousTrajets[i];
    }
    char *villeDepGlob_ = new char[40];
    char *villeArrGlob_ = new char[40];
    strcpy(villeDepGlob_, villeDepGlob.c_str());
    strcpy(villeArrGlob_, villeArrGlob.c_str());
    if(TrajetComplexe::listeCorrect(liste, nbSousTrajets, villeDepGlob_, villeArrGlob_))
    {
        TrajetComplexe* trajetComplexe = new TrajetComplexe(liste, nbSousTrajets, villeDepGlob_, villeArrGlob_);
        listeTrajets.push_back(trajetComplexe);
    }
    else
    {
        cerr << "Trajet complexe erroné";
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur



Catalogue::Catalogue (unsigned tailleMax_)
    : tailleAct(0), tailleMax(tailleMax_)
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    mesTrajets = new Trajet*[tailleMax];
    resultat = new Trajet*[TAILLE_MAX_RECHERCHE];
    tailleResRecherche = 0;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//  Détruit les trajets du catalogue puis les tableaux mesTrajets et resultat
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    for(unsigned i(0); i < tailleAct; ++i)
    {
        delete *(mesTrajets + i);
    }
    delete [] mesTrajets;
    delete [] resultat;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Méthodes privées

void Catalogue::Ajuster()
// Algorithme :
//  Création d'un tableau 2 fois plus grand puis copie des différents pointeurs déjà présent dans le tableau de départ
//  Destruction du tableau de départ, mesTrajets correspond ensuite au nouveau tableau
{
#ifdef MAP
    cout << "Appel à la méthode Ajuster de <Catalogue>" << endl;
#endif
    tailleMax *= 2;
    Trajet** newTrajets = new Trajet*[tailleMax];
    for(unsigned i(0); i < tailleAct; ++i)
    {
        *newTrajets[i] = *mesTrajets[i];
    }
    delete [] *mesTrajets;
    *mesTrajets = *newTrajets;


} //----- Fin de Ajuster
