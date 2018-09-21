#ifndef mdFunctions_h
#define mdFunctions_h

#include <stdio.h>
#include <math.h>
#include "vector.hpp"
#include "operation.hpp"
#include "molecule.hpp"

//for pseudo random parameter
#define PI 3.14159265359
#define IADD 453806245
#define IMUL 314159269
#define MASK 2147483647
#define SCALE 0.4656612873e-9


void init_pos(molecule *atom, double density, int n_atom); 
void init_acc(molecule *atom, int n_atom);
void init_pot(molecule *atom, int n_atom);
void init_kin(molecule *atom, int n_atom);
void reset(molecule *atom, int n_atom);
double randDouble();
void pseudorand(molecule *atom);
void wrapping(vector r, double density, int n_atom);
void wrapping_all(molecule *atom, double density, int n_atom);
void pot_force(molecule *atom, double density, int n_atom);
void leapfrog(molecule *atom, double time_step, double density, int n_atom, int state);
double totalEnergyCalc(molecule *atom, int n_atom);



#endif /* mdFunctions_h */
