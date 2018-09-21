//
//  vector.hpp
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/12/16.
//  Copyright © 2016 wildan. All rights reserved.
//
// Here, the class for declaring the structure of vector, which every vector has two value in x and y direction
// Private member for the data of x and y having double and integer value as the data type.
// Public member is specialized for methods, Set and Get value to the vector and also printing the value of a vector.

#ifndef vector_hpp
#define vector_hpp


#include <stdio.h>

class vector{
private :
    double x;
    double y;
    int x_int;
    int y_int;
    
public :
    void setVector(double a, double b);
    void setVector_int(int a, int b); // Reason I apply the integer vector is to define the simulation box that only take integet value.
    void setXVector(double a);
    void setYVector(double a);
    double getXVector();
    double getYVector();
    int getXVector_int();
    int getYVector_int();
    void printVector();
};

#endif /* vector_hpp */
