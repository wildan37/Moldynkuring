//
//  main.cpp
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/14/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include "vector.hpp"
#include "operation.hpp"
#include "molecule.hpp"
#include "mdfunctions.hpp"
int main(int argc, char **argv){
    
    
    int n_atom = 10, iteration = 100;
    double density = 0.8, time_step = 0.02;
    
    molecule *atom;
    atom = new molecule[n_atom*n_atom];
    init_pos(atom, density, n_atom);
   
    reset(atom, n_atom);
    
    //velocity initialization based on pseudorandom number generator
    for (int i = 0; i<n_atom*n_atom; i++){
        pseudorand(&atom[i]);
    }
    
    for (int iter = 0 ; iter < iteration ; iter++){
    
        leapfrog(atom, time_step, density, n_atom, 0);
       
        //periodic boundary conditions
        wrapping_all(atom,density, n_atom);
    
        pot_force(atom, density, n_atom);
        leapfrog(atom, time_step, density, n_atom, 1);
        
        double totalEn = totalEnergyCalc(atom, n_atom);
   	std::cout<< totalEn<<"\n";    
    }
        
   
    
    delete atom ;
    
    return 0;
}
