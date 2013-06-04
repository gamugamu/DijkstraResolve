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

#pragma mark -------------------------- public ---------------------------------
#pragma mark -------------------------------------------------------------------

void testFalseNode();
Dijkstra::Dijkstra(){
    m_impl = new DijkstraImpl();
    testFalseNode();
}

Dijkstra::~Dijkstra(){
    delete m_impl;
}

DijkstraImpl::DijkstraImpl(){
  
}

#pragma mark -------------------------- private --------------------------------
#pragma mark -------------------------------------------------------------------

void testFalseNode(){
    list<D_Node> list(3);
    
    D_Node* node_0 = new D_Node(0);
    D_Node* node_1 = new D_Node(1);
    D_Node* node_2 = new D_Node(2);
    
    node_0->addNeighboor(node_1, 1);
    node_1->addNeighboor(node_2, 1);

    node_0->description();
    node_1->description();
    node_2->description();
}