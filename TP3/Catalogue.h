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
#include "TrajetSimple.h"
#include "TrajetComplexe.h"
#include <string>
#include <fstream>
#include <vector>
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

    void SauvegardeComplete(string nomFich) const;

    void SauvegardeSelonType(string nomFich) const;

    void SauvegardeSelonVille(string nomFich) const;

    void SauvegarderSelonIntervalle(string nomFich) const;

    void ChargerFichierComplet(string nomFich);

    void ChargerFichierSelonVille(string nomFich);

    void ChargerFichierSelonType(string nomFich);

    void ChargerFichierSelonIntervalle(string nomFich);

    void LireTrajet(ifstream & fichier, vector<Trajet*> & listeTrajets);

    void LireTrajetSimple(ifstream & fichier, vector<Trajet*> & listeTrajets);

    void LireTrajetComplexe(ifstream & fichier, vector<Trajet*> & listeTrajets);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Catalogue ();
    // Contrat :
    // Construit le catalogue

    virtual ~Catalogue ( );
    // Contrat :
    // Détruit le catalogue

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    void LireFichier(string nomFich, vector<Trajet *> &listeTrajets);

    //----------------------------------------------------- Attributs protégés
    
private:
    //----------------------------------------------------- Méthodes privées

    //----------------------------------------------------- Attributs privés
    vector<Trajet*> mesTrajets; // tableau de pointeurs pointant sur les trajets composant le catalogue
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

