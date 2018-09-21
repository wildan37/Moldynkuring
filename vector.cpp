//
//  vector.cpp
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/12/16.
//  Copyright © 2016 wildan. All rights reserved.
//
// Here, I define what is the method in vector class(vector.hpp)
// The get and set method as bridging from private to public data member.

#include "vector.hpp"
#include <iostream>

using namespace std;

// set vector from 2 double(a and b) values. Later on a wil be assigned to x and b will be assigned to y
void vector::setVector(double a, double b){
    x = a;
    y = b;
}
void vector::setVector_int(int a, int b){
    x_int = a;
    y_int = b;
}
void vector::setXVector(double a){
    x = a;
}
void vector::setYVector(double a){
    y = a;
}
// this is method to get the value from private data vector(x and y)
double vector::getXVector(){
    return (x);
}
double vector::getYVector(){
    return (y);
}
int vector::getXVector_int(){
    return (x_int);
}
int vector::getYVector_int(){
    return (y_int);
}
// this is method for printing the vector value.
void vector::printVector(){
    cout <<"X coordinate is "<<x<<" and Y coordinate is "<<y<<endl;}

