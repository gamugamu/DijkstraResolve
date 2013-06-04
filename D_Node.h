//
//  D_Node.h
//  TestinC++
//
//  Created by Abadie, Loïc on 31/05/13.
//  Copyright (c) 2013 Abadie, Loïc. All rights reserved.
//

/*******************************************************************
 * NOM :            int KB_GetLine(pKbdBuf, MaxChars)
 *
 * DESCRIPTION :     Input line of text from keyboard
 *
 * Note: 
 *
 */

#ifndef __TestinC____D_Node__
#define __TestinC____D_Node__

#include <iostream>
#include <map>
#include <vector>

const int INF = 1000000;

class D_Node{
public:
    /*-------------------------------------------------------
                    constructeur / Destructeur
     -------------------------------------------------------*/
    D_Node();
    ~D_Node();

    // constructeur avec id pour la node.
    D_Node(uint idNode) : id(idNode){};

    /*-------------------------------------------------------
                            method
     -------------------------------------------------------*/
    
    // rajoute un voisin:
    // @params node: la node à rajouter
    // @params distance: la distance relative entre ces 2 nodes.
    void addNeighboor(D_Node* node, uint distance);
    
    // @retourne un iterator contenant tout les voisins de la node.
    std::vector<D_Node*>::iterator neighboors();
    
    // @retourne la distance de la node relative.
    // @note: si la node est inconnue, retourne 0.
    int distanceForNode(D_Node& node);
    
    void description();
    
    /*-------------------------------------------------------
                          propriétés:
     -------------------------------------------------------*/
    // l'id de la node.
    uint id;
    
    // la distance la plus courte relative à la node de départ.
    uint weight = INF;
    
    // permet à l'algo de Djikstra de ssavoir si cette node a déjà été
    // visitée.
    bool didVisit;
    
private:
    std::map<D_Node*, int> neighboorDistance;
    std::vector<D_Node*> neighboor;
    
    void addNode(D_Node* node, uint distance);
};

#endif /* defined(__TestinC____D_Node__) */
