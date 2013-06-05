//
//  PathFinder.h
//  TestinC++
//
//  Created by Abadie, Loïc on 29/05/13.
//  Copyright (c) 2013 Abadie, Loïc. All rights reserved.
//

#ifndef __TestinC____PathFinder__
#define __TestinC____PathFinder__

#include <iostream>
#include <vector>
#include "D_2DMConverter.h"

class DijkstraImpl;
class D_Node;

// affiche la description de toutes les nodes.
void printAllNodes(std::vector<D_Node*> &listNodes);

class Dijkstra{
public:
    Dijkstra(){};
    
    // trouve les distances les plus courtes à partir de startNode.
    // @params feeds: la list des nodes, avec leur voisins et les distances
    // respectives.
    // @params startNode: la node de départ.
    void pathFind(std::vector<D_Node*>& feeds, D_Node* startNode);
};

#endif /* defined(__TestinC____PathFinder__) */
