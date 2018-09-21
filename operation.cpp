//
//  operation.cpp
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/12/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#include "operation.hpp"
#include "vector.hpp"
#include <stdio.h>


//this method defines the vector addition, I use the Set method coming from vector class
vector operation::vectAdd(vector a, vector b){
    a.setVector(a.getXVector() + b.getXVector(), a.getYVector() + b.getYVector());
    return (a);
}

//this method defines the vector submission, I use the Set method coming from vector class
vector operation::vectSub(vector a, vector b){
    a.setVector(a.getXVector() - b.getXVector(), a.getYVector() - b.getYVector());
    return (a);
}

//this method defines the vector multiplication(dot), I use the Set method coming from vector class
 vector operation::vectDot(vector a, vector b){
     a.setVector(a.getXVector() * b.getXVector(), a.getYVector() * b.getYVector());
     return (a);
 };

//this method defines the vector division, I use the Set method coming from vector class
vector operation::vectDiv(vector a, vector b){
    a.setVector(a.getXVector() / b.getXVector(), a.getYVector() / b.getYVector());
    return (a);
}

double operation::vectSquare(vector a){
    return(a.getXVector() * a.getXVector() + a.getYVector() * a.getYVector());
}
//this method defines the vector cube, I use the Set method coming from vector class
vector operation::vectCube(vector a, vector b, vector c){
    a.setVector(a.getXVector() * b.getXVector() * c.getXVector(), a.getYVector() * b.getYVector() * c.getYVector());
    return (a);
}
//this method defines the scaling vector, I use the Set method coming from vector class
vector operation::vectScale(vector a, double b){
    a.setVector(a.getXVector() * b, a.getYVector() * b);
    return (a);
}

