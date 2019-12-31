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
    for(unsigned i(0); i < mesTrajets.size(); ++i)
    {
        mesTrajets[i]->Afficher();
        cout << endl;
    }
    cout << "Fin de l'affichage du Catalogue" << endl;
} //----- Fin de Afficher

void Catalogue::Ajouter(Trajet* trajet)
// Algorithme :
//  Ajout d'un trajet au tableau avec réajustement u tableau si nécéssaire
{
#ifdef MAP
    cout << "Appel à la méthode Ajouter de <Catalogue>" << endl;
#endif
    mesTrajets.push_back(trajet);
} //----- Fin de Ajouter

void Catalogue::Rechercher(char* villeDep_, char* villeArr_)
// Algorithme :
//  Recherche tous les trajets du catalogue ayant pour ville de départ villeDep_ et ville d'arrivée villeArr_
//  et les affiche
{
#ifdef MAP
    cout << "Appel à Rechercher() de <Catalogue>" << endl;
#endif
    for(unsigned i(0); i < mesTrajets.size(); ++i)
    {
//        cout << mesTrajets[i]->getVilleDep() << " " << mesTrajets[i]->getVilleArr() << endl;
        if(!strncmp(mesTrajets[i]->getVilleDep(), villeDep_, strlen(mesTrajets[i]->getVilleDep())-1))
        {
            if(!strncmp(mesTrajets[i]->getVilleArr(), villeArr_, strlen(mesTrajets[i]->getVilleArr())-1))
            {
                mesTrajets[i]->Afficher();
                cout << endl;
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
    for(unsigned i(0); i<mesTrajets.size();++i){
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
    for(unsigned i(0); i<mesTrajets.size();++i){
        if(mesTrajets[i]->typeTrajet == commande)
        {
            mesTrajets[i]->EcrireTrajet(fich);
        }
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
        cout << "Entrez la ville de départ:" << endl;
        cin >> villeDep;
        for(i=0; i<mesTrajets.size();++i){
            if(!strncmp(mesTrajets[i]->getVilleDep(), villeDep.c_str(), strlen(mesTrajets[i]->getVilleDep())-1))
                mesTrajets[i]->EcrireTrajet(fich);
        }
        break;
    case 2:
        cout << "Entrez la ville d'arrivée:" << endl;
        cin >> villeArr;
        for(i=0; i<mesTrajets.size();++i){
            string villeA = mesTrajets[i]->getVilleArr();
            if(!strncmp(villeA.c_str(), villeArr.c_str(), villeA.length()-1))
                mesTrajets[i]->EcrireTrajet(fich);
        }
        break;
    case 3:
        cout << "Entrez la ville de départ:" << endl;
        cin >> villeDep;
        cout << "Entrez la ville d'arrivée:" << endl;
        cin >> villeArr;
        for(i=0; i<mesTrajets.size();++i){
            if(!strncmp(mesTrajets[i]->getVilleDep(), villeDep.c_str(), strlen(mesTrajets[i]->getVilleDep())-1) && !strncmp(mesTrajets[i]->getVilleArr(), villeArr.c_str(), strlen(mesTrajets[i]->getVilleArr())-1))
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
    cout << "Borne min de l'intervalle (inclus) :" << endl;
    cin >> min;
    cout << "Borne min de l'intervalle (inclus) :" << endl;
    cin >> max;
    if(min > max || min > mesTrajets.size() || max > mesTrajets.size())
    {
        cout << "Erreur dans le choix de l'intervalle" << endl;
        return;
    }
    ofstream fich (nomFich.c_str());
    for(unsigned i(min); i <= max; ++i)
    {
        mesTrajets[i]->EcrireTrajet(fich);
    }
}

void Catalogue::LireFichier(string nomFich, vector<Trajet *> & listeTrajets)
{
    ifstream fichier(nomFich.c_str());
    string buffer;
    fichier.seekg(0, fichier.end);
    long long length = fichier.tellg();
    fichier.seekg(0, fichier.beg);
    long long pos(0);
    while(fichier.good() && pos != length)
    {
        LireTrajet(fichier, listeTrajets);
        pos = fichier.tellg();
    }
}

void Catalogue::ChargerFichierComplet(string nomFich)
{
#ifdef MAP
    cout << "Appel à ChargerFichierComplet() de <Catalogue>" << endl;
#endif
    vector<Trajet*> listeTrajets;
    LireFichier(nomFich, listeTrajets);
    for(unsigned i(0); i < listeTrajets.size(); ++i)
    {
        Ajouter(listeTrajets[i]);
    }
}

void Catalogue::ChargerFichierSelonVille(string nomFich)
{
#ifdef MAP
    cout << "Appel à ChargerFichierComplet() de <Catalogue>" << endl;
#endif
    vector<Trajet*> listeTrajets;
    LireFichier(nomFich, listeTrajets);

    cout << "Bienvenue dans le menu de chargement selon la/les ville(s) :" << endl
         << "-- (1) Chargement selon la ville de départ" << endl
         << "-- (2) Chargement selon la ville d'arrivée" << endl
         << "-- (3) Chargement selon la ville de départ et d'arrivée" << endl;
    string villeDep;
    string villeArr;
    unsigned choix;
    cin >> choix;
    unsigned i(0);
    switch (choix)
    {
    case 1:
        cout << "Entrez la ville de départ:" << endl;
        cin >> villeDep;
        for(; i < listeTrajets.size(); ++i)
        {
            if(!strncmp(villeDep.c_str(), listeTrajets[i]->getVilleDep(), strlen(listeTrajets[i]->getVilleDep())-1))
            {
                Ajouter(listeTrajets[i]);
            }
            else
            {
                delete listeTrajets[i];
            }
        }
        break;
    case 2:
        cout << "Entrez la ville d'arrivée:" << endl;
        cin >> villeArr;
        for(; i < listeTrajets.size(); ++i)
        {
            if(!strncmp(villeArr.c_str(), listeTrajets[i]->getVilleArr(), strlen(listeTrajets[i]->getVilleArr())-1))
            {
                Ajouter(listeTrajets[i]);
            }
            else
            {
                delete listeTrajets[i];
            }
        }
        break;
    case 3:
        cout << "Entrez la ville de départ:" << endl;
        cin >> villeDep;
        cout << "Entrez la ville d'arrivée:" << endl;
        cin >> villeArr;
        for(; i < listeTrajets.size(); ++i)
        {
            if(!strncmp(villeDep.c_str(), listeTrajets[i]->getVilleDep(), strlen(listeTrajets[i]->getVilleDep())-1) && !strncmp(villeArr.c_str(), listeTrajets[i]->getVilleArr(), strlen(listeTrajets[i]->getVilleArr())-1))
            {
                Ajouter(listeTrajets[i]);
            }
            else
            {
                delete listeTrajets[i];
            }
        }
        break;
    default:
        cout << "Commande non reconnue" << endl;
    }
}

void Catalogue::ChargerFichierSelonType(string nomFich)
{
#ifdef MAP
    cout << "Appel à ChargerFichierComplet() de <Catalogue>" << endl;
#endif
    vector<Trajet*> listeTrajets;
    LireFichier(nomFich, listeTrajets);
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
    for(unsigned i(0); i < listeTrajets.size(); ++i)
    {
        if(listeTrajets[i]->typeTrajet == commande)
        {
            Ajouter(listeTrajets[i]);
        }
        else
        {
            delete listeTrajets[i];
        }
    }
}

void Catalogue::ChargerFichierSelonIntervalle(string nomFich)
{
#ifdef MAP
    cout << "Appel à ChargerFichierComplet() de <Catalogue>" << endl;
#endif
    vector<Trajet*> listeTrajets;
    LireFichier(nomFich, listeTrajets);
    unsigned min, max;
    cout << "Borne min de l'intervalle (inclus) :" << endl;
    cin >> min;
    cout << "Borne max de l'intervalle (inclus) :" << endl;
    cin >> max;
    if(min > max || min > listeTrajets.size()-1 || max > listeTrajets.size()-1)
    {
        cout << "Erreur dans le choix de l'intervalle" << endl;
        return;
    }
    for(unsigned i(0); i < listeTrajets.size(); ++i)
    {
        if(i >= min && i <= max)
        {
            Ajouter(listeTrajets[i]);
        }
        else
        {
            delete listeTrajets[i];
        }
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
    string bufferS;
    getline(fichier, buffer);
    nbSousTrajets = atoi(buffer.c_str());
    Trajet** liste = new Trajet*[nbSousTrajets];
    vector<Trajet*> listeSousTrajets;
    for(unsigned i(0); i < nbSousTrajets; ++i)
    {
        getline(fichier, bufferS);
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



Catalogue::Catalogue ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//  Détruit les trajets du catalogue
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    for(unsigned i(0); i < mesTrajets.size(); ++i)
    {
        delete mesTrajets[i];
    }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Méthodes privées
