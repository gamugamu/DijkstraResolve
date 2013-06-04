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

class DijkstraImpl{
public:
    DijkstraImpl();
private:
};

using namespace std;

// helper
// a supprimer
static vector<D_Node*> listNode;
void testFalseNode();

// l'algorythme de Dijkstra.
void findPath(vector<D_Node*> allNodes);

// permet de classer les nodes par leur distances.
bool sortNodeByDistance(D_Node* node_a, D_Node* node_b);

// affiche la description de toutes les nodes.
void printAllNodes(vector<D_Node*> &listNodes);

#pragma mark -------------------------- public ---------------------------------
#pragma mark -------------------------------------------------------------------

#pragma mark - public

void Dijkstra::pathFind(vector<D_Node*> feeds){
    findPath(feeds);
}

#pragma mark - alloc / dealloc

Dijkstra::Dijkstra(){
    m_impl = new DijkstraImpl();
    testFalseNode();
}


Dijkstra::~Dijkstra(){
    delete m_impl;
}

DijkstraImpl::DijkstraImpl(){
  
}

void findPath(vector<D_Node*> allNodes){
    // par convention, la première node de la list est le départ.
    D_Node* startNode   = allNodes[0];
    
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
        
        auto n = unvisited->neighboors();

        // on parcours les voisins de la node , et on réfraichit les distances.
        for(auto it = n.begin(); it != n.end(); it++){
            D_Node* node = *it;
            
            // note, dans l'algorythme de Diskstra, on ne réupdate pas les
            // nodes visitées.
            if(!node->didVisit)
                node->weight = unvisited->weight + node->distanceForNode(unvisited);
        }
        
        // on enlève unvisited de la list
        unvisited->didVisit = true;
        notVisited.erase(notVisited.begin());
    }

    printAllNodes(allNodes);
}

#pragma mark -------------------------- private --------------------------------
#pragma mark -------------------------------------------------------------------

bool sortNodeByDistance(D_Node* node_a, D_Node* node_b){
    return node_a->weight < node_b->weight;
}

void testFalseNode(){
    D_Node* node_s = new D_Node(0);
    D_Node* node_1 = new D_Node(1);
    D_Node* node_2 = new D_Node(2);
    D_Node* node_3 = new D_Node(3);
    D_Node* node_4 = new D_Node(4);
    D_Node* node_5 = new D_Node(5);
    D_Node* node_6 = new D_Node(6);

    node_s->addNeighboor(node_1, 2);
    node_1->addNeighboor(node_2, 1);
    node_2->addNeighboor(node_3, 1);
    node_2->addNeighboor(node_4, 1);
    node_2->addNeighboor(node_5, 1);
    node_5->addNeighboor(node_6, 2);
    
    listNode.push_back(node_s);
    listNode.push_back(node_1);
    listNode.push_back(node_2);
    listNode.push_back(node_3);
    listNode.push_back(node_4);
    listNode.push_back(node_5);
    listNode.push_back(node_6);
}

void printAllNodes(vector<D_Node*> &listNodes){
    for(D_Node* node : listNodes)
        node->description();
}