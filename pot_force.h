/
//  pot_force.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/24/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#ifndef pot_force_h
#define pot_force_h


#include <stdio.h>
#include <math.h>
#include "molecule.hpp"
#include "vector.hpp"
#include "operation.hpp"
#include "wrapping.h"
#include "reset.h"

void pot_force(molecule *atom, double density, int n_atom){
    int i , j ;
    vector deltaR, tempForce;
    double rCutOff, rrCutOff, mag_deltaRR, mag_deltaRRi, mag_deltaRR3i, potVal, forceVal;
    rCutOff  = pow(2. , 1./6);
    rrCutOff = rCutOff * rCutOff;
//force and potential initialization
    reset(atom, n_atom);
    tempForce.setVector(0., 0.);
    for ( i = 0; i < n_atom * n_atom ; i++){
        for ( j = i+1 ; j < n_atom * n_atom ; j++){
            
            // calculate distance between two molecules (delta R)
            // deltaR = atom[i]_position - atom[j]_position
            deltaR = operation::vectSub(atom[i].getPosition(), atom[j].getPosition());
            
            
            // periodic boundary condition implementation
            wrapping(deltaR, density, n_atom);
            
            // calculate the magnitude of squared distance(r^2) between two atom vectors.
           // mag_deltaRR    = pow(deltaR.getXVector(),2) + pow(deltaR.getYVector(),2);
            mag_deltaRR = operation::vectSquare(deltaR);
        
            // distance between two atoms(magnitude) should be less than cut-off distance(rcut); to avoid discontinuity.
            if (mag_deltaRR < rrCutOff){
               // printf("distance more than cut off");
                // this is somewhat make easier
                mag_deltaRRi = 1./mag_deltaRR;
                mag_deltaRR3i = mag_deltaRRi * mag_deltaRRi * mag_deltaRRi;
    
                // calculate potential(lennard jones 6-12) every atom
                potVal = 4. * mag_deltaRR3i * (mag_deltaRR3i - 1.) + 1. ;
                
                atom[i].setPotential(atom[i].getPotential() + potVal);
                
                // calculate force for each atom
                forceVal = 48. * mag_deltaRR3i * (mag_deltaRR3i - 0.5) * mag_deltaRRi;
                tempForce.setVector(forceVal * deltaR.getXVector(), forceVal * deltaR.getYVector());
                //tempForce = operation::vectScale(deltaR, forceVal);
               // tempForce.printVector();
                
                // get acceleration from the force, meanwhile the newton's 3rd law happens, f(ji) = -f(ij).
                
                atom[i].setAccelerationVect(operation::vectAdd(atom[i].getAcceleration(), tempForce)); //vector addition operation
                atom[j].setAccelerationVect(operation::vectSub(atom[j].getAcceleration(), tempForce)); //vector substraction operation
              
              
                /*  atom[i].setAcceleration(atom[i].getXAcceleration() + tempForce.getXVector(), atom[i].getYAcceleration() + tempForce.getYVector());
                atom[j].setAcceleration(atom[j].getXAcceleration() - tempForce.getXVector(), atom[j].getYAcceleration() - tempForce.getYVector()); */
            }
        }
    }

}


#endif /* pot_force_h */
