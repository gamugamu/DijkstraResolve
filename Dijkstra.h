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

class Dijkstra{
public:
    Dijkstra();
    ~Dijkstra();
    
    void pathFind(std::vector<D_Node*> feeds);

private:
    DijkstraImpl* m_impl;
};

#endif /* defined(__TestinC____PathFinder__) */
