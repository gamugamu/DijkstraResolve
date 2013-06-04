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

class DijkstraImpl;

class Dijkstra{
public:
    Dijkstra();
    ~Dijkstra();
private:
    DijkstraImpl* m_impl;
};

#endif /* defined(__TestinC____PathFinder__) */
