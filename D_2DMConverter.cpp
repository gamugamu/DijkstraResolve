//
//  D_2DMConverter.cpp
//  TestinC++
//
//  Created by Abadie, Loïc on 04/06/13.
//  Copyright (c) 2013 Abadie, Loïc. All rights reserved.
//

#include "D_2DMConverter.h"
#include "D_Node.h"
#include <algorithm>

// helper
void release2DMatriceToDijkstra(std::vector<D_Node*>& nodes);

#pragma mark -------------------------- public ---------------------------------
#pragma mark -------------------------------------------------------------------

std::vector<D_Node*> D_2MConverter::make2DMatriceToDijkstra(int* matrice2D, int n, int m){
    // on efface précédemment les nodes qui ont pu être créées.
    release2DMatriceToDijkstra(nodes);

    // création des nodes avec leurs id respectifs.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            nodes.push_back(new D_Node((n * i) + j));
    
    // rajout des voisins entre les nodes
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int idx             = (n * i) + j;
            D_Node* currentNode = nodes[idx];
            
            // tout sauf le premier rang.
            if(i){
                int u = idx - n;
                currentNode->addNeighboor(nodes[u], matrice2D[u], matrice2D[idx]);
            }
            // tout sauf le dernier rang.
            if(i != n - 1){
                int d = idx + n;
                currentNode->addNeighboor(nodes[d], matrice2D[d], matrice2D[idx]);
            }
            // tout sauf la première colonne.
            if(j){
                int l = idx - 1;
                currentNode->addNeighboor(nodes[l], matrice2D[l], matrice2D[idx]);
            }
            // tout sauf la dernière colonne.
            if(j != m - 1){
                int r = idx + 1;
                currentNode->addNeighboor(nodes[r], matrice2D[r], matrice2D[idx]);
            }
        }
    }

    return nodes;
}

#pragma mark - alloc / dealloc

D_2MConverter::D_2MConverter(){

}

D_2MConverter::~D_2MConverter(){
    release2DMatriceToDijkstra(nodes);
}

#pragma mark -------------------------- private --------------------------------
#pragma mark -------------------------------------------------------------------

#pragma mark - memory managment

bool deleteNode(const D_Node* o){
    delete o;
    return true;
}

void release2DMatriceToDijkstra(std::vector<D_Node*>& nodes){
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(), deleteNode),
                nodes.end());
}