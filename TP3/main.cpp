#include <iostream>
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

using namespace std;

void AjouterTrajet(Catalogue & catalogue);
void RechercherTrajet(Catalogue & catalogue);
void AfficherTrajet(Catalogue & catalogue);

// Menu de l'application
int main()
{
    int commande = 0;
    Catalogue catalogue = Catalogue();
    cout << "Bienvenue dans ce simulateur de gestion de transports." << endl << endl;
    while(commande != -1)
    {
        cout << "Menu :" << endl
             << "-- (1) Ajouter un trajet au catalogue :" << endl
             << "-- (2) Afficher le catalogue :" << endl
             << "-- (3) Rechercher un parcours dans le catalogue :" << endl
             << "-- (4) Sortir" << endl;
        cin >> commande;
        switch(commande)
        {
        case 1:
            AjouterTrajet(catalogue);
            break;
        case 2:
            AfficherTrajet(catalogue);
            break;
        case 3:
            RechercherTrajet(catalogue);
            break;
        case 4:
            cout << "Fermeture ..." << endl;
            commande = -1;
            break;
        default:
            cout << "Commande inconnue." << endl;
            break;
        }
    }
    return 0;
}

// Algorithme :
// Demande à l'utilisateur une ville de départ et une ville d'arrivée pour la recherche puis lance la recherche
void RechercherTrajet(Catalogue & catalogue)
{
    char villeDep[100],villeArr[100];
    cout << "Ville de départ : (Sans espace)";
    cin >> villeDep;
    cout << "Ville d'arrivée : (Sans espace)";
    cin >> villeArr;
    catalogue.Rechercher(villeDep,villeArr);
    cout << endl << "Résultat de la recherche :" <<endl;
    catalogue.AfficherResRecherche();
    cout << endl;
}


// Algorithme :
// Ajoute un trajet simple dans le catalogue après avoir demandé un moyen de transport
void AjouterTrajetSimple(Catalogue & catalogue,char * &villeDep,char * &villeArr)
{
    unsigned idMoyenTransport;
    cout << "Veuillez choisir le moyen de transport" << endl;
    cout << "(1) AUTO" << endl
         << "(2) TRAIN" << endl
         << "(3) AVION" << endl
         << "(4) BATEAU" << endl;
    cin >> idMoyenTransport;
    TrajetSimple* trajetSimple;
    switch (idMoyenTransport) {
    case 1:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AUTO);
        break;
    case 2:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::TRAIN);
        break;
    case 3:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AVION);
        break;
    case 4:
        trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::BATEAU);
        break;
    default:
        cout << "Erreur" << endl;
        return;
    }
    catalogue.Ajouter(trajetSimple);
}

// Algorithme :
// Ajoute un trajet complexe dans le catalogue après avoir demandé la saisie de tous ses sous-trajets
void AjouterTrajetComplexe(Catalogue & catalogue,char * &villeDep,char * &villeArr)
{
    unsigned nbSousTrajets(0);
    while(nbSousTrajets <= 1 || nbSousTrajets >= 10)
    {
        cout << "De combien de sous-trajets se compose votre trajet complexe ? (entre 2 et 9)" << endl;
        cin >> nbSousTrajets;
    }
    char *villeDepGlobal = villeDep;
    char *villeArrGlobal = villeArr;
    Trajet** liste = new Trajet*[9];
    unsigned idMoyenTransport;
    for(unsigned i(0); i < nbSousTrajets; ++i)
    {
        cout << endl << "Composition du trajet simple composant le trajet complexe :" << endl;
        char *villeDep = new char[40];
        char *villeArr = new char[40];
        cout << "Veuillez saisir la ville de départ (Sans espace)" << endl;
        cin >> villeDep;
        cout << "Veuillez saisir la ville d'arrivée (Sans espace)" << endl;
        cin >> villeArr;
        cout << "Veuillez choisir le moyen de transport" << endl;
        cout << "(1) AUTO" << endl
             << "(2) TRAIN" << endl
             << "(3) AVION" << endl
             << "(4) BATEAU" << endl;
        cin >> idMoyenTransport;
        TrajetSimple* trajetSimple;
        switch (idMoyenTransport) {
        case 1:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AUTO);
            break;
        case 2:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::TRAIN);
            break;
        case 3:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::AVION);
            break;
        case 4:
            trajetSimple = new TrajetSimple(villeDep, villeArr, MoyenTransport::BATEAU);
            break;
        default:
            cout << "Erreur" << endl;
            return;
        }
        liste[i] = trajetSimple;
    }
    if(TrajetComplexe::listeCorrect(liste, nbSousTrajets, villeDepGlobal, villeArrGlobal))
    {
        TrajetComplexe* trajetComplexe = new TrajetComplexe(liste, nbSousTrajets, villeDepGlobal, villeArrGlobal);
        catalogue.Ajouter(trajetComplexe);
    } else
    {
        for(unsigned i = 0; i<nbSousTrajets; ++i)
          {
            delete liste[i];
          }
        delete [] liste;
        delete [] villeDep;
        delete [] villeArr;
        cout << "Le trajet composé est incorrect, il n'a pas été ajouté au catalogue" << endl;
    }
}

// Algorithme :
// Demande à l'utilisateur s'il veut ajouter un trajet simple ou un trajet complexe
// Demande la ville de départ et la ville d'arrivée du trajet puis appel la fonction correspondante (simple ou complexe)
void AjouterTrajet(Catalogue & catalogue)
{
    cout << "(1) Trajet Simple" << endl
         << "(2) Trajet Complexe" << endl;
    int commande(0);
    cin >> commande;

    char *villeDep = new char[40];
    char *villeArr = new char[40];
    cout << "Veuillez saisir la ville de départ (Sans espace)"<< endl;
    cin >> villeDep;
    cout << "Veuillez saisir la ville d'arrivée (Sans espace)" << endl;
    cin >> villeArr;

    switch (commande) {
    case 1:
        AjouterTrajetSimple(catalogue,villeDep,villeArr);
        break;
    case 2:
        AjouterTrajetComplexe(catalogue,villeDep,villeArr);
        break;
    default:
        cout << "Erreur" << endl;
        return;
    }
}

// Algorithme :
// Affiche le catalogue
void AfficherTrajet(Catalogue & catalogue)
{
    catalogue.Afficher();
}
