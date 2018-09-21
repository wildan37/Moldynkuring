//
//  molecule.cpp
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/20/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#include "molecule.hpp"


using namespace std;

//this method for assigned vector a to the position
void molecule::setPositionVect(vector a){
    pos = a;
}

// since pos,vel, and acceleration are also vector class, I can use the Set method owned by vector class.
// Thus, I can assign two double values to pos, vel, acceleration member

void molecule::setPosition(double a, double b){
    pos.setXVector(a);
    pos.setYVector(b);
}
void molecule::setXPosition(double a){
    pos.setXVector(a);
}
void molecule::setYPosition(double a){
    pos.setYVector(a);
}

void molecule::setVelocityVect(vector a){
    vel = a;
}

void molecule::setVelocity(double a, double b){
    vel.setXVector(a);
    vel.setYVector(b);
}
void molecule::setXVelocity(double a){
    vel.setXVector(a);
}
void molecule::setYVelocity(double a){
    vel.setYVector(a);
}

void molecule::setAccelerationVect(vector a){
    acc = a;
}
void molecule::setAcceleration(double a, double b){
    acc.setXVector(a);
    acc.setYVector(b);
}
void molecule::setXAcceleration(double a){
    acc.setXVector(a);
}
void molecule::setYAcceleration(double a){
    acc.setYVector(a);
}

// since pos,vel, and acceleration are also vector class, I can use the Get method owned by vector class.
// Thus, I can get values from pos, vel, acceleration member

double molecule::getXPosition(){
    return pos.getXVector();
}
double molecule::getYPosition(){
    return pos.getYVector();
}

vector molecule::getPosition(){
    return pos;
}
double molecule::getXVelocity(){
    return vel.getXVector();
}
double molecule::getYVelocity(){
    return vel.getYVector();
}
vector molecule::getVelocity(){
    return vel;
}
double molecule::getXAcceleration(){
    return acc.getXVector();
}
double molecule::getYAcceleration(){
    return acc.getYVector();
}
vector molecule::getAcceleration(){
    return acc;
}


// method for set potential energy of atom

void molecule::setPotential(double a){
   potential = a;
}
// method for get the potential of atom
double molecule::getPotential(){
    return (potential);
}

//method for set kinetic energy of atom

void molecule::setKinetic(double a){
    kinetic = a;
}

// method for get the value of kinetic energy of atom
double molecule::getKinetic(){
    return (kinetic);
}

// Method : Print
void molecule::printPosition(){
    cout <<"pos_x coordinate is "<<pos.getXVector()<<" and pos_y coordinate is "<<pos.getYVector()<<endl;
}
void molecule::printVelocity(){
    cout <<"vel_x coordinate is "<<vel.getXVector()<<" and vel_y coordinate is "<<vel.getYVector()<<endl;
}
void molecule::printAcceleration(){
    cout <<"acc_x coordinate is "<<acc.getXVector()<<" and acc_y coordinate is "<<acc.getYVector()<<endl;
}







