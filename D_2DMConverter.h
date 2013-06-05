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

class D_2MConverter{
    public:
    /*-------------------------------------------------------
                    constructeur / Destructeur
     -------------------------------------------------------*/
    D_2MConverter();
    ~D_2MConverter();
    
    /*-------------------------------------------------------
                            method
     -------------------------------------------------------*/
    std::vector<D_Node*> make2DMatriceToDijkstra(int* matrice2D, int n, int m);
    
private:
    std::vector<D_Node*> nodes;
};

#endif /* defined(__TestinC____D_2DMConverter__) */
