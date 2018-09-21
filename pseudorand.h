//
//  pseudorand.h
//  This pseudorandom generator number based on LCG(Linear Congruential Generator), Monte Carlo method 
//  by D.H. Lehmer(1948)
//  the equation for deriving this number is based on:
//  s[i+1] = ( a * s[i] + c ) % m
//  where a = well chosen multiplier, m = equal to/ slightly smaller than the largest integer that can be repsented in one computer word, and c = is constant
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/23/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#ifndef pseudorand_h
#define pseudorand_h
#include <stdio.h>
#include <math.h>
#include "vector.hpp"
#include "molecule.hpp"


#define PI 3.14159265359
#define IADD 453806245
#define IMUL 314159269
#define MASK 2147483647
#define SCALE 0.4656612873e-9

int randSeedP = 17;
double randDouble(){
    randSeedP = (randSeedP * IMUL + IADD) & MASK;
    return (randSeedP * SCALE);
}

void pseudorand(molecule *atom){
    double s;
    s = 2. * PI * randDouble();
    atom->setVelocity(cos(s), sin(s));
}

#endif /* pseudorand_h */
