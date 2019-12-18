/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.naboux@insa-lyon.fr / nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes
const unsigned TAILLE_MAX = 5;
const unsigned TAILLE_MAX_RECHERCHE = 50;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//  Contient des trajets dans un tableau de pointeurs sur trajets, les résultats d'une recherche sont stockés dans un tableau de pointeurs sur trajets
//
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void Afficher() const;
    // Contrat :
    // Affiche le catalogue

    void AfficherResRecherche() const;
    // Contrat :
    // Affiche le résultat de la recherche de parcours

    void Ajouter(Trajet* trajet);
    // Contrat :
    // Ajoute trajet au catalogue

    void Rechercher(char* villeDep_,char* villeArr_);
    // Contrat :
    // Recherche les différents trajets permettant d'aller de villeDep_ à villeArr_

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Catalogue (unsigned tailleMax_ = TAILLE_MAX);
    // Contrat :
    // Affecte à tailleMax la valeur tailleMax_

    virtual ~Catalogue ( );
    // Contrat :
    // Détruit le catalogue

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

private:
    //----------------------------------------------------- Méthodes privées
    void Ajuster();
    // Mode d'emploi :
    // L'utilisateur n'a pas à s'en servir, la méthode est utilisée lors de l'ajout d'un trajet
    // Contrat :
    // Double la taille max du tableau (réallocation).

    //----------------------------------------------------- Attributs privés
    unsigned tailleAct; // taille actuelle du tableau de trajets
    unsigned tailleMax; // taille maximale du tableau de trajets
    unsigned tailleResRecherche; // taille actuelle du tableau de trajets correspondant au résultat de la recherche
    Trajet** mesTrajets; // tableau de pointeurs pointant sur les trajets composant le catalogue
    Trajet** resultat; // tableau de pointeurs pointant sur les trajets correspondant au résultat de la recherche
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

