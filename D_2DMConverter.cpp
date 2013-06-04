//
//  D_2DMConverter.cpp
//  TestinC++
//
//  Created by Abadie, Loïc on 04/06/13.
//  Copyright (c) 2013 Abadie, Loïc. All rights reserved.
//

#include "D_2DMConverter.h"
#include "D_Node.h"

std::vector<D_Node*> convert2DMatriceToDijkstra(int* matrice2D, int n, int m){
    std::vector<D_Node*> nodes;
    
    // création des nodes avec leurs id respectifs.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            nodes.push_back(new D_Node((n * i) + j));
    
    // rajout des voisins entre les nodes
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int idx             = (n * i) + j ;
            D_Node* currentNode = nodes[idx];
            
            // tout sauf le premier rang.
            if(i){
                printf("↑");
                int u = idx - n;
                currentNode->addNeighboor(nodes[u], matrice2D[u]);
            }
            // tout sauf le dernier rang.
            if(i != n - 1){
                printf("↓");
                int d = idx + n;
                currentNode->addNeighboor(nodes[d], matrice2D[d]);
            }
            // tout sauf la première colonne.
            if(j){
                printf("←");
                int l = idx - 1;
                currentNode->addNeighboor(nodes[l], matrice2D[l]);

            }
            // tout sauf la dernière colonne.
            if(j != m - 1){
                printf("→");
                int r = idx + 1;
                currentNode->addNeighboor(nodes[r], matrice2D[r]);
            }
            
            printf("\t\t[%i %i] %u [%u]\n", i, j, matrice2D[(n * i) + j], (n * i) + j );
            currentNode->description();
        }
    }
    
    return std::vector<D_Node*>(0);
}