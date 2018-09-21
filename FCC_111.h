//
//  FCC_111.h
//  beta version, need to be fixed
//  MolDyn
//
//  Created by Wildan Abdussalam on 2/16/17.
//  Copyright © 2017 wildan. All rights reserved.
//

#ifndef FCC_111_h
#define FCC_111_h

#include <stdio.h>
#include <math.h>
#include "vector.hpp"
#include "operation.hpp"
#include "molecule.hpp"

void FCC_111(molecule *atom, double density, int n_atom){
    int i=0, j=0, n=0;
    
    vector gap, pos, region, initUnitCell;
 
    region.setVector(0.5*sqrt(2.)*1./sqrt(density) * n_atom, 0.25*sqrt(6.)*1./sqrt(density) * n_atom );
    initUnitCell.setVector_int(n_atom, n_atom);
    region.printVector();
    gap.setVector(region.getXVector()/initUnitCell.getXVector_int(), region.getYVector()/initUnitCell.getYVector_int());

    //positioning process of the atoms(initial position)
    while (i < initUnitCell.getXVector_int()){
        while (j < initUnitCell.getYVector_int()){
            if (j%2==0){
                pos.setVector((double)i + 0.5, (double)j + 0.5);
            
                // atom_position = (position * gap) + (-0.5 * region)
                atom[n].setPositionVect(operation::vectAdd(operation::vectDot(pos, gap),operation::vectScale(region, -0.5)));
            
                n += 1;
                j += 1;
            }
        else{
            pos.setVector((double)i + 0.5, (double)j + 0.5);
            
            // atom_position = (position * gap) + (-0.5 * region)
            atom[n].setPositionVect(operation::vectAdd(operation::vectDot(pos, gap),operation::vectScale(region, -0.5)));
            atom[n].setPosition(atom[n].getXPosition() + 0.25*sqrt(2), atom[n].getYPosition());
            n += 1;
            j += 1;
            
        }
        }
        i += 1;
        j = 0;
    }
}

#endif /* FCC_111_h */
