//
//  D_Node.cpp
//  TestinC++
//
//  Created by Abadie, Loïc on 31/05/13.
//  Copyright (c) 2013 Abadie, Loïc. All rights reserved.
//

#include "D_Node.h"

#pragma mark -------------------------- public ---------------------------------
#pragma mark -------------------------------------------------------------------

void D_Node::addNeighboor(D_Node* node, uint distance){
    this->addNode(node, distance);
    node->addNode(this, distance);
}

std::vector<D_Node*>::iterator D_Node::neighboors(){
    return neighboor.begin();
}

void D_Node::description(){
    printf("--- node %u [%u]----\n", id, weight);
   
    for(auto    it  = neighboorDistance.begin();
                it != neighboorDistance.end();
                ++it){
        printf("id: %u distance: %u\n", it->first->id , it->second);
    }
}

#pragma mark - alloc / dealloc

D_Node::D_Node(){

}

D_Node::~D_Node(){

}

#pragma mark -------------------------- private --------------------------------
#pragma mark -------------------------------------------------------------------

void D_Node::addNode(D_Node* node, uint distance){
    neighboor.push_back(node);
    neighboorDistance.emplace(node, distance);
}