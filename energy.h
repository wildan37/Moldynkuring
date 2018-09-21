//
//  energy.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/31/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#ifndef energy_h
#define energy_h

#include <stdio.h>
#include <math.h>
#include <iostream>
#include "molecule.hpp"

double totalEnergyCalc(molecule *atom, int n_atom){
    double tempEneTotal = 0, velMag2;
    for(int i = 0; i < n_atom * n_atom; i++){
        velMag2 = pow(atom[i].getXVelocity(),2) + pow(atom[i].getYVelocity(),2);
        atom[i].setKinetic(0.5*velMag2); // EK = 1/2 * mass * vel^2
        tempEneTotal += (atom[i].getKinetic() + atom[i].getPotential());
    }
       //cout <<"Total Energy is " << tempEneTotal << endl;
    return tempEneTotal;
    }


#endif /* energy_h */
