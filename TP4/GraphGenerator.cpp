/*************************************************************************
                           GraphGenerator  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GraphGenerator> (fichier GraphGenerator.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GraphGenerator.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void GraphGenerator::GenerateGraph(Catalog & catalog, string filename)
// Algorithme :
//
{
    map<string, unsigned> graphNodes;
    GetNodes(catalog, graphNodes);

    std::ofstream file(filename);
    file << "digraph {" << endl;

    //Nodes declaration
    map<string, unsigned>::const_iterator itNode = graphNodes.cbegin();
    while(itNode != graphNodes.cend())
    {
        file << "node" << itNode->second << " [label=\"" << itNode->first << "\"];" << endl;
        ++itNode;
    }

    //Edges declaration

    map<pair<string, string>, unsigned>::const_iterator itEdge = catalog.graphEdges.cbegin();
    while(itEdge != catalog.graphEdges.cend())
    {
        //file << "node" << graphNodes[itEdge->first.first] << " -> node" << graphNodes[itEdge->first.first] << " [label=\"" << itEdge->second << "\"];" << endl;
        file << "node" << graphNodes[itEdge->first.first] << " -> node" << graphNodes[itEdge->first.second] << " [label=\"" << itEdge->second << "\"];" << endl;
        ++itEdge;
    }

    file << "}";
}//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


GraphGenerator::GraphGenerator ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphGenerator>" << endl;
#endif
} //----- Fin de GraphGenerator


GraphGenerator::~GraphGenerator ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphGenerator>" << endl;
#endif
} //----- Fin de ~GraphGenerator


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void GraphGenerator::GetNodes(Catalog & catalog, map<string, unsigned> & graphNodes)
{

    map<pair<string, string>, unsigned>::const_iterator itEdge = catalog.graphEdges.cbegin();
    unsigned i(0);
    while(itEdge != catalog.graphEdges.cend())
    {
        if(graphNodes.count(itEdge->first.first) == 0)
        {
            graphNodes.insert(make_pair(itEdge->first.first, i));
            ++i;
        }
        if(graphNodes.count(itEdge->first.second) == 0)
        {
            graphNodes.insert(make_pair(itEdge->first.second, i));
            ++i;
        }
        ++itEdge;
    }
} //----- Fin de GetNodes
