//
//  leapfrog.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/27/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#ifndef leapfrog_h
#define leapfrog_h

#include <stdio.h>
#include "molecule.hpp"
#include "vector.hpp"
#include "wrapping.h"
#include "operation.hpp"

void leapfrog(molecule *atom, double time_step, double density, int n_atom, int state){

    if (state == 0){
        for (int i = 0 ; i < n_atom * n_atom ; i++){
        atom[i].setVelocityVect(operation::vectAdd(atom[i].getVelocity(), operation::vectScale(atom[i].getAcceleration(), time_step/2.)));
        atom[i].setPositionVect(operation::vectAdd(atom[i].getPosition(), operation::vectScale(atom[i].getVelocity(), time_step)));

        }
    }
    else if(state == 1){
        for (int i = 0 ; i < n_atom * n_atom ; i++)
        {
        atom[i].setVelocityVect(operation::vectAdd(atom[i].getVelocity(), operation::vectScale(atom[i].getAcceleration(),time_step/2.)));
        }
                                }
}


#endif /* leapfrog_h */
