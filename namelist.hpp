//
//  namelist.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 2/24/17.
//  Copyright © 2017 wildan. All rights reserved.
//

#ifndef namelist_hpp
#define namelist_hpp



class VarList_double{
public:
    VarList_double(char *x);
    int vValue;
    char *vName;
    void *vPtr;
    int vLen, vStatus;
};

class VarList_int{
public:
    VarList_int(char *x);
    double vValue;
    char *vName;
    void *vPtr;
    int vLen, vStatur;
    
};




#endif /* namelist_h */
