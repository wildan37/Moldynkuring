//
//  init_pos.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/18/16.
//  Copyright © 2016 wildan. All rights reserved.
//
// In this function, I define the initial position for each atom in order to get a perfect 2D lattice(square lattice).
// atoms position are centered to the origin with
#ifndef init_pos_h
#define init_pos_h


#include <stdio.h>
#include <math.h>
#include "vector.hpp"
#include "operation.hpp"
#include "molecule.hpp"


void init_pos(molecule *atom, double density, int n_atom){
    int i=0, j=0, n=0;
    // here gap vector is distance that should go between two atom
    // pos is the position where atom will occupy in cartesian coordinate
    // region is length of square box
    // initUnitCell is total nxn unit cell in the square box
    // all of these three are vectors such as having the x and y direction
    vector gap, pos, region, initUnitCell;
    region.setVector(1./sqrt(density) * n_atom, 1./sqrt(density) * n_atom);
    initUnitCell.setVector_int(n_atom, n_atom);
    gap.setVector(region.getXVector()/initUnitCell.getXVector_int(), region.getYVector()/initUnitCell.getYVector_int());
    
    //positioning process of the atoms(initial position)
    while (i < initUnitCell.getXVector_int()){
        while (j < initUnitCell.getYVector_int()){
            pos.setVector((double)i + 0.5, (double)j + 0.5);
            
            // atom_position = (position * gap) + (-0.5 * region)
            atom[n].setPositionVect(operation::vectAdd(operation::vectDot(pos, gap),operation::vectScale(region, -0.5)));
            
            n += 1;
            j += 1;
        }
        i += 1;
        j = 0;
    }
};

#endif /* init_pos_h */
