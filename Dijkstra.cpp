//
//  PathFinder.cpp
//  TestinC++
//
//  Created by Abadie, Loïc on 29/05/13.
//  Copyright (c) 2013 Abadie, Loïc. All rights reserved.
//

#include "Dijkstra.h"
#include "D_Node.h"
#include <list>

using namespace std;

// helper

// l'algorythme de Dijkstra.
void findPath(vector<D_Node*>& allNodes, D_Node* startNode);

// permet de classer les nodes par leur distances.
bool sortNodeByDistance(D_Node* node_a, D_Node* node_b);


#pragma mark -------------------------- public ---------------------------------
#pragma mark -------------------------------------------------------------------

#pragma mark - public

void Dijkstra::pathFind(vector<D_Node*>& feeds, D_Node* startNode){
    findPath(feeds, startNode);
}

#pragma mark - alloc / dealloc

void findPath(vector<D_Node*>& allNodes, D_Node* startNode){
    for(D_Node* node : allNodes){
        node->weight    = INF;
        node->didVisit  = false;
    }
    // on la marque comme visitée.
    startNode->weight   = 0;
    startNode->didVisit = true;
    
    // et on parcours toute la liste des nodes non visitée, tant qu'il
    // en reste.
    vector<D_Node*> notVisited = allNodes;
    
    while (!notVisited.empty()) {
        // on retrouve la node la plus proche.
        sort(notVisited.begin(), notVisited.end(), sortNodeByDistance);
      
        D_Node* unvisited = notVisited[0];

        // on exclue toutes les nodes qui ne veulent pas être visitée.
        if(!unvisited->cantVisit){
            auto n = unvisited->neighboors();
            
            // on parcours les voisins de la node , et on réfraichit les distances.
            for(auto it = n.begin(); it != n.end(); it++){
                D_Node* node = *it;
                
                // note, dans l'algorythme de Diskstra, on ne réupdate pas les
                // nodes visitées, ni celle qui ne veulent pas être visité.
                if(!node->cantVisit && !node->didVisit){
                    int weight = unvisited->weight + unvisited->distanceForNode(node);
                    
                    if(weight < node->weight)
                        node->weight = weight;
                }
            }
            // la node a été visitée.
            unvisited->didVisit = true;
        }
        // on enlève unvisited de la list
        notVisited.erase(notVisited.begin());
    }

    sort(allNodes.begin(), allNodes.end(), sortNodeByDistance);
}

#pragma mark -------------------------- private --------------------------------
#pragma mark -------------------------------------------------------------------

bool sortNodeByDistance(D_Node* node_a, D_Node* node_b){
    return node_a->weight < node_b->weight;
}

void printAllNodes(vector<D_Node*> &listNodes){
    for(D_Node* node : *&listNodes)
        node->description();
}