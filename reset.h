//
//  init_vel.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/19/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#ifndef init_vel_h
#define init_vel_h
#include <stdio.h>
#include <math.h>
#include "vector.hpp"
#include "molecule.hpp"
#include "normal_dist.h"


void init_acc(molecule *atom, int n_atom){
    int i = 0;
   
    //acceleration initialization
    while (i < n_atom * n_atom){
        atom[i].setAcceleration(0.,0.);
        i++;
    }
}

void init_pot(molecule *atom, int n_atom){
    int i = 0;
    while (i < n_atom * n_atom){
        atom[i].setPotential(0.);
        i++;
    }
}
void init_kin(molecule *atom, int n_atom){
    int i = 0;
    while (i < n_atom * n_atom){
        atom[i].setKinetic(0.);
        i++;
    }
}

void reset(molecule *atom, int n_atom){
    init_acc(atom, n_atom);
    init_pot(atom, n_atom);
    init_kin(atom, n_atom);
}
#endif /* init_vel_h */
