//
//  operation.hpp
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/12/16.
//  Copyright © 2016 wildan. All rights reserved.
//
// the idea behind this class, i collect all the operations that will be used for other class,
// especially molecule class such that i make a magic box for vector operation.

#ifndef operation_hpp
#define operation_hpp

#include <stdio.h>
#include <iostream>
#include "vector.hpp"

class operation{
    //all methods are in public data member and using static data member due to this operation will be used for any other class without defining the object
public :
    static vector vectAdd(vector a, vector b); //method for 2 vectors addition
    static vector vectSub(vector a, vector b); //method for 2 vectors submission
    static vector vectDot(vector a, vector b); //method for 2 vectors multipilication
    static double vectSquare(vector a); //method for squaring the a vector
    static vector vectCube(vector a, vector b, vector c); // method for 3 vectors multiplication
    static vector vectDiv(vector a, vector b); //method for 2 vectors division
    static vector vectScale(vector a, double b);//method for scaling a vector
};

#endif /* operation_hpp */
