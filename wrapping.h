//
//  wrapping.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/27/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#ifndef wrapping_h
#define wrapping_h

#include <stdio.h>
#include <iostream>
#include "molecule.hpp"
#include "vector.hpp"
#include "operation.hpp"


void wrapping(vector r, double density, int n_atom){
    //periodic boundary condition wrapping

    vector region;
    //region.setVector(1./sqrt(density) * n_atom, 1./sqrt(density) * n_atom);
    region.setVector(1./sqrt(density) * n_atom *0.5*sqrt(2), 1./sqrt(density) * n_atom*0.25*sqrt(0.25));
    if (r.getXVector() >= 0.5 * region.getXVector())
    {
        r.setXVector(r.getXVector() - region.getXVector());
    }
    else if (r.getXVector() < 0.5 * region.getXVector())
    {
        r.setXVector(r.getXVector() + region.getXVector());
    }
    if (r.getYVector() >= 0.5 * region.getYVector())
    {
        r.setYVector(r.getYVector() - region.getYVector());
    }
    else if (r.getYVector() < 0.5 * region.getYVector())
    {
        r.setYVector(r.getYVector() + region.getYVector());
    }
    
}
void wrapping_all(molecule *atom, double density, int n_atom){
    for (int i = 0; i< n_atom * n_atom; i++) wrapping(atom[i].getPosition(), density, n_atom);
}


#endif /* wrapping_h */
