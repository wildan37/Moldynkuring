#include "mdfunctions.hpp"

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
}

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

//  pseudorand.h
//  This pseudorandom generator number based on LCG(Linear Congruential Generator), Monte Carlo method 
//  by D.H. Lehmer(1948)
//  the equation for deriving this number is based on:
//  s[i+1] = ( a * s[i] + c ) % m
//  where a = well chosen multiplier, m = equal to/ slightly smaller than the largest integer that can be repsented in one computer word, and c = is constant
//  MolDyn

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
            deltaR = operation::vectSub(atom[i].getPosition(), atom[j].getPosition());
            
            
            // periodic boundary condition implementation
            wrapping(deltaR, density, n_atom);
            
            // calculate the magnitude of squared distance(r^2) between two atom vectors.
            mag_deltaRR = operation::vectSquare(deltaR);
        
            // distance between two atoms(magnitude) should be less than cut-off distance(rcut); to avoid discontinuity.
            if (mag_deltaRR < rrCutOff){
               
                // this is somewhat make easier
                mag_deltaRRi = 1./mag_deltaRR;
                mag_deltaRR3i = mag_deltaRRi * mag_deltaRRi * mag_deltaRRi;
    
                // calculate potential(lennard jones 6-12) every atom
                potVal = 4. * mag_deltaRR3i * (mag_deltaRR3i - 1.) + 1. ;
                
                atom[i].setPotential(atom[i].getPotential() + potVal);
                
                // calculate force for each atom
                forceVal = 48. * mag_deltaRR3i * (mag_deltaRR3i - 0.5) * mag_deltaRRi;
                tempForce.setVector(forceVal * deltaR.getXVector(), forceVal * deltaR.getYVector());
                
                
                // get acceleration from the force, meanwhile the newton's 3rd law happens, f(ji) = -f(ij).
                
                atom[i].setAccelerationVect(operation::vectAdd(atom[i].getAcceleration(), tempForce)); //vector addition operation
                atom[j].setAccelerationVect(operation::vectSub(atom[j].getAcceleration(), tempForce)); //vector substraction operation
              
              }
        }
    }

}


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



double totalEnergyCalc(molecule *atom, int n_atom){
    double tempEneTotal = 0, velMag2;
    for(int i = 0; i < n_atom * n_atom; i++){
        velMag2 = pow(atom[i].getXVelocity(),2) + pow(atom[i].getYVelocity(),2);
        atom[i].setKinetic(0.5*velMag2); // EK = 1/2 * mass * vel^2
        tempEneTotal += (atom[i].getKinetic() + atom[i].getPotential());
    }
       
    return tempEneTotal;
    }

