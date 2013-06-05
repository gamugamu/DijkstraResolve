//
//  D_2DMConverter.h
//  TestinC++
//
//  Created by Abadie, Loïc on 04/06/13.
//  Copyright (c) 2013 Abadie, Loïc. All rights reserved.
//

#ifndef __TestinC____D_2DMConverter__
#define __TestinC____D_2DMConverter__

#include <iostream>
#include <vector>

// Dijkstra Matrice 2D converter
class D_Node;

std::vector<D_Node*> create2DMatriceToDijkstra(int* matrice2D, int n, int m);
void release2DMatriceToDijkstra(std::vector<D_Node*> nodes);

#endif /* defined(__TestinC____D_2DMConverter__) */
