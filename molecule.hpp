//
//  molecule.hpp
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/20/16.
//  Copyright © 2016 wildan. All rights reserved.
//
// Molecule Class
// Idea behind this class is to collect all the objects called atoms that have all same properties.
// later on an object called atom having position, velocity, and acceleration with the vector data type.
// and the properties governed from those 3 vectors(position, velocity, acceleration) are potential and kinetic that will have double data type.

#ifndef molecule_hpp
#define molecule_hpp

#include <stdio.h>
#include <iostream>
#include "vector.hpp"


class molecule {
private:
    // I put vector pos, vel, acc, double potential, kinetic in private member due to the safety of the each member
    
    vector pos; // an atom will have position in x and y direction
    vector vel; // an atom will have velocity in x and y direction
    vector acc; // an atom will have acceleration in x and y direction
    double potential; // due to the interaction with other this value will be owned by an atom
    double kinetic; //due to the movement of an atom inside the system an atom will have a velocity

public:

    // Below I have Set and Get method for defining Position.
    void setPositionVect(vector a); // here I can also define position that will take vector as an input
    void setPosition(double a, double b);
    void setXPosition(double a);
    void setYPosition(double a);
    vector getPosition();
    double getXPosition();
    double getYPosition();
    
    // Below I have Set and Get method for defining Velocity.
    void setVelocityVect(vector a); // here I can also define velocity  that will take vector as an input
    void setVelocity(double a, double b);
    void setXVelocity(double a);
    void setYVelocity(double a);
    vector getVelocity();
    double getXVelocity();
    double getYVelocity();
    
    // Below I have Set and Get method for defining Acceleration.
    void setAccelerationVect(vector a); // here I can also define acceleration that will take vector as an input
    void setAcceleration(double a, double b);
    void setXAcceleration(double a);
    void setYAcceleration(double a);
    vector getAcceleration();
    double getXAcceleration();
    double getYAcceleration();
    
    //Set and get for atom's potential energy
    void setPotential(double a);
    double getPotential();
    
    //Set and get for atom's kinetic energy
    void setKinetic(double a);
    double getKinetic();
    
    // Later on, these methods for helping to identify/observe the dynamic of atoms by printing atom position, velocity, and acceleration.
    void printPosition();
    void printVelocity();
    void printAcceleration();
    

    
};

#endif /* molecule_hpp */
