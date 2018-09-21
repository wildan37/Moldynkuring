//
//  normal_dist.h
//  MolDyn
//
//  Created by Wildan Abdussalam on 12/19/16.
//  Copyright © 2016 wildan. All rights reserved.
//

#ifndef normal_dist_h
#define normal_dist_h
#include <random>
#include <iostream>

class normal_dist{
private:
    std::default_random_engine generator;
    std::normal_distribution<double> distribution;
    double min;
    double max;
public:
    normal_dist(double min, double max):
        distribution((min + max) / 2, (max - min) / 6), min(min), max(max)
    {}
    double operator () (){
        while (true) {
            double number = this->distribution(generator);
            if (number >= this->min && number <= this->max)
                return number;
        }
    }
};

#endif /* normal_dist_h */
